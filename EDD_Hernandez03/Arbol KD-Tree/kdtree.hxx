/************************************************
* Fecha 28 de Marzo 2025
* Autor: Santiago Hernandez, Juan Esteban Bello
* Materia: Estructuras de Datos
* Tema: Taller Arboles
************************************************/

#include "kdtree.h"
#include "kdnodo.h"
#include <vector>

using namespace std;

// Constructor del arbol, inicializa la raiz como nula
template<class T>
kdtree<T>::kdtree(){
	this->raiz=NULL;
}

// Verifica si el arbol esta vacio
template<class T>
bool kdtree<T>::esVacio()
{
   if(this==NULL)
   {
      return true;
   }
   else
   {
     return false;
   }
}

// Retorna el dato almacenado en la raiz
template<class T>
T& kdtree<T>::datoRaiz()
{
   return this->raiz->obtenerDato();
}

// Retorna la altura del arbol
template<class T>
int kdtree<T>::altura()
{
   return this->raiz->altura();
}

// Retorna el numero de nodos del arbol
template<class T>
int kdtree<T>::tamano()
{
	return this->raiz->tamano() ;
}

// Inserta un vector de datos en el arbol
template<class T>
void kdtree<T>::insertar(vector<T>& val)
{
	if(this->raiz!=NULL){
		this->raiz->insertar(val);
	}
	else{
		kdnodo<T>* nuevo= new kdnodo<T>();
		nuevo->fijarDato(val);
		this->raiz=nuevo;
	}
}

// Funcion eliminar no implementada
template<class T>
bool kdtree<T>::eliminar(T& val)
{
	return false;
}

// Busca un nodo cuyo dato coincida con el vector val
template<class T>
kdnodo<T>* kdtree<T>::buscar(T& val)
{
	return this->raiz->buscar(val);
}

// Llama al recorrido preorden
template<class T>
void kdtree<T>::preOrden()
{
	this->raiz->preOrden();
}

// Llama al recorrido inorden
template<class T>
void kdtree<T>::inOrden()
{
	this->raiz->inOrden();
}

// Llama al recorrido posorden
template<class T>
void kdtree<T>::posOrden()
{
	this->raiz->posOrden();
}

// Llama al recorrido por niveles
template<class T>
void kdtree<T>::nivelOrden()
{
	this->raiz->nivelOrden();
}

// Llama a la funcion que encuentra el valor maximo
template<class T>
void kdtree<T>::maximo(int &maxi)
{
	this->raiz->maximo(maxi);
}

// Llama a la funcion que encuentra el valor minimo
template<class T>
void kdtree<T>::minimo(int &mini)
{
	this->raiz->minimo(mini);
}
