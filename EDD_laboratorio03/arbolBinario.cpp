#include "arbolBinario.h"

// Nueva creación de nodo
struct node *newNode(int data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Recorrido Preorden
void traversePreOrder(struct node *temp) {
    if (temp != NULL) {
        cout << " " << temp->data;
        traversePreOrder(temp->left);
        traversePreOrder(temp->right);
    }
}

// Recorrido Inorden
void traverseInOrder(struct node *temp) {
    if (temp != NULL) {
        traverseInOrder(temp->left);
        cout << " " << temp->data;
        traverseInOrder(temp->right);
    }
}

// Recorrido Postorden
void traversePostOrder(struct node *temp) {
    if (temp != NULL) {
        traversePostOrder(temp->left);
        traversePostOrder(temp->right);
        cout << " " << temp->data;
    }
}

