/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/

#include <iostream>
#include<queue>			//se añadio libreria faltante
#include "nodo.h"

using namespace std;

//constructor
template<class T>
Nodo<T>::Nodo()
{

}
//constructor con parametros
template<class T>
Nodo<T>::Nodo(T valor)
{
    this->dato = valor;
}

//getter de datos
template<class T>
T& Nodo<T>::obtenerDato()
{
    return this->dato;
}

//setter de datos
template<class T>
void Nodo<T>::fijarDato(T& val)
{
    this->dato = val;
    return;
}

//funcion de soporte que calcula la altura de un sub-tree
template<class T>
int Nodo<T>::altura()
{
	if(hijos.size()==0)
	{
		return 0;
	}
	int maximo = 0, aux_altura;
	for(int i = 0;i<hijos.size() ; i++){
	    aux_altura = hijos[i].altura();
        if(aux_altura> maximo)
            maximo = aux_altura;
	}
	return maximo + 1;
}

//funcion que cuenta los nodos
template<class T>
int Nodo<T>::tamano()
{
	if(this->hijoIzq==NULL && this->hijoDer == NULL)
	{
		return 1;
	}
	int conta = 0;
	for( int i = 0; i<hijos.size() ; ++i){
        conta+=hijos[i].tamano();
	}
	return conta+1;
}

//funcion que elimina todos los hijos guardados en un nodo
template<class T>
void Nodo<T>:: limpiarLista()
{
    if(hijos.size()==0){
        delete(this);
        return;

    }

    for(int i=0; i<hijos.size(); i++){
        hijos[i].limpiarLista();
    }

}

//funcion que añade nodos hijo
template<class T>
void Nodo<T>:: adicionarDesc(T &val)
{
    Nodo* hijo = new Nodo(val);
    hijos.push_back(*hijo);
}

//funcion para eliminar un nodo hijo especifico
template<class T>
bool Nodo<T>:: eliminarDesc(T &val){
    bool correr=false;
    for(int i=0;i<hijos.size();i++){
        if(correr){
            hijos[i-1]=hijos[i];
        }
        if(hijos[i] == val)
            correr=true;
    }

    if(!correr)
        return false;
    hijos.pop_back();
    return true;
}

//funcion para buscar un nodo especifico
template<class T>
Nodo<T>* Nodo<T>:: buscar(T val){
    if(this->dato == val)
        return this;
    if(this->hijos.size() == 0)
        return NULL;
    Nodo* aux;
    for(int i = 0; i<hijos.size() ; i++){
        aux = hijos[i].buscar(val);
        if(aux!=NULL)
            return aux;
    }

    return NULL;

}

//funcion imprime arbol en preOrder (DLR)
template<class T>
void Nodo<T>:: preOrden()
{
	cout << "\t"<<this->obtenerDato() << endl;
	for(int i = 0; i < hijos.size() ; i++){
        hijos[i].preOrden();
	}
	return;
}

//funcion imprime arbol en posOrder (LRD)
template<class T>
void Nodo<T>:: posOrden()
{
	for(int i = 0; i < hijos.size() ; i++){
        hijos[i].preOrden();
	}
	return;

	cout << "\t"<<this->obtenerDato() << endl;
	return;

}

//funcion imprime arbol por nivel
template<class T>
void Nodo<T>:: nivelOrden(queue<Nodo*> &cola){
	cola.push(this);
	for(int i=0 ; i<this->hijos->size() ; i++){
        cola.push(this->hijos[i]);
	}
}




