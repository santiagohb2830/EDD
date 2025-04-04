/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/

#include <iostream>
#include <queue>
#include "arbol.h"

using namespace std;

//constructor vacio
template<class T>
Arbol<T>::Arbol()
{
    Nodo<T>* root = NULL;
}

//contructor con parametros
template<class T>
Arbol<T>::Arbol(T val)
{
    Nodo<T>* root =new  Nodo<T>(val);
    this->raiz=root;
}

//funcion que valida si el arbol esta vacio
template<class T>
bool Arbol<T>:: esVacio()
{
    if(this->raiz==NULL)
        return true;
    return false;
}

//getter de raiz
template<class T>
T Arbol<T>:: obtenerRaiz()
{
    return this->raiz;
}

//setter de raiz
template<class T>
void Arbol<T>::fijarRaiz(Nodo<T>* root)
{
    this->raiz = root;
}


template<class T>
int Arbol<T>:: altura()
{
    return this->raiz->altura();
}

template<class T>
int Arbol<T>:: tamano()
{
    return this->raiz->tamano();
}

//funcion que incerta un nodo recursivamente dado su padre y dato del nuevo nodo
template<class T>
bool Arbol<T>:: insertarNodo(T padre, T val)
{
    Nodo<T>* aux = this->raiz->buscar(padre);
    if(aux == NULL)
        return false;
    aux->adicionarDesc(val);
    return true;
}


template<class T>
bool Arbol<T>:: eliminar(T val)
{
    return this->raiz->eliminar(val);
}

template<class T>
Nodo<T>* Arbol<T>::  buscar(T val)
{
    return this->raiz->buscar(val);
}

template<class T>
void Arbol<T>:: preOrden()
{
    this->raiz->preOrden();
}

template<class T>
void Arbol<T>:: inOrden()
{
    this->raiz->inOrden();
}

template<class T>
void Arbol<T>:: posOrden()
{
    this->raiz->posOrden();
}

template<class T>
void Arbol<T>:: nivelOrden()
{
    this->raiz->nivelOrden();
}
