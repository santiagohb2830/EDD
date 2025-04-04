/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/

#ifndef __NODO__H__
#define __NODO__H__

#include<vector>			//se añadio librerias faltante
#include<queue>

using namespace std;

//declaracion de clase Nodo
template< class T >
class Nodo{
  protected:
    T dato;
    vector<Nodo <T> > hijos;

  public:
  	Nodo();
  	Nodo(T valor);
  	int altura();
  	int tamano();
    T& obtenerDato();
    void fijarDato(T& val);
    void limpiarLista();
    void adicionarDesc(T& val);
    bool eliminarDesc(T &val);
    void preOrden();
    void posOrden();
    void nivelOrden(queue<Nodo*> &cola);		//correccion declaracion de funcion
    Nodo* buscar(T val);
};

#include "nodo.hxx"
#endif
