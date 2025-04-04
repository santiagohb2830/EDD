/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/
#include <iostream>
#include "NodoBinario.h"
#include "ArbolBinario.h"
#include "NodoBinario.hxx"
#include "ArbolBinario.hxx"

using namespace std;

int main() {
    // Se crea un arbol binario
    ArbolBinario arbol;

    // Insercion de valores (CORREGIDO: llamados directos a insertar)
    arbol.insertar(10);
    arbol.insertar(5);
    arbol.insertar(15);
    arbol.insertar(2);
    arbol.insertar(7);
    arbol.insertar(12);
    arbol.insertar(20);

    // Recorrido inorden (debe imprimir en orden creciente)
    cout << "Recorrido inorden: ";
    arbol.inOrden(arbol.obtenerRaiz());
    cout << endl;

    // Recorrido preorden
    cout << "Recorrido preorden: ";
    arbol.preOrden(arbol.obtenerRaiz());
    cout << endl;

    // Recorrido posorden
    cout << "Recorrido posorden: ";
    arbol.posOrden(arbol.obtenerRaiz());
    cout << endl;

    return 0;
}

