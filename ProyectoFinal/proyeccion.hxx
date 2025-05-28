/****************************************************************
Fecha 27 de Mayo 2025
Autor: Santiago Hernandez, Juan Esteban Bello, Esteban Navas
Materia: Estructuras de Datos
Tema: Modulo 3 del Proyecto
*****************************************************************/

#include "proyeccion.h"
#include <iostream>
#include <numeric>
using namespace std;

// Función para generar una proyección 2D a partir de un volumen de imágenes
imagen proyeccion2D(volumen vol, string direccion, string criterio) {
    imagen resultado;

    // Verificar que el volumen no esté vacío
    if (vol.n_im == 0) {
        cerr << "Error: No hay un volumen cargado en memoria." << endl;
        return resultado; // Retorna una imagen vacía si no hay volumen cargado
    }

    // Validar la dirección (x, y, z)
    if (direccion != "x" && direccion != "y" && direccion != "z") {
        cerr << "Error: Dirección no válida. Use x, y o z." << endl;
        return resultado; // Retorna una imagen vacía si la dirección es inválida
    }

    // Validar el criterio (mínimo, máximo, promedio, mediana)
    if (criterio != "minimo" && criterio != "maximo" && criterio != "promedio" && criterio != "mediana") {
        cerr << "Error: Criterio no válido. Use minimo, maximo, promedio o mediana." << endl;
        return resultado; // Retorna una imagen vacía si el criterio es inválido
    }

    // Inicializar la imagen de resultado con el formato PGM
    resultado.codigo = "P2";  // Formato PGM
    resultado.W = vol.W; // Ancho de la imagen resultante
    resultado.H = vol.H; // Alto de la imagen resultante
    resultado.M = vol.imgv[0].M; // Valor máximo de intensidad (tomado de la primera imagen del volumen)
    resultado.val = vector<vector<int>>(resultado.H, vector<int>(resultado.W, 0)); // Matriz de píxeles inicializada en 0

    // Proyección en la dirección x (columnas)
    if (direccion == "x") {
        for (int y = 0; y < resultado.H; y++) {
            for (int z = 0; z < vol.n_im; z++) {
                vector<int> valores; // Vector para almacenar los valores de los píxeles
                for (int x = 0; x < resultado.W; x++) {
                    valores.push_back(vol.imgv[z].val[y][x]); // Almacenar los valores de la columna x
                }

                // Aplicar el criterio seleccionado
                if (criterio == "minimo") {
                    resultado.val[y][z] = *min_element(valores.begin(), valores.end()); // Mínimo valor
                } else if (criterio == "maximo") {
                    resultado.val[y][z] = *max_element(valores.begin(), valores.end()); // Máximo valor
                } else if (criterio == "promedio") {
                    int suma = accumulate(valores.begin(), valores.end(), 0); // Suma de valores
                    resultado.val[y][z] = suma / valores.size(); // Promedio
                } else if (criterio == "mediana") {
                    sort(valores.begin(), valores.end()); // Ordenar valores
                    resultado.val[y][z] = valores[valores.size() / 2]; // Mediana
                }
            }
        }
    }
    // Proyección en la dirección y (filas)
    else if (direccion == "y") {
        for (int x = 0; x < resultado.W; x++) {
            for (int z = 0; z < vol.n_im; z++) {
                vector<int> valores; // Vector para almacenar los valores de los píxeles
                for (int y = 0; y < resultado.H; y++) {
                    valores.push_back(vol.imgv[z].val[y][x]); // Almacenar los valores de la fila y
                }

                // Aplicar el criterio seleccionado
                if (criterio == "minimo") {
                    resultado.val[z][x] = *min_element(valores.begin(), valores.end()); // Mínimo valor
                } else if (criterio == "maximo") {
                    resultado.val[z][x] = *max_element(valores.begin(), valores.end()); // Máximo valor
                } else if (criterio == "promedio") {
                    int suma = accumulate(valores.begin(), valores.end(), 0); // Suma de valores
                    resultado.val[z][x] = suma / valores.size(); // Promedio
                } else if (criterio == "mediana") {
                    sort(valores.begin(), valores.end()); // Ordenar valores
                    resultado.val[z][x] = valores[valores.size() / 2]; // Mediana
                }
            }
        }
    }
    // Proyección en la dirección z (profundidad)
    else if (direccion == "z") {
        for (int y = 0; y < resultado.H; y++) {
            for (int x = 0; x < resultado.W; x++) {
                vector<int> valores; // Vector para almacenar los valores de los píxeles
                for (int z = 0; z < vol.n_im; z++) {
                    valores.push_back(vol.imgv[z].val[y][x]); // Almacenar los valores de la profundidad z
                }

                // Aplicar el criterio seleccionado
                if (criterio == "minimo") {
                    resultado.val[y][x] = *min_element(valores.begin(), valores.end()); // Mínimo valor
                } else if (criterio == "maximo") {
                    resultado.val[y][x] = *max_element(valores.begin(), valores.end()); // Máximo valor
                } else if (criterio == "promedio") {
                    int suma = accumulate(valores.begin(), valores.end(), 0); // Suma de valores
                    resultado.val[y][x] = suma / valores.size(); // Promedio
                } else if (criterio == "mediana") {
                    sort(valores.begin(), valores.end()); // Ordenar valores
                    resultado.val[y][x] = valores[valores.size() / 2]; // Mediana
                }
            }
        }
    }

    return resultado; // Retornar la imagen resultante de la proyección
}
