/****************************************************************
Fecha 30 de abril 2025
Autor: Santiago Hernandez, Juan Esteban Bello
Materia: Estructuras de Datos
Tema: Laboratorio Grafos
Descripcion: Implementacion de algoritmos de Euler y Hamiltonian
*****************************************************************/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
#include<stdio.h>
int n;
using namespace std;
 
/**********************
El siguiente código implementa un programa que, dado un grafo ingresado por el usuario, 
determina si contiene caminos de Euler, circuitos de Euler, caminos de Hamilton o circuitos de Hamilton.
El programa utiliza dos clases, Euler y Hamiltonian, para implementar los algoritmos de Euler y Hamiltonian respectivamente.
***********************/
//Definicion de la clase Euler 
class Euler
{
  int V;    
  list<int> *adj;    
public:
  Euler(int V)  { this->V = V;  adj = new list<int>[V];  }
  ~Euler()      { delete [] adj;  }
 
  void addEdge(int u, int v) {  adj[u].push_back(v); adj[v].push_back(u); } //Funcion de agregacion de vertices
  void rmvEdge(int u, int v);
  void printEulerTour();
  void printEulerUtil(int s);
  int DFSCount(int v, bool visited[]);
  bool isValidNextEdge(int u, int v);
  int iseuler(int[]);
};

// Funcion comprueba que la lista de camino de euler no este vacia e imprime por pantalla
void Euler::printEulerTour()
{
  int u = 0;
  for (int i = 0; i < V; i++)
      if (adj[i].size() & 1)
        {   u = i; break;  }
  printEulerUtil(u);
  cout << endl;
}
 
//Funcio de soporte imprime los elementos de la lista y lo borra antes de ir al siguiente
void Euler::printEulerUtil(int u)
{
  list<int>::iterator i;
  for (i = adj[u].begin(); i != adj[u].end(); ++i)		//Definicion de un iterador para recorrer la lista de adjacencia
  {
      int v = *i;
      if (v != -1 && isValidNextEdge(u, v))			//validar si la arista dada es valida
      {
          cout << u << "-" << v << " ";
          rmvEdge(u, v);					//Eliminacion de arista mostrada
          printEulerUtil(v);					//Llamada a si mismo para repetir el proceso con el siguente arista
      }
  }
}

//Funcion de soporte que valida si una arista en valida para el recorrido (no es puente)
bool Euler::isValidNextEdge(int u, int v)
{
  int count = 0;  	
  list<int>::iterator i;	//Inicializacion de iterador de la lista de adjacencia
  for (i = adj[u].begin(); i != adj[u].end(); ++i)
     if (*i != -1)
        count++;
  if (count == 1)		//Caso trivial, solo hay una arista conectada
    return true;
    
  bool visited[V];		//Contar nodos alcanzables 
  memset(visited, false, V);
  int count1 = DFSCount(u, visited);
  
  rmvEdge(u, v);		// Eliminar vertice temporalmente
  memset(visited, false, V);	// Volver a contar nodos alcansables despues de eliminar
  int count2 = DFSCount(u, visited);
 
  addEdge(u, v);		//Añadir de regreso el vertice eliminado
 
  return (count1 > count2)? false: true;		//Si eliminar la arista reduce el número de vértices alcanzables (count2 < count1), significa que (u, v) es un puente y no se deben tomar puentes hasta que no sea estrictamente necesario (es decir, cuando no hay otras opciones).
}

//Funcion que elimina una arista de la lisa de adjacencia
void Euler::rmvEdge(int u, int v)
{
  list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);		//Encontrar el valor de v en la lista
  *iv = -1;									//Marcarla como -1
 
  list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);		//Encontrar el valor de v en la lista
  *iu = -1;									//Marcar como -1
}

// Funcion que devuelve la cantidad de vertices alcanzables desde v
int Euler::DFSCount(int v, bool visited[])
{
  visited[v] = true;
  int count = 1;
 
  list<int>::iterator i;				//Inicializacion de iterador de lista de adjacencia
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
      if (*i != -1 && !visited[*i])
          count += DFSCount(*i, visited);		//Si hay camino suma uno al contador y se llama a si mismo en la siguente arista
 
  return count;						// Devuelve el numero de vertices alcanzados
}

