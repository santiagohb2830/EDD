/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/
#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

#include "NodoBinario.h"

// TAD ArbolBinario: representa un arbol binario de busqueda

class ArbolBinario {
private:
    NodoBinario* raiz; // Nodo raiz del arbol

public:
    ArbolBinario(); // Constructor
    NodoBinario* obtenerRaiz(); // Retorna la raiz
    void insertar(int); // Inserta un nuevo valor
    void inOrden(NodoBinario*); // Recorrido inorden
    void preOrden(NodoBinario*); // Recorrido preorden
    void posOrden(NodoBinario*); // Recorrido posorden
};

#endif

