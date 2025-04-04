/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/

#ifndef __NODOBINARIO__H__
#define __NODOBINARIO__H__

using namespace std;

//declaracion de la clase NodoBinario
template< class T >
class NodoBinario
{
  protected:
    T dato;
    NodoBinario<T> *hijoIzq;
    NodoBinario<T> *hijoDer;

  public:
  	NodoBinario();
    T& obtenerDato();
    void fijarDato(T& val);
    NodoBinario<T>* obtenerHijoIzq();
    NodoBinario<T>* obtenerHijoDer();
    void fijarHijoIzq(NodoBinario<T> *izq);
    void fijarHijoDer(NodoBinario<T> *der);
    int altura();
    int tamano();
    void insertar(T& val);
    NodoBinario<T>* buscar(T& val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
	NodoBinario<T>* extremo_izq();
	NodoBinario<T>* extremo_der();
};

#include "NodoBinario.hxx"
#endif
