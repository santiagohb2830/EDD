#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;

// ======================= TAD Palabra =======================
class Palabra {
private:
    string palabra;
    unsigned int n_linea;

public:
    // Constructor
    Palabra(string n_palabra = "", unsigned int n_num = 0) 
        : palabra(n_palabra), n_linea(n_num) {}

    // FijarPalabra: Cambia la palabra actual
    void FijarPalabra(string n_palabra) {
        palabra = n_palabra;
    }

    // FijarNumLinea: Cambia el número de línea actual
    void FijarNumLinea(unsigned int n_num) {
        n_linea = n_num;
    }

    // ObtenerPalabra: Retorna la palabra almacenada
    string ObtenerPalabra() const {
        return palabra;
    }

    // ObtenerNumLinea: Retorna el número de línea
    unsigned int ObtenerNumLinea() const {
        return n_linea;
    }
};

// ===================== TAD ArchivoTexto ====================
class ArchivoTexto {
private:
    vector<string> lineasTexto;

public:
    // FijarListaLineas: Asigna un nuevo vector de líneas de texto
    void FijarListaLineas(const vector<string>& n_lista) {
        lineasTexto = n_lista;
    }

    // ObtenerListaLineas: Retorna el vector de líneas de texto
    vector<string> ObtenerListaLineas() const {
        return lineasTexto;
    }

    // ObtenerNumLineas: Retorna la cantidad de líneas de texto
    unsigned int ObtenerNumLineas() const {
        return lineasTexto.size();
    }

    // AgregarListaPals: Agrega una nueva línea de texto
    void AgregarListaPals(const string& linea) {
        lineasTexto.push_back(linea);
    }

    // BuscarPrincipio: Busca palabras que comienzan con la subcadena
    void BuscarPrincipio(const string& subcadena) const {
        int contador = 0;
        cout << "\n=== Palabras que comienzan con \"" << subcadena << "\" ===" << endl;

        for (unsigned int numLinea = 0; numLinea < lineasTexto.size(); numLinea++) {
            string linea = lineasTexto[numLinea];
            stringstream ss(linea);
            string palabra;

            while (ss >> palabra) {
                if (palabra.find(subcadena) == 0) { // Comienza con la subcadena
                    cout << "Linea " << (numLinea + 1) << ": " << palabra << endl;
                    contador++;
                }
            }
        }

        cout << "Total: " << contador << " palabras encontradas." << endl;
    }

    // BuscarContiene: Busca palabras que contienen la subcadena
    void BuscarContiene(const string& subcadena) const {
        int contador = 0;
        cout << "\n=== Palabras que contienen \"" << subcadena << "\" ===" << endl;

        for (unsigned int numLinea = 0; numLinea < lineasTexto.size(); numLinea++) {
            string linea = lineasTexto[numLinea];
            stringstream ss(linea);
            string palabra;

            while (ss >> palabra) {
                if (palabra.find(subcadena) != string::npos) { // Contiene la subcadena
                    cout << "Linea " << (numLinea + 1) << ": " << palabra << endl;
                    contador++;
                }
            }
        }

        cout << "Total: " << contador << " palabras encontradas." << endl;
    }

    // BuscarInvertida: Busca palabras que contienen la subcadena invertida
    void BuscarInvertida(const string& subcadena) const {
        string subcadenaInvertida = subcadena;
        reverse(subcadenaInvertida.begin(), subcadenaInvertida.end());

        int contador = 0;
        cout << "\n=== Palabras que contienen la subcadena invertida \"" 
             << subcadenaInvertida << "\" ===" << endl;

        for (unsigned int numLinea = 0; numLinea < lineasTexto.size(); numLinea++) {
            string linea = lineasTexto[numLinea];
            stringstream ss(linea);
            string palabra;

            while (ss >> palabra) {
                if (palabra.find(subcadenaInvertida) != string::npos) { 
                    cout << "Linea " << (numLinea + 1) << ": " << palabra << endl;
                    contador++;
                }
            }
        }

        cout << "Total: " << contador << " palabras encontradas." << endl;
    }
};

// ============================ main ============================
int main(int argc, char* argv[]) {
    // Verificar si se pasó el nombre del archivo como argumento
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <nombre_archivo>" << endl;
        return 1;
    }

    // Nombre del archivo pasado como argumento
    string nombreArchivo = argv[1];
    
    // Variables para almacenar la subcadena y las líneas de texto
    string subcadena;
    ArchivoTexto archivoTexto;

    // Lectura del archivo
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return 1;
    }

    int n;
    archivo >> n;
    archivo.ignore(); // Ignorar el salto de línea

    getline(archivo, subcadena);

    string linea;
    for (int i = 0; i < n; i++) {
        getline(archivo, linea);
        archivoTexto.AgregarListaPals(linea);
    }
    archivo.close();

    // Realizar las búsquedas
    archivoTexto.BuscarPrincipio(subcadena);
    archivoTexto.BuscarContiene(subcadena);
    archivoTexto.BuscarInvertida(subcadena);

    return 0;
}

