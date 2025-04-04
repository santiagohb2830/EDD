/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/

#ifndef NODOEXPRESION_H
#define NODOEXPRESION_H
#include <string.h>
using namespace std;

// Clase que representa un nodo del arbol de expresion
class NodoExpresion{
  protected:
    char dato;               // Almacena el caracter del nodo (operador o digito)
    bool operando;           // Indica si el nodo es un operando (true) o un operador (false)
    NodoExpresion *hijoIzq;  // Puntero al hijo izquierdo
    NodoExpresion *hijoDer;  // Puntero al hijo derecho
  public:
  NodoExpresion();           // Constructor por defecto
  ~NodoExpresion();          // Destructor

  char getDato();            // Retorna el caracter almacenado en el nodo
  void setDato(char val);    // Asigna el valor del caracter al nodo

  void setOperando(bool op); // Define si el nodo es operando o no
  bool getOperando();        // Retorna si el nodo es operando

  NodoExpresion* getHijoIzq(); // Retorna el hijo izquierdo
  NodoExpresion* getHijoDer(); // Retorna el hijo derecho

  void setHijoIzq(NodoExpresion* izq); // Asigna el hijo izquierdo
  void setHijoDer(NodoExpresion* der); // Asigna el hijo derecho
};
#include "NodoExpresion.hxx"

#endif //NODOBINARIO_H
