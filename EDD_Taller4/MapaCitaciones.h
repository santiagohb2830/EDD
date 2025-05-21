/****************************************************************
Fecha 21 de may 2025
Autor: Santiago Hernandez, Juan Esteban Bello
Materia: Estructuras de Datos
Tema: Taller Grafos
*****************************************************************/
// MapaCitaciones.h
#pragma once
#include <vector>
#include "Articulo.h"

// TAD MapaCitaciones: grafo de citaciones
class MapaCitaciones {
public:
    MapaCitaciones(const std::vector<Articulo>& arts);

    void agregarCita(int ori, int dest);      // registra una arista ori→dest

    int articuloMasCitado() const;            // algoritmo 1
    int contarGruposAlEliminar(int id) const; // algoritmo 2
    double indiceDeReferenciacion(int id) const; // algoritmo 3
    int contarCitacionesIndirectas(int id) const; // algoritmo 4

private:
    std::vector<Articulo> articulos;               // todos los artículos
    std::vector<std::vector<bool>> adyacencia;     // matriz de adyacencia

    int indexOf(int id) const;                     // ayuda: id → índice
};
