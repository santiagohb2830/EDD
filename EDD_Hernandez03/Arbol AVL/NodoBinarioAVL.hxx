/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/

#include "NodoBinarioAVL.h"

using namespace std;

//contructor de la clase
template <class T>
NodoBinarioAVL<T>::NodoBinarioAVL(){
	this->hijoIzq=NULL;
	this->hijoDer=NULL;
}

template <class T>
NodoBinarioAVL<T>::~NodoBinarioAVL(){
}

//getter de dato
template <class T>
T& NodoBinarioAVL<T>::getDato(){
	return this->dato;
}

//setter de dato
template <class T>
void NodoBinarioAVL<T>::setDato(T& val){
	this->dato=val;
	return;
}

//getter de HijoIzq
template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoIzq(){
	return this->hijoIzq;
}

//getter de HijDer
template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoDer(){
	return this->hijoDer;
}

//setter de HijoIzq
template <class T>
void NodoBinarioAVL<T>::setHijoIzq(NodoBinarioAVL<T>* izq){
	this->hijoIzq=izq;
	return;
}

//setter de HijoDer
template <class T>
void NodoBinarioAVL<T>::setHijoDer(NodoBinarioAVL<T>* der){
	this->hijoDer=der;
	return;
}
