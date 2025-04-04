/************************************************
* Fecha 28 de Marzo 2025
* Autor: Santiago Hernandez, Juan Esteban Bello
* Materia: Estructuras de Datos
* Tema: Taller Arboles
************************************************/

#include <bits/stdc++.h>
#include "quadtree.h"

using namespace std;

int main(){
    // Se define el par inicial para la raiz
    pair datop1 = {40,70};

    // Se crea el arbol QuadTree con el nodo raiz inicial
    Arbol<int> arbolito(datop1);

    // Ciclo para insertar 4 pares de coordenadas
    for(int i=0; i<4; i++)
    {
        int dato1, dato2;
        cout<< i << " par de datos:\n";

        // Entrada de coordenadas
        cin >> dato1;
        cin >> dato2;

        // Se emparejan los datos y se insertan en el arbol
        pair datop = {dato1,dato2};
        arbolito.insertar(datop);
    }

    // Muestra el recorrido inorden del arbol
    cout << endl << "Inorden: " << endl;
    arbolito.inOrden();
}
