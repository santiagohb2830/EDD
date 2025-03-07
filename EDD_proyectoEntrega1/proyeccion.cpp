#include "proyeccion.h"

imagen proyeccion2D(volumen vol, string direccion, string criterio) {
    imagen resultado;
    resultado.codigo = "P2";  // Formato PGM
    resultado.W = vol.W;
    resultado.H = vol.H;
    resultado.M = vol.imgv[0].M;
    resultado.val = vector<vector<int>>(resultado.H, vector<int>(resultado.W, 0));

    if (direccion == "x") {
        for (int y = 0; y < resultado.H; y++) {
            for (int z = 0; z < vol.n_im; z++) {
                vector<int> valores;
                for (int x = 0; x < resultado.W; x++) {
                    valores.push_back(vol.imgv[z].val[y][x]);
                }

                if (criterio == "minimo") {
                    resultado.val[y][z] = *min_element(valores.begin(), valores.end());
                } else if (criterio == "maximo") {
                    resultado.val[y][z] = *max_element(valores.begin(), valores.end());
                } else if (criterio == "promedio") {
                    int suma = accumulate(valores.begin(), valores.end(), 0);
                    resultado.val[y][z] = suma / valores.size();
                } else if (criterio == "mediana") {
                    sort(valores.begin(), valores.end());
                    resultado.val[y][z] = valores[valores.size() / 2];
                }
            }
        }
    }
    else if (direccion == "y") {
        for (int x = 0; x < resultado.W; x++) {
            for (int z = 0; z < vol.n_im; z++) {
                vector<int> valores;
                for (int y = 0; y < resultado.H; y++) {
                    valores.push_back(vol.imgv[z].val[y][x]);
                }

                if (criterio == "minimo") {
                    resultado.val[z][x] = *min_element(valores.begin(), valores.end());
                } else if (criterio == "maximo") {
                    resultado.val[z][x] = *max_element(valores.begin(), valores.end());
                } else if (criterio == "promedio") {
                    int suma = accumulate(valores.begin(), valores.end(), 0);
                    resultado.val[z][x] = suma / valores.size();
                } else if (criterio == "mediana") {
                    sort(valores.begin(), valores.end());
                    resultado.val[z][x] = valores[valores.size() / 2];
                }
            }
        }
    }
    else if (direccion == "z") {
        for (int y = 0; y < resultado.H; y++) {
            for (int x = 0; x < resultado.W; x++) {
                vector<int> valores;
                for (int z = 0; z < vol.n_im; z++) {
                    valores.push_back(vol.imgv[z].val[y][x]);
                }

                if (criterio == "minimo") {
                    resultado.val[y][x] = *min_element(valores.begin(), valores.end());
                } else if (criterio == "maximo") {
                    resultado.val[y][x] = *max_element(valores.begin(), valores.end());
                } else if (criterio == "promedio") {
                    int suma = accumulate(valores.begin(), valores.end(), 0);
                    resultado.val[y][x] = suma / valores.size();
                } else if (criterio == "mediana") {
                    sort(valores.begin(), valores.end());
                    resultado.val[y][x] = valores[valores.size() / 2];
                }
            }
        }
    }

    return resultado;
}
