/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/
#ifndef KDNODO_H
#define KDNODO_H

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// Declaracion de la clase kdnodo
template<class T>
class kdnodo{
protected:
    vector<T> datos;      // Vector de datos almacenado en el nodo
    int tag;              // Dimension usada para comparacion
    kdnodo<T>* hijoIzq;   // Puntero al hijo izquierdo
    kdnodo<T>* hijoDer;   // Puntero al hijo derecho
    T dato;               // Dato asociado para funciones max/min

public:
    kdnodo();                                   // Constructor

    T& obtenerDato();                           // Retorna el dato asociado
    void fijarDato(vector<T>&);                 // Asigna el vector al nodo
    void fijarTag(int);                         // Asigna el tag de comparacion

    kdnodo<T>* obtenerHijoIzq();                // Retorna hijo izquierdo
    kdnodo<T>* obtenerHijoDer();                // Retorna hijo derecho

    void fijarHijoIzq(kdnodo<T>*);              // Asigna hijo izquierdo
    void fijarHijoDer(kdnodo<T>*);              // Asigna hijo derecho

    int altura();                               // Calcula la altura desde este nodo
    int tamano();                               // Calcula el tamaño desde este nodo

    void insertar(vector<T>&);                  // Inserta un nuevo nodo
    kdnodo<T>* buscar(vector<T>&);              // Busca un nodo
    bool iguales(vector<T>&);                   // Compara dos vectores

    void preOrden();                            // Recorrido preorden
    void inOrden();                             // Recorrido inorden
    void posOrden();                            // Recorrido posorden
    void nivelOrden();                          // Recorrido por niveles

    void maximo(int&);                          // Encuentra el valor maximo
    void minimo(int&);                          // Encuentra el valor minimo

    void imprimir();                            // Imprime el vector de datos
};

#include "kdnodo.hxx"

#endif
