/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/
#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include <queue>
using namespace std;

// Enumeracion de colores para los nodos
enum Color { RED, BLACK };

// Estructura de un nodo del arbol Red-Black
struct Node {
    int data;          // Valor del nodo
    bool color;        // Color del nodo (RED o BLACK)
    Node *left, *right, *parent; // Punteros a hijos y padre

    Node(int data);    // Constructor del nodo
};

// Clase que representa el arbol Red-Black
class RBTree {
private:
    Node* root; // Puntero a la raiz del arbol

    // Metodos auxiliares para rotaciones y ajustes
    void rotateLeft(Node*&, Node*&);
    void rotateRight(Node*&, Node*&);
    void fixViolation(Node*&, Node*&);
    void inorderHelper(Node* root);
    void levelOrderHelper(Node* root);
    Node* BSTInsert(Node* root, Node* pt); // Insercion tipo BST (sin reglas de color)

public:
    RBTree(); // Constructor del arbol
    void insert(const int &n); // Inserta un nuevo valor en el arbol
    void inorder();            // Recorrido inorden
    void levelOrder();         // Recorrido por niveles
};

#endif


