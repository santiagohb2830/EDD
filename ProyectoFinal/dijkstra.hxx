/****************************************************************
Fecha 27 de Mayo 2025
Autor: Santiago Hernandez, Juan Esteban Bello, Esteban Navas
Materia: Estructuras de Datos
Tema: Modulo 3 del Proyecto
*****************************************************************/
#include <queue>
#include <tuple>
#include <cmath>
#include <vector>
#include <cstdint>
#include <iostream>
#include "imagen.h"

using namespace std;

const double INF = 1e18;			//Definicion de un valor muy grade para representar infinito usado en dijkstra

void segmentar(const imagen& img, string nombre, vector<string> argv) {
    int argc = argv.size();
    if (argc < 3 || (argc) % 3 != 0 || (argc) / 3 > 5) {
        std::cerr << "Uso: segmentar salida.pgm sx1 sy1 sl1 [sx2 sy2 sl2 ...] (hasta 5 semillas)\n";
        return;
    }

    int W = img.W;
    int H = img.H;

    // Matrices de distancia y etiqueta
    vector<vector<double>> dist(H, vector<double>(W, INF));
    vector<vector<uint8_t>> label(H, vector<uint8_t>(W, 0));

    using State = tuple<double, int, int, uint8_t>;
    auto cmp = [](const State& a, const State& b) { return get<0>(a) > get<0>(b); };
    priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);

    // Inicializar semillas
    for (int i = 0; i < argc; i += 3) {
        int sx = stoi(argv[i]);
        int sy = stoi(argv[i + 1]);
        int sl = stoi(argv[i + 2]);
        if (sx < 0 || sx >= W || sy < 0 || sy >= H || sl < 1 || sl > 255) {
            cerr << "Semilla inválida: (" << sx << "," << sy << ") etiqueta " << sl << "\n";
            return;
        }
        dist[sy][sx] = 0;
        label[sy][sx] = static_cast<uint8_t>(sl);
        pq.emplace(0.0, sy, sx, label[sy][sx]);
    }

    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    // Propagación Dijkstra multi-fuente
    while (!pq.empty()) {
        auto [d, y, x, lab] = pq.top(); pq.pop();
        if (d > dist[y][x]) continue;
        for (int k = 0; k < 4; ++k) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            double w = abs(img.val[y][x] - img.val[ny][nx]);
            if (d + w < dist[ny][nx]) {
                dist[ny][nx] = d + w;
                label[ny][nx] = lab;
                pq.emplace(dist[ny][nx], ny, nx, lab);
            }
        }
    }

    // Convertir etiquetas a imagen salida
    imagen salida_img;
    salida_img.W = W;
    salida_img.H = H;
    salida_img.val.assign(H, vector<int>(W));
    for (int y = 0; y < H; ++y)
        for (int x = 0; x < W; ++x)
            salida_img.val[y][x] = label[y][x];

    // Calcular el valor máximo de escala de grises para el header:
    int maxv = 0;
    for (int y = 0; y < H; ++y)
        for (int x = 0; x < W; ++x)
            if (salida_img.val[y][x] > maxv)
                maxv = salida_img.val[y][x];
    // O, si prefieres fijarlo siempre en 255:
    // maxv = 255;
    salida_img.M = maxv;
    guardarPGM(salida_img, nombre);
    cout << "Segmentación completada. Archivo guardado en " << nombre << "\n";
}