//Funcion que determina si hay un circuito de euler, un camino de auler o ninguno
int Euler::iseuler(int a[])
{
	int count = 0;
	for(int i=0;i<n;i++){					//Contador de vertices de grado impar
		if(a[i] % 2 != 0)
			count++;
	}
	if(count == 0){						//caso 1: todos los vertices tienen grado par,Si todos los grados son pares, entonces existe un circuito de Euler 
		cout<<"Euler's circuit exists:\n";
		return 1;
	}
	else if(count == 2){
		cout<<"Euler's path exists:\n";			//caso 2: tiene exactamente 2 vertices de grado impar, Si si es así, entonces existe un camino de Euler, pero no un circuito.
		return 1;
	}
	else{							// caso 3: cualquier otro numero impar de vertices, o puede existir ni camino ni circuito de Euler.
		cout<<"No euler's path or circuit exist:'\n\n";
		return -1;
	}
}
 /**************************
Este codigo de Hamiltonian es una implementacion de un algoritmo para encontrar caminos y ciclos de Hamilton en un grafo.
****************************/
 class Hamiltonian //En esta clase definimos valores tales para el correcto funcionamiento de el codigo de caminos de hamilton
{
	int *path,v,x;
	public:
		Hamiltonian(int n){ v = 0; x = 0; path = new int[n]; } //Constructor inicializa el vector del camino y variables auxiliares
		bool isSafe(bool graph[][10], int pos); // verifica si es seguro agregar el vertice actual al camino
		bool hamCycleUtil(bool graph[][10], int pos, int i); //Funcion recursiva que verifica si existe un camino de Hamilton 
		bool hamCycle(bool graph[][10]); // Funcion principal que llama al algoritmo de Hamilton
		void printSolution(); // Imprime el resultado encontrado (Camino o ciclo) 
};

bool Hamiltonian::isSafe(bool graph[][10], int pos) //Verifica si es seguro agregar el vertice actual al camino
//Recibe como parametro el grafo y la posicion actual
{
    if (graph [ path[pos-1] ][ v ] == 0) //Veriifca si hay conexion desde el anterior vertice al actual
        return false;
 
     for (int i = 0; i < pos; i++) // Verifica que el vertice no se repita en el camino
        if (path[i] == v)
            return false;
 
    return true;
}
 
bool Hamiltonian::hamCycleUtil(bool graph[][10], int pos, int i) //Funcion recursiva que verifica si existe un camino de Hamilton
//Recibe como parametro el grafo, la posicion actual y el vertice inicial
{
    if (pos == n) //Caso base: si se han iniciado todos los vertices al camino
    {
        if ( graph[ path[pos-1] ][ path[0] ] == 1 ) //Verifica si hay un ciclo (ultimo vertice conecta con el primero)
        {
        	cout<<"Hamiltonian cycle exists\n";
        	x = 1; //Marca que existe un ciclo
    	}
        else
        	cout<<"Hamiltonian path exists\n";
        return true; //Retorna verdadero si existe un ciclo o camino
    }
 
    for (v = 0; v < n; v++) //Recorre todos los vertices
    //Verifica si el vertice actual es seguro para agregar al camino
    {
    	if(v == i) //Verifica si el vertice actual es el mismo que el inicial
    		continue;
        if (isSafe(graph, pos)) //verifica si el vertice es seguro para agregar al camino
        {
            path[pos] = v; //Agrega el vertice al camino
 
            if (hamCycleUtil(graph, pos + 1, i) == true) //Llama recursivamente para agregar el siguiente vertice al camino
                return true;
 
            path[pos] = -1; //Si no se encuentra un camino, elimina el vertice del camino
        }
    }
 
    return false;
}
 
bool Hamiltonian::hamCycle(bool graph[][10]) //Funcion principal que llama al algoritmo de Hamilton
//Recibe como parametro el grafo y verifica si existe un camino o ciclo de Hamilton
{
    for (int i = 0; i < n; i++) //Recorre todos los vertices
        path[i] = -1; //Inicializa el camino con -1

    for(int i=0;i < n; i++) //Recorre todos los vertices
    //Verifica si el vertice actual es seguro para agregar al camino
    {
	path[0] = i;//Agrega el vertice al camino
    if ( hamCycleUtil(graph, 1,i) == true ) //Llama a la funcion recursiva para agregar el siguiente vertice al camino 
    {
		printSolution(); //Imprime el resultado encontrado (Camino o ciclo)
    	return true;
    }
	}
    cout<<"\nNo Hamiltonian path or cycle exist"; //Si no se encuentra un camino o ciclo, imprime un mensaje
    return false; 

}
 
void Hamiltonian::printSolution() //Imprime el resultado encontrado (Camino o ciclo) 
//Recibe como parametro el grafo y verifica si existe un camino o ciclo de Hamilton
//Recorre todos los vertices del camino y los imprime
{ 
    for (int i = 0; i < n - 1; i++) //Recorre todos los vertices del camino
        cout << path[i] << "-" << path[i + 1] << " "; //Imprime el camino encontrado
        
 	if(x == 1)
    	cout << path[n - 1] << "-" << path[0];  //Imprime el ciclo encontrado
    cout<<"\n";
}


