/****************************************************************
Fecha 21 de may 2025
Autor: Santiago Hernandez, Juan Esteban Bello
Materia: Estructuras de Datos
Tema: Taller Grafos
*****************************************************************/
// main.cpp
#include <iostream>
#include "Articulo.h"
#include "MapaCitaciones.h"

int main() {
    // Creamos 5 artículos con IDs 1..5
    std::vector<Articulo> arts = {
        Articulo(1), Articulo(2),
        Articulo(3), Articulo(4),
        Articulo(5)
    };

    // Inicializamos el grafo de citaciones
    MapaCitaciones mapa(arts);

    // Añadimos citas (usando índices 0..4 para IDs 1..5)
    mapa.agregarCita(0, 1); // 1→2
    mapa.agregarCita(1, 2); // 2→3
    mapa.agregarCita(1, 4); // 2→5
    mapa.agregarCita(2, 4); // 3→5
    mapa.agregarCita(4, 1); // 5→2

    // Mostramos resultados
    std::cout << "Más citado: "
              << mapa.articuloMasCitado()
              << "\n";
    std::cout << "Grupos al eliminar ID=2: "
              << mapa.contarGruposAlEliminar(2)
              << "\n";
    std::cout << "Índice ref. de ID=2: "
              << mapa.indiceDeReferenciacion(2)
              << "\n";
    std::cout << "Citaciones indirectas de ID=2: "
              << mapa.contarCitacionesIndirectas(2)
              << "\n";

    return 0;
}
