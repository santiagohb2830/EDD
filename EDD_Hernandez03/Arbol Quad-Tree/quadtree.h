/************************************************
* Fecha 28 de Marzo 2025
* Autor: Santiago Hernandez, Juan Esteban Bello
* Materia: Estructuras de Datos
* Tema: Taller Arboles
************************************************/

#ifndef __QUADTREE__H__
#define __QUADTREE__H__

#include "nodo.h"

using namespace std;

// Declaracion de la clase Arbol tipo QuadTree
template<class T>
class Arbol {
  protected:
    Nodo<T> *raiz; // Puntero a la raiz del arbol

  public:
    Arbol(); // Constructor por defecto
    Arbol(pair<T,T> val); // Constructor con valor inicial para la raiz

    bool esVacio(); // Verifica si el arbol esta vacio
    pair<T,T> obtenerRaiz(); // Retorna el valor almacenado en la raiz
    void fijarRaiz(Nodo<T>* root); // Fija la raiz a un nuevo nodo

    void insertar(pair<T,T> val); // Inserta un par de coordenadas al arbol

    int altura(); // Calcula la altura del arbol
    int tamano(); // Retorna el numero de nodos del arbol

    void insertar(T& val); // Metodo no implementado para insertar un T directo
    bool eliminar(T& val); // Metodo no implementado para eliminar un T directo

    Nodo<T>* buscar(pair<T,T> val); // Busca un nodo con el par de datos

    void inOrden();  // Recorre el arbol en inorden
    void preOrden(); // Recorre el arbol en preorden
    void posOrden(); // Recorre el arbol en posorden
};

#include "quadtree.hxx"
#endif
