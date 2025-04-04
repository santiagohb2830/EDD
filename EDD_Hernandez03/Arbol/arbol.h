/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/

#ifndef __ARBOL__H__
#define __ARBOL__H__

#include "nodo.h"

using namespace std;

//declaracion de clase Arbol
template<class T>
class Arbol {
	protected:
    	Nodo<T> *raiz;
	public:
		Arbol();
		Arbol(T val);
	    bool esVacio();
   	 	T obtenerRaiz();
   	 	void fijarRaiz(Nodo<T>* root);
   	 	bool insertarNodo(T padre, T val);
    	int altura();
	    int tamano();
   		void insertar(T& val);
    	bool eliminar(T val);
    	Nodo<T>*  buscar(T val);
    	void preOrden();
    	void inOrden();
    	void posOrden();
    	void nivelOrden();
};

#include "arbol.hxx"
#endif
