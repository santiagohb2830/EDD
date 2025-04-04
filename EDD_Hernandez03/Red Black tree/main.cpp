/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/
#include "rbtree.h"

int main() {
    RBTree tree; // Se crea una instancia del arbol Red-Black

    // Insercion de valores en el arbol
    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);

    // Se imprime el recorrido inorden (de menor a mayor)
    cout << "Inorder Traversal of Created Tree\n";
    tree.inorder();

    // Se imprime el recorrido por niveles (estructura del arbol)
    cout << "\n\nLevel Order Traversal of Created Tree\n";
    tree.levelOrder();
    cout << "\n";

    return 0;
}
