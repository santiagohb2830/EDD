/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/
#include <iostream>
using namespace std;

#include "ArbolBinario.h"

// Constructor por defecto (CORREGIDO: se inicializa raiz como nullptr)
ArbolBinario::ArbolBinario() {
    raiz = nullptr;
}

// Retorna la raiz
NodoBinario* ArbolBinario::obtenerRaiz() {
    return raiz;
}

// Inserta un nuevo valor en el arbol
void ArbolBinario::insertar(int valor) {
    NodoBinario* nuevo = new NodoBinario(valor);
    if (raiz == nullptr) {
        raiz = nuevo; // Si esta vacio, nuevo es la raiz
    } else {
        NodoBinario* actual = raiz;
        while (true) {
            if (valor < actual->obtenerDato()) {
                // Ir a la izquierda
                if (actual->obtenerHijoIzquierdo() == nullptr) {
                    actual->fijarHijoIzquierdo(nuevo);
                    break;
                } else {
                    actual = actual->obtenerHijoIzquierdo();
                }
            } else {
                // Ir a la derecha
                if (actual->obtenerHijoDerecho() == nullptr) {
                    actual->fijarHijoDerecho(nuevo);
                    break;
                } else {
                    actual = actual->obtenerHijoDerecho();
                }
            }
        }
    }
}

// Recorrido inorden (izquierda, raiz, derecha)
void ArbolBinario::inOrden(NodoBinario* nodo) {
    if (nodo != nullptr) {
        inOrden(nodo->obtenerHijoIzquierdo());
        cout << nodo->obtenerDato() << " ";
        inOrden(nodo->obtenerHijoDerecho());
    }
}

// Recorrido preorden (raiz, izquierda, derecha)
void ArbolBinario::preOrden(NodoBinario* nodo) {
    if (nodo != nullptr) {
        cout << nodo->obtenerDato() << " ";
        preOrden(nodo->obtenerHijoIzquierdo());
        preOrden(nodo->obtenerHijoDerecho());
    }
}

// Recorrido posorden (izquierda, derecha, raiz)
void ArbolBinario::posOrden(NodoBinario* nodo) {
    if (nodo != nullptr) {
        posOrden(nodo->obtenerHijoIzquierdo());
        posOrden(nodo->obtenerHijoDerecho());
        cout << nodo->obtenerDato() << " ";
    }
}

