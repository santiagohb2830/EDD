/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/

#ifndef __KDTREE__H__
#define __KDTREE__H__

#include "kdnodo.h"			//correccion libreria
#include <vector>			//inclucion de libreria vector
using namespace std;

// Declaracion de la clase kdtree
template<class T>
class kdtree{
protected:
    kdnodo<T>* raiz;  // Puntero a la raiz del arbol

public:
    kdtree();                       // Constructor
    bool esVacio();                // Verifica si el arbol esta vacio
    T& datoRaiz();                 // Retorna el dato de la raiz
    int altura();                  // Calcula la altura del arbol
    int tamano();                  // Calcula el numero total de nodos

    void insertar(vector<T>&);     // Inserta un nuevo nodo con un vector
    bool eliminar(T&);             // Elimina un nodo (no implementado)
    kdnodo<T>* buscar(T&);         // Busca un nodo a partir de un vector

    void preOrden();               // Recorrido preorden
    void inOrden();                // Recorrido inorden
    void posOrden();              // Recorrido posorden
    void nivelOrden();            // Recorrido por niveles

    void maximo(int&);            // Encuentra el valor maximo
    void minimo(int&);            // Encuentra el valor minimo
};

#include "kdtree.hxx"

#endif
