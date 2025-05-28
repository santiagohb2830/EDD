/****************************************************************
Fecha 27 de Mayo 2025
Autor: Santiago Hernandez, Juan Esteban Bello, Esteban Navas
Materia: Estructuras de Datos
Tema: Modulo 3 del Proyecto
*****************************************************************/
#include "imagen.h"
#include <iostream>

using namespace std;

// Función para convertir una imagen PPM a escala de grises
imagen cargarPPM(string nombre) {
    imagen img;
    string temp;
    ifstream archivo(nombre);

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << nombre << endl;
        return img; // Retorna una imagen vacía en caso de error
    }

    // Leer el código del formato PPM (debe ser "P3" para un archivo PPM)
    getline(archivo, img.codigo);

    // Ignorar comentarios en el archivo (comienzan con '#')
    archivo >> temp;
    while (temp[0] == '#') {
        getline(archivo, temp); // Leer y descartar la línea de comentario
        archivo >> temp; // Leer el siguiente valor
    }

    // Leer el ancho (W), alto (H) y valor máximo (M) de la imagen
    img.W = stoi(temp); // Convertir el ancho a entero
    archivo >> img.H; // Leer el alto
    archivo >> img.M; // Leer el valor máximo de los píxeles

    // Leer los valores de los píxeles (RGB) y convertirlos a escala de grises
    for (int i = 0; i < img.H; i++) {
        img.val.emplace_back(vector<int>()); // Crear una nueva fila de píxeles
        for (int j = 0; j < img.W; j++) {
            int r, g, b;
            archivo >> r >> g >> b; // Leer los valores de rojo, verde y azul
            // Convertir RGB a escala de grises usando el método de luminosidad
            int gris = static_cast<int>(0.299 * r + 0.587 * g + 0.114 * b);
            img.val[i].push_back(gris); // Agregar el valor de gris a la fila actual
        }
    }

    archivo.close(); // Cerrar el archivo después de leerlo
    return img; // Retornar la imagen cargada y convertida a escala de grises
}

// Función para cargar una imagen en formato PGM
imagen cargarImg(string nombre) {
    imagen img;
    string temp;
    ifstream archivo(nombre);

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << nombre << endl;
        return img; // Retorna una imagen vacía en caso de error
    }

    // Leer el código del formato PGM (debe ser "P2" para un archivo PGM)
    getline(archivo, img.codigo);

    // Ignorar comentarios en el archivo (comienzan con '#')
    archivo >> temp;
    while (temp[0] == '#') {
        getline(archivo, temp); // Leer y descartar la línea de comentario
        archivo >> temp; // Leer el siguiente valor
    }

    // Leer el ancho (W), alto (H) y valor máximo (M) de la imagen
    img.W = stoi(temp); // Convertir el ancho a entero
    archivo >> img.H; // Leer el alto
    archivo >> img.M; // Leer el valor máximo de los píxeles

    // Leer los valores de los píxeles (ya en escala de grises)
    for (int i = 0; i < img.H; i++) {
        img.val.emplace_back(vector<int>()); // Crear una nueva fila de píxeles
        for (int j = 0; j < img.W; j++) {
            archivo >> temp; // Leer el valor del píxel
            img.val[i].push_back(stoi(temp)); // Convertir a entero y agregar a la fila
        }
    }

    archivo.close(); // Cerrar el archivo después de leerlo
    cout<<"se cargo la imagen"<< nombre << " correctamente\n";
    return img; // Retornar la imagen cargada
}

// Función para cargar un volumen de imágenes PPM
volumen cargarVol(string nombre_base, int n) {
    volumen vol;
    if (n > 99) {
        cerr << "Error: El número de imágenes no puede ser mayor a 99." << endl;
        return vol; // Retornar un volumen vacío si el número de imágenes es inválido
    }
    vol.n_im = n; // Establecer el número de imágenes en el volumen
    bool error = false;

    // Cargar cada imagen en el volumen
    for (int i = 1; i <= n; i++) {
        // Generar el nombre correcto: "nombre_baseXX.ppm" (donde XX es el número de la imagen)
        string numero = (i < 10) ? "0" + to_string(i) : to_string(i);
        string nombre = nombre_base + numero + ".ppm"; // Sin guiones extras

        // Cargar la imagen PPM
        imagen img = cargarPPM(nombre);

        // Verificar si la imagen se cargó correctamente
        if (img.val.empty()) {
            cerr << "Error: No se pudo cargar la imagen " << nombre << endl;
            error = true;
            break; // Salir del bucle si hay un error
        }

        // Verificar que todas las imágenes tengan el mismo tamaño
        if (i == 1) {
            vol.W = img.W; // Establecer el ancho del volumen
            vol.H = img.H; // Establecer el alto del volumen
        } else if (img.W != vol.W || img.H != vol.H) {
            cerr << "Error: Las imágenes no tienen el mismo tamaño." << endl;
            error = true;
            break; // Salir del bucle si las imágenes no coinciden en tamaño
        }

        vol.imgv.push_back(img); // Agregar la imagen al volumen
    }

    // Manejar errores en la carga del volumen
    if (error) {
        vol.imgv.clear(); // Limpiar el volumen si hubo un error
        vol.n_im = 0;
        vol.W = 0;
        vol.H = 0;
        cout << "El volumen no pudo cargarse completamente." << endl;
    } else {
        cout << "\nSe cargó " << nombre_base << " con " << n << " imágenes exitosamente\n" << endl;
    }

    return vol; // Retornar el volumen cargado
}

// Función para guardar una imagen en formato PGM
void guardarPGM(imagen img, string nombre_archivo) {
    ofstream archivo(nombre_archivo);

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo crear el archivo " << nombre_archivo << endl;
        return; // Salir de la función si no se puede crear el archivo
    }

    // Escribir el archivo PGM
    archivo << "P2" << endl; // Formato PGM
    archivo << img.W << " " << img.H << endl; // Escribir ancho y alto
    archivo << img.M << endl; // Escribir el valor máximo de los píxeles

    // Escribir los valores de los píxeles
    for (int i = 0; i < img.H; i++) {
        for (int j = 0; j < img.W; j++) {
            archivo << img.val[i][j] << " "; // Escribir el valor del píxel
        }
        archivo << endl; // Nueva línea después de cada fila de píxeles
    }

    archivo.close(); // Cerrar el archivo después de escribirlo
}
