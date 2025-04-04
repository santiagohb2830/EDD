/************************************************
* Fecha 28 de Marzo 2025
* Autor: Santiago Hernandez, Juan Esteban Bello
* Materia: Estructuras de Datos
* Tema: Taller Arboles
************************************************/

#include "nodo.h"
#include <bits/stdc++.h>
using namespace std;

// Constructor por defecto, inicializa todos los hijos en NULL
template<class T>
Nodo<T>::Nodo() {
    this->NW = NULL;
    this->NE = NULL;
    this->SW = NULL;
    this->SE = NULL;
}

// Constructor que recibe un par de coordenadas
template<class T>
Nodo<T>::Nodo(pair<T,T> val) {
    this->dato = val;
    this->NW = NULL;
    this->NE = NULL;
    this->SW = NULL;
    this->SE = NULL;
}

// Retorna el par almacenado en el nodo
template<class T>
pair<T,T> Nodo<T>::obtenerDato() {
    return this->dato;
}

// Asigna un nuevo par de valores al nodo
template<class T>
void Nodo<T>::fijarDato(pair<T,T> val) {
    this->dato = val;
    return;
}

// Calcula la altura del nodo dentro del arbol
template<class T>
int Nodo<T>::altura() {
    if(NW == NULL && NE == NULL && SW == NULL && SE == NULL)
        return 1;

    int mayor = 0, actual;
    if(NW != NULL) {
        actual = this->NW->altura() + 1;
        if(actual > mayor) mayor = actual;
    }
    if(NE != NULL) {
        actual = this->NE->altura() + 1;
        if(actual > mayor) mayor = actual;
    }
    if(SW != NULL) {
        actual = this->SW->altura() + 1;
        if(actual > mayor) mayor = actual;
    }
    if(SE != NULL) {
        actual = this->SE->altura() + 1;
        if(actual > mayor) mayor = actual;
    }
}

// Calcula el numero total de nodos descendientes (tamano del subarbol)
template<class T>
int Nodo<T>::tamano() {
    if(NW == NULL && NE == NULL && SW == NULL && SE == NULL)
        return 1;

    int cont = 0;
    if(NW != NULL) cont += this->NW->altura() + 1;
    if(NE != NULL) cont += this->NE->altura() + 1;
    if(SW != NULL) cont += this->SW->altura() + 1;
    if(SE != NULL) cont += this->SE->altura() + 1;
    return cont;
}

// Inserta un nuevo par de datos en el arbol segun coordenadas
template<class T>
void Nodo<T>::insertar(pair<T,T> val) {
    // Norte
    if(this->dato.first < val.first) {
        if(this->dato.second < val.second) {
            if(this->NE != NULL) {
                this->NE->insertar(val);
            } else {
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                this->NE = nuevo;
            }
        } else {
            if(this->SE != NULL) {
                this->SE->insertar(val);
            } else {
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                this->SE = nuevo;
            }
        }
    }

    // Sur
    if(this->dato.first > val.first) {
        if(this->dato.second < val.second) {
            if(this->NW != NULL) {
                this->NW->insertar(val);
            } else {
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                this->NW = nuevo;
            }
        } else {
            if(this->SW != NULL) {
                this->SW->insertar(val);
            } else {
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                this->SW = nuevo;
            }
        }
    }
}

// Busca un par de datos dentro del arbol desde este nodo
template<class T>
Nodo<T>* Nodo<T>::buscar(pair<T,T> val) {
    if(this->dato == val) return this;
    if(NW == NULL && NE == NULL && SW == NULL && SE == NULL) return NULL;

    if(this->dato.first < val.first) {
        if(this->dato.second < val.second) {
            if(this->NE != NULL) return this->NE->buscar(val);
            else return NULL;
        } else {
            if(this->SE != NULL) return this->SE->buscar(val);
            else return NULL;
        }
    }

    // Sur
    if(this->dato.first > val.first) {
        if(this->dato.second < val.second) {
            if(this->NW != NULL) return this->NW->buscar(val);
            else return NULL;
        } else {
            if(this->SW != NULL) return this->SW->buscar(val);
            else return NULL;
        }
    }

    return NULL;
}

// Recorre el arbol en preorden desde este nodo
template<class T>
void Nodo<T>::preOrden() {
    cout << "(" << this->dato.first << ',' << this->dato.second << ")" << endl;
    if(this->NW != NULL) this->NW->preOrden();
    if(this->NE != NULL) this->NE->preOrden();
    if(this->SW != NULL) this->SW->preOrden();
    if(this->SE != NULL) this->SE->preOrden();
    return;
}

// Recorre el arbol en posorden desde este nodo
template<class T>
void Nodo<T>::posOrden() {
    if(this->NW != NULL) this->NW->preOrden();
    if(this->NE != NULL) this->NE->preOrden();
    if(this->SW != NULL) this->SW->preOrden();
    if(this->SE != NULL) this->SE->preOrden();
    cout << "(" << this->dato.first << ',' << this->dato.second << ")" << endl;
    return;
}

// Recorre el arbol en inorden desde este nodo
template<class T>
void Nodo<T>::inOrden() {
    if(this->NW != NULL) this->NW->preOrden();
    if(this->NE != NULL) this->NE->preOrden();
    cout << "(" << this->dato.first << ',' << this->dato.second << ")" << endl;
    if(this->SW != NULL) this->SW->preOrden();
    if(this->SE != NULL) this->SE->preOrden();
    return;
}
