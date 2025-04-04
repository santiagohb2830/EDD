/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/
#include "NodoBinario.h"

// Constructor por defecto
NodoBinario::NodoBinario() {
    dato = 0;
    hijoIzq = nullptr;
    hijoDer = nullptr;
}

// Constructor con parametro (CORREGIDO: se agrego constructor funcional)
NodoBinario::NodoBinario(int val) {
    dato = val;
    hijoIzq = nullptr;
    hijoDer = nullptr;
}

// Retorna el valor del nodo
int NodoBinario::obtenerDato() {
    return dato;
}

// Cambia el valor del nodo
void NodoBinario::fijarDato(int val) {
    dato = val;
}

// Retorna el hijo izquierdo
NodoBinario* NodoBinario::obtenerHijoIzquierdo() {
    return hijoIzq;
}

// Retorna el hijo derecho
NodoBinario* NodoBinario::obtenerHijoDerecho() {
    return hijoDer;
}

// Asigna el hijo izquierdo
void NodoBinario::fijarHijoIzquierdo(NodoBinario* nodo) {
    hijoIzq = nodo;
}

// Asigna el hijo derecho
void NodoBinario::fijarHijoDerecho(NodoBinario* nodo) {
    hijoDer = nodo;
}

