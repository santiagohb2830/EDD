/**********************************
Fecha: 11 de Febrero 2025
Autores: Santiago Hernandez, Juan Esteban, Esteban Navas
Materia: Estructuras de Datos
Tema: Primera entrega del proyecto
***********************************/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Funcion que convierte la entrada del usuario (string) en un vector de strings con los comandos separados
vector<string> userIn() {
    string in;  // Variable que almacena la entrada del usuario
    cout << "$ ";  // Se muestra el prompt de la linea de comandos
    getline(cin, in);  // Se captura la linea completa de entrada del usuario

    stringstream ss(in);  // Se usa stringstream para separar los elementos de la entrada
    vector<string> comando;  // Vector para almacenar los comandos separados

    // Separa la entrada en palabras y las almacena en el vector
    while (ss >> in) {
        comando.push_back(in);
    }

    return comando;  // Retorna el vector con los comandos ingresados
}

int main(int argc, char *argv[]) {
    // Bucle infinito para mantener la ejecucion del programa hasta que el usuario decida salir
    while (true) {
        // Captura la entrada del usuario y la convierte en un vector de strings
        vector<string> comando = userIn();

        // Comando para salir del programa
        if (comando[0] == "exit") {
            cout << "\nSaliendo del sistema...\n";
            exit(0);
        }
        // Comando para cargar una imagen individual
        else if (comando[0] == "cargar_imagen" && comando.size() == 2) {
            cout << "\nSe cargo " << comando[1] << " exitosamente\n" << endl;
        }
        // Comando para cargar un volumen de imagenes
        else if (comando[0] == "cargar_volumen" && comando.size() == 3) {
            cout << "\nSe cargo " << comando[1] << " con " << comando[2] << " imagenes exitosamente\n" << endl;
        }
        // Comando para mostrar informacion de la imagen cargada
        else if (comando[0] == "info_imagen" && comando.size() == 1) {
            cout << "\nInformacion de la imagen cargada\n" << endl;
        }
        // Comando para realizar la proyeccion 2D de un volumen de imagenes
        else if (comando[0] == "proyeccion2D" && comando.size() == 4) {
            cout << "\nSe genero la proyeccion " << comando[3] << "\nDireccion: " << comando[1]
                 << "\nCriterio: " << comando[2] << endl << endl;
        }
        // Comando para codificar y guardar una imagen en formato comprimido
        else if (comando[0] == "codificar_imagen" && comando.size() == 2) {
            cout << "\nSe guardo la imagen " << comando[1] << " exitosamente\n" << endl;
        }
        // Comando para decodificar un archivo y generar una imagen
        else if (comando[0] == "decodificar_archivo" && comando.size() == 3) {
            cout << "\nSe decodifico " << comando[1] << " y se creo " << comando[2] << " exitosamente\n" << endl;
        }
        // Comando para segmentar una imagen en base a semillas
        else if (comando[0] == "segmentar" && comando.size() > 3) {
            cout << "\nSe segmento " << comando[1] << " con las semillas: " << comando[2] << endl << endl;
        }
        // Comando de ayuda general
        else if (comando[0] == "ayuda" && comando.size() == 1) {
            cout << "\n***** Comandos disponibles *****\n"
                 << "cargar_imagen\n"
                 << "cargar_volumen\n"
                 << "info_imagen\n"
                 << "proyeccion2D\n"
                 << "codificar_imagen\n"
                 << "decodificar_archivo\n"
                 << "segmentar\n"
                 << "exit\n\n";
        }
        // Comando de ayuda especifica para cada funcionalidad
        else if (comando[0] == "ayuda" && comando.size() > 1) {
            if (comando[1] == "cargar_imagen")
                cout << "\ncargar_imagen (nombre_imagen)\n\nCarga la imagen con el nombre dado en el sistema.\n" << endl;
            else if (comando[1] == "cargar_volumen")
                cout << "\ncargar_volumen (nombre_base) (n_im)\n\nCarga imagenes con el mismo nombre base y las enumera en orden ascendente.\n" << endl;
            else if (comando[1] == "info_imagen")
                cout << "\ninfo_imagen\n\nMuestra informacion basica de la imagen cargada.\n" << endl;
            else if (comando[1] == "proyeccion2D")
                cout << "\nproyeccion2D (direccion) (criterio) (nombre_archivo.pgm)\n\nGenera la imagen proyectada en la direccion y criterio especificados.\n" << endl;
            else if (comando[1] == "codificar_imagen")
                cout << "\ncodificar_imagen (nombre_archivo.huf)\n\nCodifica la imagen y la guarda en un archivo comprimido.\n" << endl;
            else if (comando[1] == "decodificar_archivo")
                cout << "\ndecodificar_archivo (nombre_archivo.huf) (nombre_imagen.pgm)\n\nDecodifica un archivo y genera una imagen en formato PGM.\n" << endl;
            else if (comando[1] == "segmentar")
                cout << "\nsegmentar (salida_imagen.pgm) (sx1 sy1 sl1) ... (sx5 sy5 sl5)\n\nSegmenta la imagen con semillas y genera una imagen segmentada.\n" << endl;
            else
                cout << "\nComando inexistente.\n" << endl;
        }
        // Mensaje de error si el comando ingresado no es valido
        else {
            cout << "\nComando invalido.\n" << endl;
        }
    }
}
