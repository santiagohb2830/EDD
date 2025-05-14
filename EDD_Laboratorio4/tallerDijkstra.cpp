/****************************************************************
Fecha 14 de Mayo 2025
Autor: Santiago Hernandez
Materia: Estructuras de Datos
Tema: Laboratorio 05
*****************************************************************/
#include <iostream>
#include <climits>
using namespace std;
#define V 9

/* función para encontrar el vértice con el valor de distancia mínimo, del 
   conjunto de vértices aún no incluidos en el árbol del camino más corto */
int minDistance(int dist[], bool sptSet[]){
    // Inicializar con valor mínimo
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

/* función para imprimir la matriz de distancias construida */
void printSolution(int dist[]){
    cout << "Vértice \t Distancia desde la Fuente" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t " << dist[i] << endl;
}

/*Función algoritmo de fuente única de Dijkstra: camino más corto de
Dijkstra para un grafo representado mediante representación de matriz de
adyacencia*/

// 3) Implementación completa de Dijkstra
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];

    // Inicializar
    for (int i = 0; i < V; i++) {
        dist[i]   = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;

    // Bucle principal: para cada vértice
    for (int count = 0; count < V - 1; count++) {
        // a) Escoger vértice u con distancia mínima
        int u = minDistance(dist, sptSet);
        // b) Marcarlo como procesado
        sptSet[u] = true;
        // c) Relajar sus aristas (u → v)
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] &&
                graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Mostrar resultado
    printSolution(dist);
}
    int main(){
        /* Grafo */
        int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
        // llamada a la función
        dijkstra(graph, 0);

        return 0;
        }
