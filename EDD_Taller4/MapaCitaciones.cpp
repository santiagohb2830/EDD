/****************************************************************
Fecha 21 de may 2025
Autor: Santiago Hernandez, Juan Esteban Bello
Materia: Estructuras de Datos
Tema: Taller Grafos
*****************************************************************/
// MapaCitaciones.cpp
#include "MapaCitaciones.h"
#include <limits>
#include <queue>

MapaCitaciones::MapaCitaciones(const std::vector<Articulo>& arts)
  : articulos(arts),
    adyacencia(arts.size(), std::vector<bool>(arts.size(), false))
{}// inicializa matriz de adyacencia

// crea arista ori→dest en la matriz
void MapaCitaciones::agregarCita(int ori, int dest) {
    adyacencia[ori][dest] = true;
}

// busca índice de un artículo por id
int MapaCitaciones::indexOf(int id) const {
    for (int i = 0; i < (int)articulos.size(); ++i)
        if (articulos[i].obtenerId() == id) return i;
    return -1;
}

// 1) devuelve id del artículo con más citas entrantes
int MapaCitaciones::articuloMasCitado() const {
    int n = adyacencia.size();
    std::vector<int> cuenta(n, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (adyacencia[i][j]) ++cuenta[j];

    int maxC = -1, mejorId = -1;
    for (int i = 0; i < n; ++i) {
        if (cuenta[i] > maxC) {
            maxC    = cuenta[i];
            mejorId = articulos[i].obtenerId();
        }
    }
    return mejorId;
}

// 2) elimina id y cuenta componentes conexos (grafo no dirigido)
int MapaCitaciones::contarGruposAlEliminar(int id) const {
    int rem = indexOf(id), n = adyacencia.size();
    if (rem < 0) return 0;
// eliminar id
    std::vector<bool> vis(n, false);
    int grupos = 0;
    for (int i = 0; i < n; ++i) {
        if (i == rem || vis[i]) continue;
        ++grupos;
        std::queue<int> q;
        q.push(i); vis[i] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v = 0; v < n; ++v) {
                if (v == rem || vis[v]) continue;
                if (adyacencia[u][v] || adyacencia[v][u]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }// contar componentes conexos
    // (grafo no dirigido)
    return grupos;
}

// 3) devuelve entrantes / (0.5 * salientes)
double MapaCitaciones::indiceDeReferenciacion(int id) const {
    int idx = indexOf(id), n = adyacencia.size();
    if (idx < 0) return 0.0;

    int ent = 0, sal = 0;
    for (int j = 0; j < n; ++j) {
        if (adyacencia[j][idx]) ++ent;
        if (adyacencia[idx][j]) ++sal;
    } // contar entrantes y salientes
    if (sal == 0) return 0.0;
    return double(ent) / (0.5 * sal);
}

// 4) cuenta nodos alcanzables en ≥2 saltos desde id
int MapaCitaciones::contarCitacionesIndirectas(int id) const {
    int idx = indexOf(id), n = adyacencia.size();
    if (idx < 0) return 0;

    std::vector<int> nivel(n, -1);
    std::queue<int> q;
    nivel[idx] = 0; q.push(idx); // nivel de id es 0

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < n; ++v) {
            if (adyacencia[u][v] && nivel[v] == -1) {
                nivel[v] = nivel[u] + 1;
                q.push(v);
            }
        }
    } // contar nodos alcanzables

    int cuenta = 0;
    for (int i = 0; i < n; ++i)
        if (nivel[i] >= 2) ++cuenta;
    return cuenta;
}