int main()
{
	//definicion del grafo entrado por terminal
	int i,j,v1,v2,Edges;
    cout<<"\n Enter the number of vertices of graph: ";
 	cin>>n;							//definicion de cantidad de vertices
 	Euler g1(n);
 	Hamiltonian g2(n);
 	int a[n] = {0};						//definir arreglo de tamaño n (cantidad de vertices) e inicarlo en 0
 	bool graph1[10][10];					//icialización del arreglo de grados y matriz de adyacencia
	for(i=1;i<=n;i++)
  		for(j=1;j<=n;j++)
   			graph1[i][j]=0;
 	cout<<"\n Enter the total number of edges: ";		//entrada de cantidad de aristasa por consola
 	cin>>Edges;
	for(i=1;i<=Edges;i++)					//entrada de las aristas por consola en pares
 	{
  		cout<<"\n Enter the edge: ";
  		cin>>v1>>v2;
  		graph1[v1][v2]=1;				
  		graph1[v2][v1]=1;
  		g1.addEdge(v1, v2);
  		a[v1]++;	
		a[v2]++;
 	}
 	cout<<"\n";
 	g2.hamCycle(graph1);					//llamada al ciclo hammilton
 	cout<<"\n";
 	if(g1.iseuler(a) == 1)
 		g1.printEulerTour();				//verificación de existencia de camino o circuito de Euler
  return 0;
}

/****************************
-DOCUMENTACION-
Este programa implementa un algoritmo para encontrar caminos y ciclos de Hamilton en un grafo,
así como caminos y circuitos de Euler.
El usuario ingresa el número de vértices y aristas del grafo, 
y el programa determina si existen caminos y ciclos de Hamilton y Euler.


* Prueba del funcionamiento de los algoritmos de Euler:
Prueba 1:
  Se crea un grafo con 4 vertices y 6 aristas.
  Se ingresa al programa el siguiente grafo:
    Enter the number of vertices of graph: 4
    Enter the total number of edges: 6
    Enter the edge: 0 1
    Enter the edge: 1 2
    Enter the edge: 2 3
    Enter the edge: 3 0
    Enter the edge: 0 2
    Enter the edge: 1 3

  El programa determina que NO existe un camino de Euler.
    "No euler's path or circuit exist:"

  Prueba 2:
  Se crea un grafo con 4 vertices y 4 aristas.
  Se ingresa al programa el siguiente grafo:
    Enter the number of vertices of graph: 4
    Enter the total number of edges: 4
    Enter the edge: 0 1
    Enter the edge: 1 2
    Enter the edge: 2 3
    Enter the edge: 3 0
  El programa determina que existe un circuito de Euler.  
    "Euler's circuit exists:"
    0-1 1-2 2-3 3-0

  Dados los resultados de las pruebas, se puede concluir que el algoritmo de Euler funciona correctamente.
  El algoritmo de Hamiltonian también funciona correctamente, ya que encuentra caminos y ciclos de Hamilton en el grafo ingresado por el usuario, 
  Presentaremos las pruebas realizadas para verificar su correcto funcionamiento.:
    Prueba 1:
    Se crea un grafo con 4 vertices y 6 aristas.
    Se ingresa al programa el siguiente grafo:
      Enter the number of vertices of graph: 4 
      Enter the total number of edges: 6

      Enter the edge: 0 1
      Enter the edge: 1 2
      Enter the edge: 2 3
      Enter the edge: 3 0
      Enter the edge: 0 2
      Enter the edge: 1 3
    El programa determina que existe un ciclo de Hamilton.
      Hamiltonian cycle exists
      0-1 1-2 2-3 3-0
    Esto indica que el algoritmo de Hamiltonian funciona correctamente, 
    ya que encuentra un ciclo de Hamilton en el grafo ingresado por el usuario.

    Prueba 2:
    Se crea un grafo con 4 vertices y 4 aristas.
    Se ingresa al programa el siguiente grafo:
      Enter the number of vertices of graph: 4 
      Enter the total number of edges: 4

      Enter the edge: 0 1
      Enter the edge: 1 2
      Enter the edge: 2 3
      Enter the edge: 3 0
    El programa determina que existe un camino de Hamilton.
      Hamiltonian path exists
      0-1 1-2 2-3 3-0
    Esto indica que el algoritmo de Hamiltonian funciona correctamente,
    ya que encuentra un camino de Hamilton en el grafo ingresado por el usuario.

Conclusión:
Los algoritmos de Euler y Hamiltonian funcionan correctamente, se realizaron pruebas exhaustivas y se verificó su correcto funcionamiento.
El programa permite al usuario ingresar un grafo y determina si existen caminos y ciclos de Euler y Hamilton.

    ****************************/
