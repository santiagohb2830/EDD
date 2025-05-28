# Procesamiento y Segmentación de Imágenes PGM

Este repositorio contiene la implementación en C++ de un conjunto de herramientas de línea de comandos para el procesamiento de imágenes en formato PGM (P2/P5). El proyecto se divide en tres componentes principales:

1. **Carga e Información**: lectura de imágenes y volúmenes PGM, consulta de metadatos.
2. **Proyección 2D y Compresión Huffman**: generación de vistas 2D desde volúmenes 3D y compresión/descompresión de imágenes mediante Huffman.
3. **Segmentación**: identificación de regiones conectadas a partir de semillas de usuario usando un grafo implícito y Dijkstra multi-fuente.

---

## Características

- Lectura y validación de archivos PGM (formatos P2 y P5).
- Módulo de consulta de metadatos (ancho, alto, valor máximo, número de capas).
- Generación de proyecciones mínimas, máximas y promedio desde volúmenes.
- Compresión y descompresión de imágenes con algoritmo de Huffman.
- Segmentación de imágenes basada en propagación de etiquetas con Dijkstra multi-fuente.
- Manejo de errores y comandos de ayuda integrados (`--help`).

---

## Requisitos

- Compilador: GNU g++ (versión mínima 4.0.0; recomendado 7.0 o superior)
- Sistema operativo: Linux o macOS (Windows con adaptaciones de ruta y compilación)
- Herramientas: make (opcional)

---

## Instalación

Clonar este repositorio y compilar todos los módulos:

```bash
$ git clone https://github.com/tu-usuario/proyecto-pgm.git
$ cd proyecto-pgm
$ g++ main.cpp imagen.hxx proyeccion.hxx huffman.hxx dijkstra.hxx -std=c++17 -O2 -o pgm_tool
```

Si prefieres usar `make`, crear un `Makefile` con este comando de compilación.

---

## Uso

Ejecutar el binario `pgm_tool` seguido del subcomando y sus parámetros:

### 1. Cargar imagen
```bash
$ ./pgm_tool cargar_imagen input.pgm
Se cargó correctamente input.pgm
```

### 2. Consultar metadatos
```bash
$ ./pgm_tool info_imagen
Ancho: 512  Alto: 512  Max: 255
```

### 3. Cargar volumen
```bash
$ ./pgm_tool cargar_volumen slice_ 30
Volumen cargado correctamente con 30 capas
```

### 4. Proyección 2D
```bash
$ ./pgm_tool proyeccion2D min output.pgm
Proyección (min) guardada en output.pgm
```

### 5. Compresión Huffman
```bash
$ ./pgm_tool codificar_imagen compressed.huf
Codificación completada: compressed.huf
```

### 6. Descompresión Huffman
```bash
$ ./pgm_tool decodificar_archivo compressed.huf restored.pgm
Decodificación completada: restored.pgm
```

### 7. Segmentación
```bash
$ ./pgm_tool segmentar out.pgm 30 30 10 100 50 20
Segmentación completada. Archivo guardado en out.pgm
```
- Primer valor: nombre de salida (`out.pgm`).
- Tripletas: `x y etiqueta` para cada semilla (entre 1 y 5 semillas).

Para ver más detalles de uso y opciones disponibles:
```bash
$ ./pgm_tool --help
```

---

## Plan de pruebas

Se incluye un plan de pruebas detallado en el documento `PlanDePruebas.pdf`, con casos normales, de límite y de error. Ejemplo:

| Caso   | Comando                                    | Descripción                                    | Esperado                   |
|--------|--------------------------------------------|------------------------------------------------|----------------------------|
| CP01   | `segmentar out.pgm 10 10 5`               | Menos de 4 parámetros de semilla              | Mensaje de error y salidacode != 0 |
| CP05   | `proyeccion2D avg output.pgm`             | Proyección promedio desde volumen cargado     | Archivo `output.pgm` válido |

---

## Estructura del proyecto

```
proyecto-pgm/
├── main.cpp
├── imagen.hxx
├── proyeccion.hxx
├── huffman.hxx
├── dijkstra.hxx
├── Makefile      # (opcional)
├── PlanDePruebas.pdf
└── README.md
```

---

## Contribuciones

Se agradecen sugerencias y correcciones. Abrir _issues_ o _pull requests_ para aportar.

---

## Licencia

Este proyecto está bajo la licencia MIT. Consulta el archivo `LICENSE` para más detalles.
