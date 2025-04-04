/************************************************
* Fecha: 28 de Marzo 2025
* Autor: Santiago Hernandez, Juan Esteban Bello
* Materia: Estructuras de Datos
* Tema: Taller Arboles
************************************************/

#include "NodoExpresion.h"
#include <string>

using namespace std;

// Constructor: inicializa los hijos en NULL
NodoExpresion::NodoExpresion(){
	this->hijoIzq=NULL;
	this->hijoDer=NULL;
}

// Destructor (vacio en esta implementacion)
NodoExpresion::~NodoExpresion(){
}

// Retorna el caracter almacenado en el nodo
char NodoExpresion::getDato(){
	return this->dato;
}

// Asigna el caracter al nodo
void NodoExpresion::setDato(char val){
	this->dato=val;
	return;
}

// Retorna el hijo izquierdo
NodoExpresion* NodoExpresion::getHijoIzq(){
	return this->hijoIzq;
}

// Retorna el hijo derecho
NodoExpresion* NodoExpresion::getHijoDer(){
	return this->hijoDer;
}

// Asigna el hijo izquierdo
void NodoExpresion::setHijoIzq(NodoExpresion* izq){
	this->hijoIzq=izq;
	return;
}

// Define si el nodo es operando
void NodoExpresion::setOperando(bool op){
	this->operando=op;
	return;
}

// Retorna si el nodo es operando
bool NodoExpresion::getOperando(){
	return this->operando;
}

// Asigna el hijo derecho
void NodoExpresion::setHijoDer(NodoExpresion* der){
	this->hijoDer=der;
	return;
}
