/****************************************************************
Fecha 21 de may 2025
Autor: Santiago Hernandez, Juan Esteban Bello
Materia: Estructuras de Datos
Tema: Taller Grafos
*****************************************************************/
// Articulo.h
#pragma once
#include <vector>

// TAD Articulo: representa un artículo y sus citas
class Articulo {
public:
    Articulo(int id) : id(id) {}              // constructor con id

    int obtenerId() const { return id; }      // devuelve el id
    const std::vector<int>& obtenerReferencias() const { return referencias; }  // devuelve citas

    void agregarReferencia(int idDest) {       // añade una cita
        referencias.push_back(idDest);
    }

private:
    int id;                                    // identificador único
    std::vector<int> referencias;              // ids de artículos citados
};
