#ifndef IMAGEN_H
#define IMAGEN_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct imagen {
    string codigo;
    int W;
    int H;
    int M;
    vector<vector<int>> val;
};

struct volumen {
    int W;
    int H;
    int n_im;
    vector<imagen> imgv;
};

imagen cargarImg(string nombre);
volumen cargarVol(string nombre_base, int n);
void guardarPGM(imagen img, string nombre_archivo);

#endif // IMAGEN_H
