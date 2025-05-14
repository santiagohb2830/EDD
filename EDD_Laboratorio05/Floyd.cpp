	/****************************************************************
	Fecha 14 de Mayo 2025
	Autor: Santiago Hernandez
	Materia: Estructuras de Datos
	Tema: Laboratorio 05
	*****************************************************************/
#include <iostream>

using namespace std;
/*Función algoritmo de Floyd Warshall: camino más corto 
para un grafo representado mediante representación de matriz de
adyacencia*/

const int V = 5;

void floyds(int b[V][V]){

	int i, j, k;
	
	// ELiminar valores infinitos y encontrar el menor valor.
	
		for (k = 0; k < V; k++) {
			for (i = 0; i < V; i++) {
				for (j = 0; j < V; j++) {
					if ((b[i][k] * b[k][j] != 0) && (i != j)) {
						if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0)) {
							b[i][j] = b[i][k] + b[k][j];
						}
					}
				}
			}
		}
	
	// Imprimir la matriz completa sin valores infinitos y con el camino mas corto
	
	for (i = 0; i < V; i++) {
		cout<<"Minimum Cost With Respect to Node:"<<i<<endl;
		for (j = 0; j < V; j++) {
			cout<<b[i][j]<<"\t";
		}
	}
	
	cout << endl;
}

int main(){
	/* Ejemplo 1:
	//Tamaño del grafo
	int b[3][3];
	// Grafo:
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			b[i][j] = 0;
		}
	}
		
	// Costos de el grafo ponderado
	b[0][1] = 10;
	b[1][2] = 15;
	b[2][0] = 12;
	
	// Funcion de algoritmo de Floyd Warshall
	floyds(b);
	*/
	
	// Tamaño del grafo:
	
	int b[V][V];
	
	for (int i = 0; i < V; i++) {
		for (int j=0; j < V; j++) {
			b[i][j];
		}
	}
	
	// Costos de el grafo ponderado;
	
	b[0][1] = 5;
	b[0][3] = 6;
	b[1][2] = 1;
	b[1][4] = 7;
	b[2][0] = 3;
	b[2][3] = 4;
	b[3][2] = 2;
	b[3][4] = 3;
	b[4][0] = 2;
	b[4][3] = 5;
	
	floyds(b);
	
	return 0;
}

