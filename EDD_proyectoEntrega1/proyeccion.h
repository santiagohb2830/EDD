/**********************************
Fecha 5 de Marzo 2025
Autor: Santiago Hernandez, Juan Esteban, Esteban Navas
Materia: Estructuras de Datos
Tema: Primera entrega Proyecto
***********************************/
#ifndef PROYECCION_H
#define PROYECCION_H

#include "imagen.h" // Incluir la definición de la estructura imagen y volumen
#include <algorithm> // Incluir la librería para usar funciones como min_element, max_element, etc.

// Declaración de la función para generar una proyección 2D
imagen proyeccion2D(volumen vol, string direccion, string criterio);

#endif // PROYECCION_H
