/**********************************
Fecha 5 de Marzo 2025
Autor: Santiago Hernandez, Juan Esteban, Esteban Navas
Materia: Estructuras de Datos
Tema: Primera entrega Proyecto
***********************************/
#include "arbolBinario.h"

int main() {
    // Crear el árbol con la estructura de la imagen
    struct node *root = newNode(7);  // Nodo raíz con valor 7
    root->left = newNode(3);         // Hijo izquierdo con valor 3
    root->right = newNode(20);       // Hijo derecho con valor 20

    // Agregar nodos en la rama izquierda
    root->left->left = newNode(0);   // Hijo izquierdo de 3 es 0
    root->left->right = newNode(5);  // Hijo derecho de 3 es 5
    root->left->left->left = newNode(-3); // Hijo izquierdo de 0 es -3
    root->left->right->left = newNode(1); // Hijo izquierdo de 5 es 1

    // Agregar nodos en la rama derecha
    root->right->left = newNode(15);  // Hijo izquierdo de 20 es 15
    root->right->right = newNode(25); // Hijo derecho de 20 es 25
    root->right->right->right = newNode(30); // Hijo derecho de 25 es 30
    root->right->left->right = newNode(6);   // Hijo derecho de 15 es 6

    // Imprimir los recorridos del árbol
    cout << "Preorder traversal:";
    traversePreOrder(root);

    cout << "\nInorder traversal:";
    traverseInOrder(root);

    cout << "\nPostorder traversal:";
    traversePostOrder(root);

    cout << "\n";

    return 0;
}

