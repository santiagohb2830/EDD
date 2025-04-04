/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/
#ifndef NODO_BINARIO_H
#define NODO_BINARIO_H

// TAD NodoBinario: representa un nodo con un dato entero y dos hijos

class NodoBinario {
private:
    int dato; // Valor almacenado en el nodo
    NodoBinario* hijoIzq; // Puntero al hijo izquierdo
    NodoBinario* hijoDer; // Puntero al hijo derecho

public:
    NodoBinario(); // Constructor por defecto
    NodoBinario(int); // Constructor con dato inicial
    int obtenerDato(); // Retorna el dato del nodo
    void fijarDato(int); // Asigna un nuevo dato
    NodoBinario* obtenerHijoIzquierdo(); // Retorna el hijo izquierdo
    NodoBinario* obtenerHijoDerecho(); // Retorna el hijo derecho
    void fijarHijoIzquierdo(NodoBinario*); // Asigna el hijo izquierdo
    void fijarHijoDerecho(NodoBinario*); // Asigna el hijo derecho
};

#endif

