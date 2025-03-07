/**********************************
Fecha 5 de Marzo 2025
Autor: Santiago Hernandez, Juan Esteban, Esteban Navas
Materia: Estructuras de Datos
Tema: Primera entrega Proyecto
***********************************/
#ifndef IMAGEN_H
#define IMAGEN_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// Estructura que representa una imagen
struct imagen {
    string codigo; // Código del formato de la imagen (P2 para PGM, P3 para PPM)
    int W; // Ancho de la imagen (número de columnas)
    int H; // Alto de la imagen (número de filas)
    int M; // Valor máximo de intensidad de los píxeles
    vector<vector<int>> val; // Matriz de valores de intensidad en escala de grises
};

// Estructura que representa un volumen de imágenes
struct volumen {
    int W; // Ancho común de todas las imágenes en el volumen
    int H; // Alto común de todas las imágenes en el volumen
    int n_im; // Número de imágenes en el volumen
    vector<imagen> imgv; // Vector que almacena las imágenes del volumen
};

// Declaraciones de funciones

// Función para cargar una imagen en formato PGM
imagen cargarImg(string nombre);

// Función para cargar una imagen en formato PPM y convertirla a escala de grises
imagen cargarPPM(string nombre);

// Función para cargar un volumen de imágenes PPM
volumen cargarVol(string nombre_base, int n);

// Función para guardar una imagen en formato PGM
void guardarPGM(imagen img, string nombre_archivo);

#endif // IMAGEN_H
