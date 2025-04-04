/************************************************
* Fecha 28 de Marzo 2025
* Autor: Santiago Hernandez, Juan Esteban Bello
* Materia: Estructuras de Datos
* Tema: Taller Arboles
************************************************/

#include <bits/stdc++.h>
#include "quadtree.h"
using namespace std;

// Constructor por defecto, inicializa raiz como nula
template<class T>
Arbol<T>::Arbol() {
    Nodo<T>* root = NULL;
}

// Constructor que recibe un par de datos para inicializar la raiz
template<class T>
Arbol<T>::Arbol(pair<T,T> val) {
    Nodo<T>* root = new Nodo<T>(val);
    this->raiz = root;
}

// Verifica si el arbol esta vacio
template<class T>
bool Arbol<T>::esVacio() {
    if(this->raiz == NULL)
        return true;
    return false;
}

// Retorna el valor almacenado en la raiz
template<class T>
pair<T,T> Arbol<T>::obtenerRaiz() {
    return this->raiz->obtenerDato();
}

// Asigna un nuevo nodo como raiz
template<class T>
void Arbol<T>::fijarRaiz(Nodo<T>* root) {
    this->raiz = root;
}

// Retorna la altura total del arbol
template<class T>
int Arbol<T>::altura() {
    return this->raiz->altura();
}

// Retorna el numero de nodos en el arbol
template<class T>
int Arbol<T>::tamano() {
    return this->raiz->tamano();
}

// Inserta un nuevo par de datos en el arbol
template<class T>
void Arbol<T>::insertar(pair<T,T> val) {
    this->raiz->insertar(val);
}

// Busca un nodo en el arbol segun coordenadas
template<class T>
Nodo<T>* Arbol<T>::buscar(pair<T,T> val) {
    return this->raiz->buscar(val);
}

// Recorre el arbol en preorden
template<class T>
void Arbol<T>::preOrden() {
    this->raiz->preOrden();
}

// Recorre el arbol en posorden
template<class T>
void Arbol<T>::posOrden() {
    this->raiz->posOrden();
}

// Recorre el arbol en inorden
template<class T>
void Arbol<T>::inOrden() {
    this->raiz->inOrden();
}
