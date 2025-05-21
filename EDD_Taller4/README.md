# Taller de Grafos

Este repositorio contiene la solución al Taller de Grafos de la asignatura Estructura de Datos. El objetivo es representar y analizar redes de citaciones académicas usando grafos dirigidos.

## Estructura de archivos

* `Articulo.h` / `Articulo.cpp` (opcional): define el TAD `Articulo`, con su identificador y lista de referencias.
* `MapaCitaciones.h` / `MapaCitaciones.cpp`: define el TAD `MapaCitaciones` y los algoritmos:

  1. `articuloMasCitado()`
  2. `contarGruposAlEliminar(int id)`
  3. `indiceDeReferenciacion(int id)`
  4. `contarCitacionesIndirectas(int id)`
* `main.cpp`: ejemplo de uso. Crea un conjunto de artículos, añade citas y muestra resultados.

## ¿Cómo funciona?

1. **Modelado**: cada `Articulo` tiene un `id` y puede citar a otros artículos.
2. **Grafo dirigido**: `MapaCitaciones` construye una matriz de adyacencia para representar las citaciones.
3. **Algoritmos**:

   * **Artículo más citado**: busca la columna con más entradas en la matriz.
   * **Grupos al eliminar**: trata el grafo como no dirigido y cuenta componentes conexos, ignorando un vértice.
   * **Índice de referenciación**: calcula (entrantes) / (0.5 \* salientes).
   * **Citaciones indirectas**: hace un BFS para medir la distancia en saltos y cuenta los que están a ≥2 saltos.

## Requisitos

* Ubuntu Linux
* Compilador C++ (g++ compatible con C++17)

## Compilación y ejecución

Abrir una terminal en la carpeta del proyecto y ejecutar:

```bash
# Compilar
g++ main.cpp MapaCitaciones.cpp -o miPrograma

# Ejecutar
./miPrograma
```

La salida esperada es:

```
Más citado: 2
Grupos al eliminar ID=2: 3
Índice ref. de ID=2: 2
Citaciones indirectas de ID=2: 0
```

---

Con esto se cubre el funcionamiento y la forma de uso del taller.

