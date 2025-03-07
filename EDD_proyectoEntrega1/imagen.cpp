#include "imagen.h"

imagen cargarImg(string nombre) {
    imagen img;
    string temp;
    ifstream archivo(nombre);
    if (archivo.is_open()) {
        getline(archivo, img.codigo);
        archivo >> temp;
        while (temp[0] == '#') {
            getline(archivo, temp);
            archivo >> temp;
        }
        img.W = stoi(temp);
        archivo >> img.H;
        archivo >> img.M;

        for (int i = 0; i < img.H; i++) {
            img.val.emplace_back(vector<int>());
            for (int j = 0; j < img.W; j++) {
                archivo >> temp;
                img.val[i].push_back(stoi(temp));
            }
        }
    }
    archivo.close();
    return img;
}

volumen cargarVol(string nombre_base, int n) {
    volumen vol;
    vol.n_im = n;
    for (int i = 1; i <= n; i++) {
        string nombre = nombre_base + (n < 10 ? "0" : "") + to_string(i) + ".pgm";
        imagen img = cargarImg(nombre);
        vol.imgv.push_back(img);
        vol.H = img.H;
        vol.W = img.W;
    }
    return vol;
}

void guardarPGM(imagen img, string nombre_archivo) {
    ofstream archivo(nombre_archivo);
    if (archivo.is_open()) {
        archivo << img.codigo << endl;
        archivo << img.W << " " << img.H << endl;
        archivo << img.M << endl;
        for (int i = 0; i < img.H; i++) {
            for (int j = 0; j < img.W; j++) {
                archivo << img.val[i][j] << " ";
            }
            archivo << endl;
        }
        archivo.close();
    }
}
