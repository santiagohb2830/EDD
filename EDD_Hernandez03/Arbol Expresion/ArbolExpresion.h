/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/

#ifndef ARBOLEXPRESION_H
#define  ARBOLEXPRESION_H
#include "NodoExpresion.h"
#include <string>
using namespace std;

// Clase que representa un arbol de expresion
class ArbolExpresion {
  protected:
    NodoExpresion* raiz; // Puntero a la raiz del arbol
public:
    ArbolExpresion();    // Constructor
    ~ArbolExpresion();   // Destructor

    NodoExpresion* getRaiz();                   // Retorna la raiz del arbol
    void setRaiz(NodoExpresion* nod);           // Asigna la raiz del arbol

    void llenarDesdePrefija(string &expresion); // Construye el arbol a partir de una expresion prefija
    void llenarDesdePosfija(string &expresion); // Construye el arbol a partir de una expresion posfija

    void obtenerPrefija(NodoExpresion* inicio); // Imprime la expresion en notacion prefija
    void obtenerInfija(NodoExpresion* inicio);  // Imprime la expresion en notacion infija
    void obtenerPosfija(NodoExpresion* inicio); // Imprime la expresion en notacion posfija

    int evaluar(NodoExpresion* nodi);           // Evalua el resultado numerico del arbol de expresion
    bool siOperando(char car);                  // Verifica si el caracter es un operando
};
#include "ArbolExpresion.hxx"

#endif
