# Gestor de Imágenes PGM

**Autores**: Santiago Hernández, Juan Esteban Bello, Esteban Navas, John Corredor
**Fecha**: 27 de mayo de 2025
**Lenguaje**: C++ (requiere GNU g++ ≥ 4.0.0)

---

## Visión General

Gestor de Imágenes PGM es una herramienta de línea de comandos diseñada para el procesamiento y análisis de imágenes en formato PGM (P2/P5) y volúmenes 3D. Permite:

* **Cargar** imágenes individuales y colecciones volumétricas.
* **Visualizar** metadatos esenciales (dimensiones, nombre de archivo).
* **Generar proyecciones 2D** sobre ejes X, Y o Z mediante criterios de mínima, máxima o media.
* **Comprimir** y **descomprimir** imágenes con codificación Huffman para reducción de tamaño.
* **Segmentar** regiones conectadas en base a múltiples semillas usando un grafo implícito y algoritmo de Dijkstra.

El programa se estructura en TADs modulares (Imagen, Volumen, Huffman, Grafo) que garantizan claridad, mantenibilidad y facilidad de extensión.

---

## Requisitos

* Sistema operativo: Linux, Windows o macOS
* Compilador: g++ versión 4.0.0 o superior (soporte C++11)

---

## Compilación

**Con Makefile**:

```bash
make
```

**Manual**:

```bash
g++ -std=c++11 -o gestor_pgm \
    imagen.h imagen.hxx \
    proyeccion.h proyeccion.hxx \
    huffman.h huffman.hxx \
    dijkstra.h dijkstra.hxx \
    main.cpp
```

---

## Uso

Ejecuta:

```bash
./gestor_pgm
```

Prompt inicial:

```
Bienvenido al programa.
Use el comando (ayuda) para ver los comandos disponibles.
$
```

### Comandos y ejemplos

#### `ayuda`

Muestra la lista de comandos o detalles sintácticos:

```bash
$ ayuda             # Lista todos los comandos disponibles
$ ayuda cargar_imagen  # Sintaxis y descripción de 'cargar_imagen'
```

#### 1. Carga y consulta de imágenes

* **`cargar_imagen <ruta.pgm>`**: carga un archivo PGM (P2/P5) en memoria.

  ```bash
  $ cargar_imagen lena.pgm
  Se cargó correctamente lena.pgm
  ```

* **`cargar_volumen <base> <n>`**: carga secuencia `<base>0.pgm`…`<base><n-1>.pgm` como volumen 3D.

  ```bash
  $ cargar_volumen slice_ 10
  Volumen cargado correctamente
  ```

* **`info_imagen`**: muestra nombre, ancho y alto de la imagen actual.

  ```bash
  $ info_imagen
  Nombre: lena.pgm | Ancho: 512 | Alto: 512
  ```

* **`info_volumen`**: muestra base, número de capas y dimensiones del volumen.

  ```bash
  $ info_volumen
  Base: slice_ | Capas: 10 | Dimensiones: 256×256
  ```

#### 2. Proyección 2D

**`proyeccion2D <eje> <criterio> <salida.pgm>`**

* **Eje**: `x`, `y` o `z`
* **Criterio**: `min`, `max` o `avg`

```bash
$ proyeccion2D z avg proj_avg.pgm
Proyección generada: proj_avg.pgm
```

#### 3. Compresión y descompresión (Huffman)

* **`codificar_imagen <salida.huf>`**: comprime la imagen en memoria a archivo `.huf`.

  ```bash
  $ codificar_imagen lena.huf
  Comprimida: lena.huf
  ```

* **`decodificar_archivo <entrada.huf> <salida.pgm>`**: reconstruye PGM desde `.huf`.

  ```bash
  $ decodificar_archivo lena.huf lena_rec.pgm
  Decodificada: lena_rec.pgm
  ```

#### 4. Segmentación de imágenes

**`segmentar <salida.pgm> sx1 sy1 l1 [sx2 sy2 l2 ...]`**

* Hasta 5 semillas `(x, y, etiqueta)`.

```bash
$ segmentar segm.pgm 10 10 1 50 50 2
Segmentación completa: segm.pgm
```

**Errores comunes**:

* Sin imagen cargada: `Error: No hay imagen en memoria.`
* Semilla fuera de rango: `Semilla inválida (x,y)`

---

## Plan de pruebas

* **CP01**: Segmentación con 5 semillas → éxito.
* **CP02**: Sin imagen cargada → muestra error y termina.
* **CP03**: Semilla inválida → mensaje de semilla inválida.

---

## Estructura de directorios

```plaintext
/ (raíz)
│ main.cpp
│ Makefile
├─ imagen.h .hxx
├─ proyeccion.h .hxx
├─ huffman.h .hxx
└─ dijkstra.h .hxx
```
