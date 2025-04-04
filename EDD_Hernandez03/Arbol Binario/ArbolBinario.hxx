/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/

#include "ArbolBinario.h"
#include "NodoBinario.h"

using namespace std;

//constructor de la clase
template<class T>
ArbolBinario<T>::ArbolBinario()
{
    this->raiz=NULL;
}

//funcion vaida si el arbol esta vacio
template<class T>
bool ArbolBinario<T>::esVacio()
{
    if(this==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//getter de dato
template<class T>
T& ArbolBinario<T>::datoRaiz()
{
    return this->raiz->obtenerDato();
}

template<class T>
int ArbolBinario<T>::altura()
{
    return this->raiz->altura();
}

template<class T>
int ArbolBinario<T>::tamano()
{
    return this->raiz->tamano() ;
}


template<class T>
void ArbolBinario<T>::insertar(T& val)
{
    if(this->raiz!=NULL)
    {
        this->raiz->insertar(val);
    }
    else
    {
        NodoBinario<T>* nuevo= new NodoBinario<T>();
        nuevo->fijarDato(val);
        this->raiz=nuevo;
    }


}


//funcion recursiva de eliminacion con parametro
template<class T>
bool ArbolBinario<T>::eliminar(T& val)
{ 
	//Nodo* borrar = this->buscar(val);
	NodoBinario<T>* borrar = this->buscar(val);
    if(borrar == NULL)
        return false;

    if(borrar->hijoIzq != NULL)
    {
        //Nodo* nuevo = borrar->hijoIzq->extremo_der();
		NodoBinario<T>* nuevo = borrar->hijoIzq->extremo_der();
        borrar->fijarDato(nuevo->obtenerDato());
		delete(nuevo);    }
    else if(borrar->hijoDer != NULL)
    {
		
        //Nodo* nuevo = borrar->hijoDer->extremo_izq();
		NodoBinario<T>* nuevo = borrar->hijoDer->extremo_izq();
        borrar->fijarDato(nuevo->obtenerDato());
		delete(nuevo);
    }
    return true;
}


//funcion de soporte que busca un nodo
template<class T>
NodoBinario<T>* ArbolBinario<T>::buscar(T& val)
{
    return this->raiz->buscar(val);
}

template<class T>
void ArbolBinario<T>::preOrden()
{
    this->raiz->preOrden();
}

template<class T>
void ArbolBinario<T>::inOrden()
{
    this->raiz->inOrden();
}

template<class T>
void ArbolBinario<T>::posOrden()
{
    this->raiz->posOrden();
}

template<class T>
void ArbolBinario<T>::nivelOrden()
{
    this->raiz->nivelOrden();
}

