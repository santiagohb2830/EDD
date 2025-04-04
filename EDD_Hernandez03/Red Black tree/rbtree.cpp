/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/
#include "rbtree.h"

// Constructor del nodo, se inicializa con valor y color rojo
Node::Node(int data) {
    this->data = data;
    left = right = parent = NULL;
    color = RED;
}

// Constructor del arbol, inicia con raiz nula
RBTree::RBTree() {
    root = NULL;
}

// Rotacion hacia la izquierda en el nodo pt
void RBTree::rotateLeft(Node *&root, Node *&pt) {
    Node *pt_right = pt->right;

    pt->right = pt_right->left;
    if (pt->right != NULL)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_right;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

// Rotacion hacia la derecha en el nodo pt
void RBTree::rotateRight(Node *&root, Node *&pt) {
    Node *pt_left = pt->left;

    pt->left = pt_left->right;
    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_left;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

// Insercion tipo arbol binario de busqueda (sin reglas de color)
Node* RBTree::BSTInsert(Node* root, Node* pt) {
    if (root == NULL)
        return pt;

    if (pt->data < root->data) {
        root->left = BSTInsert(root->left, pt);
        root->left->parent = root;
    } else if (pt->data > root->data) {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }

    return root;
}

// Ajusta las violaciones a las reglas del arbol Red-Black despues de insertar un nodo
void RBTree::fixViolation(Node *&root, Node *&pt) {
    Node *parent_pt = NULL;
    Node *grand_parent_pt = NULL;

    while ((pt != root) && (pt->color != BLACK) &&
           (pt->parent->color == RED)) {

        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        // Caso cuando el padre es hijo izquierdo
        if (parent_pt == grand_parent_pt->left) {
            Node *uncle_pt = grand_parent_pt->right;

            // Caso 1: El tio es rojo → recoloreo
            if (uncle_pt != NULL && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                // Caso 2 y 3: rotaciones y recoloreo
                if (pt == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        } else {
            // Caso simetrico cuando el padre es hijo derecho
            Node *uncle_pt = grand_parent_pt->left;

            if ((uncle_pt != NULL) && (uncle_pt->color == RED)) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    // Asegurar que la raiz siempre sea negra
    root->color = BLACK;
}

// Inserta un nodo con el valor dado y aplica balanceo
void RBTree::insert(const int &data) {
    Node *pt = new Node(data);            // Crea el nuevo nodo
    root = BSTInsert(root, pt);           // Inserta como en BST
    fixViolation(root, pt);               // Corrige violaciones Red-Black
}

// Recorrido inorden (izquierda, nodo, derecha)
void RBTree::inorderHelper(Node *root) {
    if (root == NULL) return;

    inorderHelper(root->left);
    cout << root->data << "  ";
    inorderHelper(root->right);
}

// Recorrido por niveles usando una cola
void RBTree::levelOrderHelper(Node *root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        cout << temp->data << "  ";
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

// Llamada externa al recorrido inorden
void RBTree::inorder() {
    inorderHelper(root);
}

// Llamada externa al recorrido por niveles
void RBTree::levelOrder() {
    levelOrderHelper(root);
}
