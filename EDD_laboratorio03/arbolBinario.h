/**********************************
Fecha 5 de Marzo 2025
Autor: Santiago Hernandez, Juan Esteban, Esteban Navas
Materia: Estructuras de Datos
Tema: Primera entrega Proyecto
***********************************/
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Prototipos de funciones
struct node *newNode(int data);
void traversePreOrder(struct node *temp);
void traverseInOrder(struct node *temp);
void traversePostOrder(struct node *temp);

#endif // ARBOLBINARIO_H

