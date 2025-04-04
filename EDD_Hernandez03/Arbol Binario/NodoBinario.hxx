/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/

#include "NodoBinario.h"
#include <bits/stdc++.h>

using namespace std;

//constructor de la clase
template<class T>
NodoBinario<T>::NodoBinario()
{
    this->hijoIzq=NULL;
    this->hijoDer=NULL;
}

//getter de dato
template<class T>
T& NodoBinario<T>::obtenerDato()
{
    return this->dato;
}

//setter de dato
template<class T>
void NodoBinario<T>::fijarDato(T& val)
{
    this->dato = val;
}

//getter HijoIzq
template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq()
{
    return this->hijoIzq;
}

//getter HijoDer
template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer()
{
    return this->hijoDer;
}

//setter HijoIzq
template<class T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T> *izq)
{
    this->hijoIzq = izq;
}

//setter HijoDer
template<class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T> *der)
{
    this->hijoDer = der;
}

//funcion que calcula la altura del arbol
template<class T>
int NodoBinario<T>::altura()
{
	if(this->hijoIzq==NULL && this->hijoDer == NULL)
	{
		return 1;
	}
	if(this->hijoIzq==NULL)
		return this->hijoDer->altura();
	else if(this->hijoDer==NULL)
		return this->hijoIzq->altura();


	return max(this->hijoIzq->altura() , this->hijoDer->altura());
}

//funcion que cuenta la cantidad de nodos del arbol
template<class T>
int NodoBinario<T>::tamano()
{
	if(this->hijoIzq==NULL && this->hijoDer == NULL)
	{
		return 1;
	}
	if(this->hijoIzq==NULL)
		return this->hijoDer->tamano() +1 ;
	else if(this->hijoDer==NULL)
		return this->hijoIzq->tamano() +1 ;


	return this->hijoIzq->tamano() + this->hijoDer->tamano() +1 ;
}

//funcion que incerta nuevos nodos recursivamente
template<class T>
void NodoBinario<T>:: insertar(T& val)
{

	if(val > this->obtenerDato()){
		if(this->hijoDer==NULL)
		{
			NodoBinario* nuevo= new NodoBinario();
			nuevo->fijarDato(val);
			this->fijarHijoDer(nuevo);
		}
		else
		{
			this->hijoDer->insertar(val);
		}
	}

	if(val < this->obtenerDato()){
		if(this->hijoIzq==NULL)
		{
			NodoBinario* nuevo= new NodoBinario();
			nuevo->fijarDato(val);
			this->fijarHijoIzq(nuevo);
		}
		else
		{
			this->hijoIzq->insertar(val);
		}
	}

}

//funcion que permite buscar un nodo
template<class T>
NodoBinario<T>* NodoBinario<T>:: buscar(T& val)
{
	if(this->obtenerDato()==val){
		return this;
	}

	if(val < this-> obtenerDato()){
        if(this->hijoIzq != NULL)
            return this->hijoIzq->buscar(val);
        else
            return NULL;
	}
	else{
        if(this->hijoDer != NULL)
            return this->hijoDer->buscar(val);
        else
            return NULL;
	}
}

//funcion devuelve el nodo de mayor valor
template<class T>
NodoBinario<T>* NodoBinario<T>::extremo_der()
{
    if(this->hijoDer != NULL)
        return this->hijoDer->extremoDer();
    else
        return this;
}

//funcion devuelve el nodo de menor valor
template<class T>
NodoBinario<T>* NodoBinario<T>::extremo_izq()
{
    if(this->hijoIzq != NULL)
        return this->hijoIzq->extremo_izq();
    else
        return this;
}

//funcion imprime arbol en preOrder (DLR)
template<class T>
void NodoBinario<T>:: preOrden()
{
	cout << "\t"<<this->obtenerDato() << endl;
	if(this->hijoIzq != NULL)
		this->hijoIzq->preOrden();
	if(this->hijoDer != NULL)
		this->hijoDer->preOrden();
	return;
}

//funcion imprime arbol en inOrder (LDR)
template<class T>
void NodoBinario<T>:: inOrden()
{
	if(this->hijoIzq != NULL)
		this->hijoIzq->inOrden();

	cout << "\t"<<this->obtenerDato() << endl;

	if(this->hijoDer != NULL)
		this->hijoDer->inOrden();
	return;

}

//funcion imprime arbol en posOrder (LRD)
template<class T>
void NodoBinario<T>:: posOrden()
{
	if(this->hijoIzq != NULL)
		this->hijoIzq->posOrden();

	if(this->hijoDer != NULL)
		this->hijoDer->posOrden();

	cout << "\t"<<this->obtenerDato() << endl;
	return;

}

//funcion imprime arbol por nivel
template<class T>
void NodoBinario<T>:: nivelOrden()
{
	queue<NodoBinario*> cola;
	cola.push(this);
	while(!cola.empty()){
		cout<<"\t"<<cola.front()->obtenerDato()<<endl;
		if(cola.front()->hijoIzq != NULL){
			cola.push(cola.front()->hijoIzq);
		}

		if(cola.front()->hijoDer != NULL){
			cola.push(cola.front()->hijoDer);
		}
		cola.pop();
	}
}




