/************************************************
* Fecha 28 de Marzo 2025
* Autor: Santiago Hernandez, Juan Esteban Bello
* Materia: Estructuras de Datos
* Tema: Taller Arboles
************************************************/

#include "kdnodo.h"
#include <bits/stdc++.h>

using namespace std;

// Constructor: inicializa punteros nulos y el tag en 0
template<class T>
kdnodo<T>::kdnodo()
{
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
    this->tag = 0;
}

// Retorna el dato del nodo (en este caso, el vector completo)
template<class T>
T& kdnodo<T>::obtenerDato()
{
    return this->dato;
}

// Asigna el vector de datos al nodo
template<class T>
void kdnodo<T>::fijarDato(vector < T >& val)
{
    this->datos = val;
}

// Asigna el tag (dimension en la que se compara)
template<class T>
void kdnodo<T>::fijarTag(int value)
{
    this->tag = value;
}

// Retorna el hijo izquierdo
template<class T>
kdnodo<T>* kdnodo<T>::obtenerHijoIzq()
{
    return this->hijoIzq;
}

// Retorna el hijo derecho
template<class T>
kdnodo<T>* kdnodo<T>::obtenerHijoDer()
{
    return this->hijoDer;
}

// Asigna el hijo izquierdo
template<class T>
void kdnodo<T>::fijarHijoIzq(kdnodo<T> *izq)
{
    this->hijoIzq = izq;
}

// Asigna el hijo derecho
template<class T>
void kdnodo<T>::fijarHijoDer(kdnodo<T> *der)
{
    this->hijoDer = der;
}

// Calcula la altura del arbol desde este nodo
template<class T>
int kdnodo<T>::altura()
{
	if(this->hijoIzq==NULL && this->hijoDer == NULL)
	{
		return 1;
	}
	if(this->hijoIzq==NULL)
		return this->hijoDer->altura();
	else if(this->hijoDer==NULL)
		return this->hijoIzq->altura();

	return max(this->hijoIzq->altura() , this->hijoDer->altura());
}

// Calcula el tamaño del subarbol desde este nodo
template<class T>
int kdnodo<T>::tamano()
{
	if(this->hijoIzq==NULL && this->hijoDer == NULL)
	{
		return 1;
	}
	if(this->hijoIzq==NULL)
		return this->hijoDer->tamano() +1 ;
	else if(this->hijoDer==NULL)
		return this->hijoIzq->tamano() +1 ;

	return this->hijoIzq->tamano() + this->hijoDer->tamano() +1 ;
}

// Inserta un vector en el arbol desde este nodo
template<class T>
void kdnodo<T>:: insertar(vector < T >& val)
{
	if(val[this->tag] > this->datos[this->tag])
	{
		if(this->hijoDer == NULL)
		{
			kdnodo* nuevo= new kdnodo();
			nuevo->fijarTag((this->tag+1)%val.size());
			nuevo->fijarDato(val);
			this->fijarHijoDer(nuevo);
		}
		else
		{
			this->hijoDer->insertar(val);
		}
	}

	if(val[this->tag] < this->datos[this->tag])
	{
		if(this->hijoIzq == NULL)
		{
			kdnodo* nuevo= new kdnodo();
			nuevo->fijarTag((this->tag+1)%val.size());
			nuevo->fijarDato(val);
			this->fijarHijoIzq(nuevo);
		}
		else
		{
			this->hijoIzq->insertar(val);
		}
	}
}

// Busca un vector en el arbol desde este nodo
template<class T>
kdnodo<T>* kdnodo<T>:: buscar(vector < T >& val)
{
	if(this->iguales(val))
	{
		return this;
	}

	if(val[this->tag] < this->datos[this->tag])
	{
		return this->hijoIzq->buscar(val);
	}
	else
	{
		return this->hijoDer->buscar(val);
	}
}

// Compara si dos vectores son iguales
template<class T>
bool kdnodo<T>::iguales(vector < T >& val)
{
	for(int i = 0 ; i < val.size() ; ++i)
	{
		if(this->datos[i] != val[i])
		{
			return false;
		}
	}
	return true;
}

// Recorre el arbol en preorden desde este nodo
template<class T>
void kdnodo<T>:: preOrden()
{
	this->imprimir();
	if(this->hijoIzq != NULL)
		this->hijoIzq->preOrden();
	if(this->hijoDer != NULL)
		this->hijoDer->preOrden();
	return;
}

// Recorre el arbol en inorden desde este nodo
template<class T>
void kdnodo<T>:: inOrden()
{
	if(this->hijoIzq != NULL)
		this->hijoIzq->inOrden();

	this->imprimir();

	if(this->hijoDer != NULL)
		this->hijoDer->inOrden();
	return;
}

// Recorre el arbol en posorden desde este nodo
template<class T>
void kdnodo<T>:: posOrden()
{
	if(this->hijoIzq != NULL)
		this->hijoIzq->posOrden();

	if(this->hijoDer != NULL)
		this->hijoDer->posOrden();

	this->imprimir();
	return;
}

// Recorre el arbol por niveles
template<class T>
void kdnodo<T>:: nivelOrden()
{
	queue<kdnodo*> cola;
	cola.push(this);
	while(!cola.empty()){
		cout<<"\t"<<cola.front()->obtenerDato()<<endl;
		if(cola.front()->hijoIzq != NULL){
			cola.push(cola.front()->hijoIzq);
		}

		if(cola.front()->hijoDer != NULL){
			cola.push(cola.front()->hijoDer);
		}
		cola.pop();
	}
}

// Encuentra el valor maximo desde este nodo
template<class T>
void kdnodo<T>:: maximo(int &maxi)
{
	if(maxi < this->obtenerDato())
	{
		maxi = this->obtenerDato();
	}
	if(this->hijoIzq != NULL)
		this->hijoIzq->maximo(maxi);

	if(this->hijoDer != NULL)
		this->hijoDer->maximo(maxi);
	return;
}

// Encuentra el valor minimo desde este nodo
template<class T>
void kdnodo<T>:: minimo(int &mini)
{
	if(mini > this->obtenerDato())
	{
		mini = this->obtenerDato();
	}
	if(this->hijoIzq != NULL)
		this->hijoIzq->minimo(mini);

	if(this->hijoDer != NULL)
		this->hijoDer->minimo(mini);
	return;
}

// Imprime el vector de datos del nodo
template<class T>
void kdnodo<T>:: imprimir()
{
	cout<<"( ";
	for(int i = 0 ; i < this->datos.size() ; ++i)
	{
		cout<<this->datos[i];
		if(i!=this->datos.size()-1)
			cout<<", ";
	}
	cout<<" )\n";
}
