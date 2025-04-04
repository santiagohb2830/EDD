/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/

#ifndef __NODO__H__
#define __NODO__H__

using namespace std;

template< class T >
class Nodo
{
  protected:
    pair<T,T> dato;
    Nodo<T>* NW;
    Nodo<T>* NE;
    Nodo<T>* SW;
    Nodo<T>* SE;


  public:
  	Nodo();
  	Nodo(pair<T,T> val);
  	int altura();
  	int tamano();
    pair<T,T> obtenerDato();
    void insertar(pair<T,T>  val);
    void fijarDato(pair<T,T> val);
    void preOrden();
    void posOrden();
    void inOrden();
    Nodo* buscar(pair<T,T> val);
};

#include "nodo.hxx"
#endif
