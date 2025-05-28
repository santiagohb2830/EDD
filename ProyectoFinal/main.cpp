/****************************************************************
Fecha 27 de Mayo 2025
Autor: Santiago Hernandez, Juan Esteban Bello, Esteban Navas
Materia: Estructuras de Datos
Tema: Modulo 3 del Proyecto
*****************************************************************/

#include <iostream>
#include <sstream>
#include <vector>
#include "imagen.h"
#include "proyeccion.h"
#include "huffman.h"
#include "dijkstra.h"

using namespace std;

// Declaración de la función para obtener la entrada del usuario
vector<string> userIn();

int main(int argc, char *argv[]) {    
    imagen img; // Variable para almacenar una imagen
    volumen vol; // Variable para almacenar un volumen de imágenes
    string n_img, n_vol; // Variables para almacenar los nombres de la imagen y el volumen cargados

    // ========= Mensaje de bienvenida mejorado =========
    cout << "=====================================================\n";
    cout << ":'######:::'########::'######::'########::'#######::'########:::::'####:'##::::'##::::'###:::::'######:::'########:'##::: ##:'########::'######::   \n";
    cout << "'##... ##:: ##.....::'##... ##:... ##..::'##.... ##: ##.... ##::::. ##:: ###::'###:::'## ##:::'##... ##:: ##.....:: ###:: ##: ##.....::'##... ##:   \n";        
    cout << " ##:::..::: ##::::::: ##:::..::::: ##:::: ##:::: ##: ##:::: ##::::: ##:: ####'####::'##:. ##:: ##:::..::: ##::::::: ####: ##: ##::::::: ##:::..::   \n";
    cout << " ##::'####: ######:::. ######::::: ##:::: ##:::: ##: ########:::::: ##:: ## ### ##:'##:::. ##: ##::'####: ######::: ## ## ##: ######:::. ######::   \n";
    cout << " ##::: ##:: ##...:::::..... ##:::: ##:::: ##:::: ##: ##.. ##::::::: ##:: ##. #: ##: #########: ##::: ##:: ##...:::: ##. ####: ##...:::::..... ##:   \n";
    cout << " ##::: ##:: ##:::::::'##::: ##:::: ##:::: ##:::: ##: ##::. ##:::::: ##:: ##:.:: ##: ##.... ##: ##::: ##:: ##::::::: ##:. ###: ##:::::::'##::: ##:   \n";
    cout << ". ######::: ########:. ######::::: ##::::. #######:: ##:::. ##::::'####: ##:::: ##: ##:::: ##:. ######::: ########: ##::. ##: ########:. ######::   \n";        
    cout << ":......::::........:::......::::::..::::::.......:::..:::::..:::::....::..:::::..::..:::::..:::......::::........::..::::..::........:::......:::   \n";
    cout << "               GESTOR DE IMÁGENES                         \n";
    cout << "=====================================================\n";
    cout << "\nBienvenido al programa.\n";
    cout << "Use el comando (ayuda) para ver los comandos disponibles.\n";
    cout << "Si desea información específica de un comando, escriba:\n";
    cout << "ayuda <nombre_comando>\n";
    cout << "Por ejemplo: ayuda cargar_volumen\n\n";


    // ===================================================

    while (true) {
        // Obtener el comando del usuario
        vector<string> comando = userIn();

        if (comando[0] == "salir") {
            cout << "\nSaliendo del programa...\n";
            exit(0);
        }
        else if (comando[0] == "cargar_imagen" && comando.size() == 2) {
            img = cargarImg(comando[1]);
            n_img = comando[1];
        }
        else if (comando[0] == "cargar_volumen" && comando.size() == 3) {
            vol = cargarVol(comando[1], stoi(comando[2]));
            n_vol = comando[1];
        }
        else if (comando[0] == "info_imagen" && comando.size() == 1) {
            cout << "\nInformación de la imagen cargada:\n";
            cout << "- Nombre: " << n_img << "\n";
            cout << "- Ancho : " << img.W << "\n";
            cout << "- Alto  : " << img.H << "\n";
        }
        else if (comando[0] == "info_volumen" && comando.size() == 1) {
            cout << "\nInformación del volumen cargado:\n";
            cout << "- Nombre base: " << n_vol << "\n";
            cout << "- Ancho       : " << vol.W << "\n";
            cout << "- Alto        : " << vol.H << "\n";
            cout << "- Número de imágenes: " << vol.n_im << "\n";
        }
        else if (comando[0] == "proyeccion2D" && comando.size() == 4) {
            if (vol.n_im == 0) {
                cout << "\nError: El volumen aún no ha sido cargado en memoria.\n";
            } else {
                imagen resultado = proyeccion2D(vol, comando[1], comando[2]);
                guardarPGM(resultado, comando[3]);
                cout << "\nProyección 2D generada exitosamente y almacenada como " << comando[3] << "\n";
            }
        }
        else if (comando[0] == "codificar_imagen" && comando.size() == 2) {
            if (img.val.empty()) {
                cout << "\nError: No hay una imagen en memoria.\n";
            } else {
                codificar_img(img, comando[1]);
                cout << "\nLa imagen ha sido comprimida y almacenada como " << comando[1] << "\n";
            }
        }
        else if (comando[0] == "decodificar_archivo" && comando.size() == 3) {
            decodificar_img(comando[1], comando[2]);
            
        }
	    else if (comando[0] == "segmentar" && comando.size() >= 5 && comando.size() <= 17){
            if (img.val.empty()) {
                cout << "\nError: No hay una imagen en memoria.\n";
            } else {
            vector<string> semillas;
            semillas.assign(comando.begin()+2,comando.end());
            segmentar(img,comando[1],semillas);
            }
	    }

        else if (comando[0] == "ayuda" && comando.size() == 1) {
            cout << "\n========== LISTA DE COMANDOS ==========\n";
            cout << "- cargar_imagen <nombre_imagen>\n";
            cout << "- cargar_volumen <nombre_base> <numero_imagenes>\n";
            cout << "- info_imagen\n";
            cout << "- info_volumen\n";
            cout << "- proyeccion2D <direccion> <criterio> <nombre_salida>\n";
            cout << "- codificar_imagen <nombre_salida.huf>\n";
            cout << "- decodificar_archivo <archivo.huf> <nombre_imagen_salida>\n";
            cout << "- segmentar <salida_imagen> <semillas>\n";
            cout << "- salir\n";
            cout << "=======================================\n";
            cout << "Use 'ayuda <comando>' para obtener información detallada.\n";
        }
        else if (comando[0] == "ayuda" && comando.size() > 1) {
            if (comando[1] == "cargar_imagen")
                cout << "\n(cargar_imagen <nombre_imagen>)\nCarga una imagen en el sistema.\n";
            else if (comando[1] == "cargar_volumen")
                cout << "\n(cargar_volumen <nombre_base> <n_im>)\nCarga un conjunto de imágenes como un volumen.\n";
            else if (comando[1] == "info_imagen")
                cout << "\n(info_imagen)\nMuestra la información de la imagen cargada.\n";
            else if (comando[1] == "info_volumen")
                cout << "\n(info_volumen)\nMuestra la información del volumen cargado.\n";
            else if (comando[1] == "proyeccion2D")
                cout << "\n(proyeccion2D <direccion> <criterio> <nombre_archivo>)\nGenera una proyección 2D basada en la dirección (x, y, z) y el criterio (mínimo, máximo, promedio, mediana).\n";
            else if (comando[1] == "codificar_imagen")
                cout << "\n(codificar_imagen <nombre_archivo.huf>)\nCodifica la imagen cargada usando Huffman.\n";
            else if (comando[1] == "decodificar_archivo")
                cout << "\n(decodificar_archivo <nombre_archivo.huf> <nombre_imagen.pgm>)\nDecodifica un archivo comprimido y recupera una imagen.\n";
            else if (comando[1] == "segmentar")
                cout << "\n(segmentar <nombre_salida> <semillas>)\nSegmenta una imagen usando hasta cinco semillas (x, y, valor).\n";
            else
                cout << "\nError: Comando inexistente.\n";
        }
        else {
            cout << "\nError: Comando inválido.\n";
        }
    }
    return 0;
}

vector<string> userIn() {
    string in;
    do{
    cout << "$ ";
    getline(cin, in);} while (in.empty());
    stringstream ss(in);
    vector<string> comando;
    while (ss >> in) {
        comando.push_back(in);
    }
    return comando;
}
