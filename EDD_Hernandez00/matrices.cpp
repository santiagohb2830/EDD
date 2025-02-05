/**********************************
Fecha 29 de enero 2025
Autor: Santiago Hernandez B
Materia: Estructuras de Datos
Tema: Programación modular, c++
***********************************/
#include <iostream>
#include <math.h>
#include <chrono>
#include <vector>
#include <string>
#include <ctime>

using namespace std;
using namespace chrono;

/**************** Funciones Recursivas ****************/
int sumaRecursiva(int n) {
    if (n <= 1) {
        return n;
    } else {
        return n + sumaRecursiva(n - 1);
    }
}

int cuadradosPares(int n) {
    if (n == 0) {
        return n;
    } else if (n % 2 == 0) {
        return n * n + cuadradosPares(n - 1);
    } else {
        return cuadradosPares(n - 1);
    }
}

int cuadradosPares2(int n) {
    if (n == 0) {
        return n;
    } else {
        return pow(n + n, 2) + cuadradosPares2(n - 1);
    }
}

int fibNumero(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibNumero(n - 1) + fibNumero(n - 2);
    }
}

bool lineal(string s, char c, int l) {
    if (l < 0) {
        return false;
    } else if (s[l] == c) {
        return true;
    } else {
        return lineal(s, c, l - 1);
    }
}

/**************** Funciones de Ordenamiento y Búsqueda ****************/
template <class T> 
void impresionVector(vector<T>& V) {
    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";
    cout << "\n";
}

template <class T> 
void burbujaOrdenar(vector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size() - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int BinarySearch(vector<int> v, int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (v[mid] == x)
            return mid;
        if (v[mid] > x)
            return BinarySearch(v, low, mid - 1, x);
        return BinarySearch(v, mid + 1, high, x);
    }
    return -1;
}

/**************** Multiplicación de Matrices con Apuntadores ****************/
void multiplicacionMatrices(int** mA, int** mB, int** mC, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(*(mC + i) + j) = 0;
            for (int k = 0; k < N; k++) {
                *(*(mC + i) + j) += *(*(mA + i) + k) * *(*(mB + k) + j);
            }
        }
    }
}

/**************** Función Principal ****************/
int main() {
    int N = 5;

    // Asignación dinámica de memoria
    int** mA = new int*[N];
    int** mB = new int*[N];
    int** mC = new int*[N];

    for (int i = 0; i < N; i++) {
        mA[i] = new int[N];
        mB[i] = new int[N];
        mC[i] = new int[N];
    }

    // Inicializar matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(*(mA + i) + j) = 2 * i;
            *(*(mB + i) + j) = i + j;
            *(*(mC + i) + j) = 0;
        }
    }

    // Multiplicación de matrices
    multiplicacionMatrices(mA, mB, mC, N);

    // Impresión de resultados
    cout << "Matriz A:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(*(mA + i) + j) << " ";
        }
        cout << endl;
    }

    cout << "Matriz B:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(*(mB + i) + j) << " ";
        }
        cout << endl;
    }

    cout << "Matriz C (A x B):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(*(mC + i) + j) << " ";
        }
        cout << endl;
    }

    // Pruebas de funciones recursivas
    cout << "Suma recursiva de 9: " << sumaRecursiva(9) << endl;
    cout << "Cuadrados de pares hasta 33: " << cuadradosPares(33) << endl;
    cout << "Fib(9): " << fibNumero(9) << endl;

    string palabra = "Palabra";
    char substring = 'g';
    cout << "¿La letra '" << substring << "' está en la palabra? " 
         << (lineal(palabra, substring, palabra.length() - 1) ? "Sí" : "No") 
         << endl;

    // Prueba de ordenamiento y búsqueda binaria
    vector<int> vec = {34, 7, 23, 32, 5, 62, 32, 78, 44, 21};
    cout << "Vector original: ";
    impresionVector(vec);

    burbujaOrdenar(vec);
    cout << "Vector ordenado: ";
    impresionVector(vec);

    int numBuscado = 23;
    int resultado = BinarySearch(vec, 0, vec.size() - 1, numBuscado);
    cout << "Resultado de búsqueda binaria para " << numBuscado << ": " 
         << (resultado != -1 ? to_string(resultado) : "No encontrado") 
         << endl;

    // Liberar memoria dinámica
    for (int i = 0; i < N; i++) {
        delete[] mA[i];
        delete[] mB[i];
        delete[] mC[i];
    }
    delete[] mA;
    delete[] mB;
    delete[] mC;

    return 0;
}


