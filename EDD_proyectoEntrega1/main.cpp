#include <iostream>
#include <sstream>
#include <vector>
#include "imagen.h"
#include "proyeccion.h"

using namespace std;

vector<string> userIn();

int main(int argc, char *argv[]) {	
    imagen img;
    volumen vol;
    string n_img, n_vol;

    while (true) {
        vector<string> comando = userIn();

        if (comando[0] == "exit") {
            cout << "\nsaliendo\n";
            exit(0);
        }
        else if (comando[0] == "cargar_imagen" && comando.size() == 2) {
            img = cargarImg(comando[1]);
            n_img = comando[1];
            cout << "\nse cargo " << comando[1] << " exitosamente\n" << endl;
        }
        else if (comando[0] == "cargar_volumen" && comando.size() == 3) {
            vol = cargarVol(comando[1], stoi(comando[2]));
            n_vol = comando[1];
            cout << "\nse cargo " << comando[1] << " con " << comando[2] << " imagenes exitosamente\n" << endl;
        }
        else if (comando[0] == "info_imagen" && comando.size() == 1) {
            cout << endl << n_img << "\nancho: " << img.W << "\nalto: " << img.H << endl;
        }
        else if (comando[0] == "info_volumen" && comando.size() == 1) {
            cout << endl << n_vol << "\nancho: " << vol.W << "\nalto: " << vol.H << "\ntamaño: " << vol.n_im << endl;
        }
        else if (comando[0] == "proyeccion2D" && comando.size() == 4) {
            if (vol.n_im == 0) {
                cout << "\nEl volumen aún no ha sido cargado en memoria.\n" << endl;
            } else {
                imagen resultado = proyeccion2D(vol, comando[1], comando[2]);
                guardarPGM(resultado, comando[3]);
                cout << "\nLa proyección 2D ha sido generada y almacenada en " << comando[3] << endl << endl;
            }
        }
        else if (comando[0] == "ayuda" && comando.size() == 1) {
            cout << "\n*****comandos*****\n"
                 << "cargar_imagen\n"
                 << "cargar_volumen\n"
                 << "info_imagen\n"
                 << "info_volumen\n"
                 << "proyeccion2D\n"
                 << "codificar_imagen\n"
                 << "decodificar_archivo\n"
                 << "segmentar\n"
                 << "exit\n\n";
        }
        else if (comando[0] == "ayuda" && comando.size() > 1) {
            if (comando[1] == "cargar_imagen")
                cout << "\ncargar_imagen (nombre_imagen)\n\n"
                     << "Carga la imagen con el nombre dado en el sistema\n" << endl;
            else if (comando[1] == "cargar_volumen")
                cout << "\ncargar_volumen (nombre_base) (n_im)\n\n"
                     << "Carga imágenes con el mismo nombre base que estén enumeradas\n"
                     << "en orden ascendente (hasta 99 imágenes) con el nombre: nombrebaseXX\n"
                     << "donde n_im es el número de imágenes del volumen\n" << endl;
            else if (comando[1] == "info_imagen")
                cout << "\ninfo_imagen\n\n"
                     << "Muestra información básica de la imagen cargada\n" << endl;
            else if (comando[1] == "info_volumen")
                cout << "\ninfo_volumen\n\n"
                     << "Muestra información básica del volumen cargado\n" << endl;
            else if (comando[1] == "proyeccion2D")
                cout << "\nproyeccion2D (direccion) (criterio) (nombre_archivo.pgm)\n\n"
                     << "Genera la imagen basándose en la dirección que puede ser:\n"
                     << "x (columnas), y (filas) o z (profundidad).\n"
                     << "El criterio puede ser: mínimo, máximo, promedio o mediana.\n" << endl;
            else if (comando[1] == "codificar_imagen")
                cout << "\ncodificar_imagen (nombre_archivo.huf)\n\n"
                     << "Se codifica y guarda la imagen en un archivo de nombre: nombre_archivo\n" << endl;
            else if (comando[1] == "decodificar_archivo")
                cout << "\ndecodificar_archivo (nombre_archivo.huf) (nombre_imagen.pgm)\n\n"
                     << "Se decodifica un archivo de nombre: nombre_archivo y se crea una imagen\n"
                     << "de nombre: nombre_imagen\n" << endl;
            else if (comando[1] == "segmentar")
                cout << "\nsegmentar (salida_imagen.pgm) (sx1) (sy1) (sl1) ... (sx5) (sy5) (sl5)\n\n"
                     << "Se segmenta la imagen cargada utilizando el algoritmo Dijkstra\n"
                     << "con hasta cinco semillas en formato: [x y] [valor], donde [x y]\n"
                     << "representa la posición de un píxel y [valor] es un número entre 0 y 255\n"
                     << "que representa el color esperado en esa coordenada.\n" << endl;
            else
                cout << "\ncomando inexistente\n" << endl;
        }
        else {
            cout << "\ncomando invalido\n" << endl;
        }
    }
    return 0;
}

// Función para obtener la entrada del usuario
vector<string> userIn() {
    string in;
    cout << "$ ";
    getline(cin, in);
    stringstream ss(in);
    vector<string> comando;
    while (ss >> in) {
        comando.push_back(in);
    }
    return comando;
}
