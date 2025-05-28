# 🖼️ Gestor de Imágenes

Un sistema completo de procesamiento y manipulación de imágenes desarrollado en C++ que incluye funcionalidades avanzadas de compresión, proyección 2D y segmentación.

## 📋 Tabla de Contenidos

- [Características](#-características)
- [Requisitos del Sistema](#-requisitos-del-sistema)
- [Instalación y Compilación](#-instalación-y-compilación)
- [Uso del Programa](#-uso-del-programa)
- [Comandos Disponibles](#-comandos-disponibles)  
- [Ejemplos de Uso](#-ejemplos-de-uso)
- [Formatos Soportados](#-formatos-soportados)
- [Estructura del Proyecto](#-estructura-del-proyecto)
- [Autores](#-autores)

## ✨ Características

- **Carga de Imágenes**: Soporte para formatos PGM y PPM con conversión automática a escala de grises
- **Gestión de Volúmenes**: Manejo de conjuntos de imágenes como volúmenes 3D
- **Proyecciones 2D**: Generación de proyecciones bidimensionales desde volúmenes 3D
- **Compresión Huffman**: Algoritmo de compresión sin pérdida para optimizar almacenamiento
- **Segmentación**: Segmentación de imágenes usando algoritmo de Dijkstra multi-fuente
- **Interfaz Interactiva**: Sistema de comandos intuitivo con ayuda integrada

## 🔧 Requisitos del Sistema

- **Compilador**: G++ con soporte para C++17 o superior
- **Sistema Operativo**: Linux, macOS, Windows (con MinGW)

## 🚀 Instalación y Compilación

### Compilación Manual
```bash
g++ -Wall -std=c++17 -o prog main.cpp
```

### Usando Makefile
```bash
# Compilar
make

# Compilar y ejecutar
make run

# Limpiar archivos compilados
make clean
```

## 💻 Uso del Programa

### Ejecución
```bash
./prog
```

Al iniciar, verás el banner del programa y el prompt de comandos:
```
$ 
```

### Sistema de Ayuda
- `ayuda` - Lista todos los comandos disponibles
- `ayuda <comando>` - Información específica de un comando
- `salir` - Terminar el programa

## 📝 Comandos Disponibles

### 1. Gestión de Imágenes

#### `cargar_imagen <nombre_imagen>`
Carga una imagen individual en formato PGM.

**Ejemplo:**
```bash
$ cargar_imagen imagen01.pgm
```

#### `info_imagen`
Muestra información de la imagen cargada actualmente.

**Salida esperada:**
```
Información de la imagen cargada:
- Nombre: imagen01.pgm
- Ancho : 512
- Alto  : 512
```

### 2. Gestión de Volúmenes

#### `cargar_volumen <nombre_base> <numero_imagenes>`
Carga un conjunto de imágenes PPM como un volumen 3D.

**Formato esperado de archivos:** `nombre_base01.ppm`, `nombre_base02.ppm`, ..., `nombre_baseNN.ppm`

**Ejemplo:**
```bash
$ cargar_volumen slice 25
```
Esto cargará: `slice01.ppm`, `slice02.ppm`, ..., `slice25.ppm`

#### `info_volumen`
Muestra información del volumen cargado.

**Salida esperada:**
```
Información del volumen cargado:
- Nombre base: slice
- Ancho       : 256
- Alto        : 256
- Número de imágenes: 25
```

### 3. Proyecciones 2D

#### `proyeccion2D <direccion> <criterio> <nombre_salida>`

Genera una proyección 2D desde un volumen 3D.

**Parámetros:**
- **Dirección**: `x`, `y`, o `z`
- **Criterio**: `minimo`, `maximo`, `promedio`, `mediana`

**Ejemplos:**
```bash
$ proyeccion2D z maximo proyeccion_maxima.pgm
$ proyeccion2D x promedio proyeccion_promedio.pgm
$ proyeccion2D y mediana proyeccion_mediana.pgm
```

### 4. Compresión y Descompresión

#### `codificar_imagen <nombre_salida.huf>`
Comprime la imagen cargada usando el algoritmo de Huffman.

**Ejemplo:**
```bash
$ codificar_imagen imagen_comprimida.huf
```

#### `decodificar_archivo <archivo.huf> <nombre_imagen_salida>`
Descomprime un archivo y recupera la imagen original.

**Ejemplo:**
```bash
$ decodificar_archivo imagen_comprimida.huf imagen_recuperada.pgm
```

### 5. Segmentación

#### `segmentar <salida_imagen> <semillas>`
Segmenta una imagen usando hasta 5 semillas con el algoritmo de Dijkstra.

**Formato de semillas:** `x y etiqueta` (hasta 5 conjuntos)

**Ejemplos:**
```bash
# Una semilla
$ segmentar resultado.pgm 100 100 255

# Tres semillas
$ segmentar segmentacion.pgm 50 50 100 150 150 200 200 200 255

# Cinco semillas (máximo)
$ segmentar multi_segmento.pgm 10 10 50 50 50 100 100 100 150 150 150 200 200 200 255
```

## 🎯 Ejemplos de Uso

### Ejemplo Completo: Procesamiento de Volumen Médico

```bash
# Iniciar el programa
./prog

# Cargar un volumen de 30 imágenes de resonancia magnética
$ cargar_volumen brain 30

# Verificar información del volumen
$ info_volumen

# Generar proyección máxima en el eje Z
$ proyeccion2D z maximo brain_projection_max.pgm

# Generar proyección promedio en el eje Y  
$ proyeccion2D y promedio brain_projection_avg.pgm

# Cargar una imagen específica para análisis
$ cargar_imagen brain_slice.pgm

# Comprimir la imagen
$ codificar_imagen brain_compressed.huf

# Segmentar la imagen con múltiples regiones
$ segmentar brain_segmented.pgm 64 64 100 128 128 150 192 192 200

# Salir del programa
$ salir
```

### Ejemplo: Análisis de Imagen Única

```bash
# Cargar imagen
$ cargar_imagen foto.pgm

# Ver información
$ info_imagen

# Segmentar con dos regiones
$ segmentar foto_segmentada.pgm 50 50 128 200 200 255

# Comprimir resultado
$ codificar_imagen foto_segmentada_compressed.huf

# Verificar descompresión
$ decodificar_archivo foto_segmentada_compressed.huf foto_verificacion.pgm
```

## 📁 Formatos Soportados

### Entrada
- **PGM (P2)**: Imágenes en escala de grises
- **PPM (P3)**: Imágenes a color (convertidas automáticamente a escala de grises)

### Salida
- **PGM (P2)**: Todas las imágenes de salida
- **HUF**: Archivos comprimidos con Huffman

### Estructura de Archivos PGM
```
P2
# Comentario opcional
ancho alto
valor_maximo
pixel1 pixel2 pixel3 ...
```

### Estructura de Archivos PPM
```
P3
# Comentario opcional  
ancho alto
valor_maximo
r1 g1 b1 r2 g2 b2 ...
```

## 🏗️ Estructura del Proyecto

```
gestor-imagenes/
├── main.cpp           # Programa principal con interfaz de usuario
├── imagen.h           # Definiciones de estructuras de datos
├── imagen.hxx         # Implementación de carga/guardado de imágenes
├── proyeccion.h       # Declaraciones para proyecciones 2D
├── proyeccion.hxx     # Implementación de proyecciones 2D
├── huffman.h          # Declaraciones para compresión Huffman
├── huffman.hxx        # Implementación del algoritmo Huffman
├── dijkstra.h         # Declaraciones para segmentación
├── dijkstra.hxx       # Implementación del algoritmo Dijkstra
├── Makefile           # Automatización de compilación
└── README.md          # Documentación del proyecto
```

### Componentes Principales

#### Estructuras de Datos
```cpp
struct imagen {
    string codigo;              // Formato (P2/P3)
    int W, H;                  // Dimensiones
    int M;                     // Valor máximo
    vector<vector<int>> val;   // Matriz de píxeles
};

struct volumen {
    int W, H;                  // Dimensiones comunes
    int n_im;                 // Número de imágenes  
    vector<imagen> imgv;      // Vector de imágenes
};
```

#### Algoritmos Implementados

1. **Conversión PPM → Escala de Grises**
   - Fórmula: `0.299*R + 0.587*G + 0.114*B`

2. **Proyecciones 2D**
   - Mínimo, Máximo, Promedio, Mediana
   - Direcciones: X, Y, Z

3. **Compresión Huffman**
   - Construcción de árbol binario
   - Codificación variable
   - Serialización de árbol

4. **Segmentación Dijkstra**
   - Multi-fuente
   - Basada en diferencias de intensidad
   - Hasta 5 semillas simultáneas

## ⚠️ Notas Importantes

- Las imágenes del volumen deben tener el mismo tamaño
- Los nombres de archivos del volumen deben seguir el formato: `base##.ppm`
- El número máximo de imágenes por volumen es 99
- La segmentación soporta máximo 5 semillas
- Los archivos comprimidos tienen extensión `.huf`

## 🐛 Solución de Problemas

### Errores Comunes

1. **"Error: No se pudo abrir el archivo"**
   - Verificar que el archivo existe
   - Comprobar permisos de lectura
   - Validar el nombre del archivo

2. **"Error: Las imágenes no tienen el mismo tamaño"**
   - Todas las imágenes del volumen deben ser idénticas en dimensiones
   - Verificar resolución de cada imagen

3. **"Error: El volumen aún no ha sido cargado en memoria"**
   - Cargar un volumen antes de usar `proyeccion2D`

4. **"Error: No hay una imagen en memoria"**
   - Cargar una imagen antes de usar `codificar_imagen` o `segmentar`

## 👥 Autores

- **Santiago Hernández**
- **Juan Esteban Bello** 
- **Esteban Navas**

**Materia:** Estructuras de Datos  
**Fecha:** 27 de Mayo 2025  
**Tema:** Módulo 3 del Proyecto

---

*Este proyecto implementa algoritmos avanzados de procesamiento de imágenes incluyendo compresión sin pérdida, proyecciones volumétricas y segmentación basada en grafos.*
