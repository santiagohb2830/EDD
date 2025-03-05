#include "arbolBinario.h"

int main() {
    struct node *root = newNode(7);
    root->left = newNode(3);
    root->right = newNode(20);

    root->left->left = newNode(0);
    root->left->right = newNode(5);
    root->left->left->left = newNode(-3);
    root->left->right->left = newNode(1);
    root->right->left = newNode(15);
    root->right->right = newNode(25);
    root->right->right->right = newNode(30);
    root->right->left->right = newNode(6);

    cout << "Preorder traversal:";
    traversePreOrder(root);
    
    cout << "\nInorder traversal:";
    traverseInOrder(root);
    
    cout << "\nPostorder traversal:";
    traversePostOrder(root);
    
    cout << "\n";

    return 0;
}

