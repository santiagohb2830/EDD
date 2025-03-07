/**********************************
Fecha 5 de Marzo 2025
Autor: Santiago Hernandez
Materia: Estructuras de Datos
Tema: Laboratorio en clase
***********************************/
#include "arbolBinario.h"

// Nueva creación de nodo
struct node *newNode(int data) {
    struct node *node = (struct node *)malloc(sizeof(struct node)); // Asignar memoria para el nodo
    node->data = data;  // Asignar el dato al nodo
    node->left = NULL;   // Inicializar el hijo izquierdo como NULL
    node->right = NULL;  // Inicializar el hijo derecho como NULL
    return node;         // Retornar el nodo creado
}

// Recorrido Preorden
void traversePreOrder(struct node *temp) {
    if (temp != NULL) {
        cout << " " << temp->data;  // Imprimir el dato del nodo actual
        traversePreOrder(temp->left);  // Recorrer el hijo izquierdo
        traversePreOrder(temp->right); // Recorrer el hijo derecho
    }
}

// Recorrido Inorden
void traverseInOrder(struct node *temp) {
    if (temp != NULL) {
        traverseInOrder(temp->left);  // Recorrer el hijo izquierdo
        cout << " " << temp->data;  // Imprimir el dato del nodo actual
        traverseInOrder(temp->right); // Recorrer el hijo derecho
    }
}

// Recorrido Postorden
void traversePostOrder(struct node *temp) {
    if (temp != NULL) {
        traversePostOrder(temp->left);  // Recorrer el hijo izquierdo
        traversePostOrder(temp->right); // Recorrer el hijo derecho
        cout << " " << temp->data;  // Imprimir el dato del nodo actual
    }
}

