/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/

#ifndef NODOBINARIOAVL_H
#define NODOBINARIOAVL_H

template <class T>

//definicion de la clase NodoBinarioAVL
class NodoBinarioAVL{
	public:
		T dato;
		NodoBinarioAVL<T> *hijoIzq;
		NodoBinarioAVL<T> *hijoDer;

	public:
		NodoBinarioAVL();
		~NodoBinarioAVL();
		T& getDato();
		void setDato(T& val);
		NodoBinarioAVL<T>* getHijoIzq();
		NodoBinarioAVL<T>* getHijoDer();
		void setHijoIzq(NodoBinarioAVL<T>* izq);
		void setHijoDer(NodoBinarioAVL<T>* der);
};

#include "NodoBinarioAVL.hxx"

#endif //NODOBINARIOAVL_H
