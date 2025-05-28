# Procesamiento y Segmentación de Imágenes PGM

Este proyecto ofrece un conjunto de herramientas de línea de comandos escritas en C++ para el manejo integral de imágenes en formato PGM (P2) y volúmenes formados por múltiples capas PPM/PGM. Está organizado en tres módulos principales:

1. **Carga e Información**: lectura y guardado de imágenes PGM; carga de volúmenes PPM/PGM; consulta de metadatos.
2. **Proyección 2D y Compresión Huffman**: generación de imágenes 2D según criterios (mínimo, máximo, promedio, mediana) desde volúmenes 3D; compresión y descompresión de imágenes con el algoritmo de Huffman.
3. **Segmentación**: identificación automática de regiones conectadas en una imagen PGM mediante un grafo implícito y un algoritmo de Dijkstra multi-fuente.

---

## Vista general

Al iniciar el programa ejecutable `pgm_tool`, el usuario tiene acceso a un menú interactivo por línea de comandos donde puede cargar imágenes o volúmenes, consultar sus metadatos, aplicar proyecciones, comprimir o descomprimir con Huffman, y finalmente segmentar una imagen indicando hasta cinco semillas con coordenadas (x, y) y una etiqueta (1–255).

Cada módulo se implementa con TADs claros y separados (por ejemplo, `imagen`, `volumen`, `NodoHuffman`, `Grafo`), y funciones que siguen rigurosamente entradas, salidas, precondiciones y postcondiciones, como se documenta en el informe de diseño.

---

## Instalación y compilación

Requisitos:
- GNU g++ 4.0.0 o superior
- make (opcional)

Clonar y compilar:

```bash
$ git clone https://github.com/tu-usuario/proyecto-pgm.git
$ cd proyecto-pgm
$ make         # si ya existe Makefile
# o directamente:
$ g++ main.cpp imagen.hxx proyeccion.hxx huffman.hxx dijkstra.hxx -std=c++17 -O2 -o pgm_tool
```

---

## Uso y ejemplos

Tras compilar, ejecutar el binario:
```bash
$ ./pgm_tool
``` 
Aparecerá la interfaz interactiva; usar `ayuda` para ver comandos.

### Carga y consulta

```bash
$ cargar_imagen imagen.pgm
Se cargó la imagen 'imagen.pgm' correctamente

$ info_imagen
Nombre: imagen.pgm
Dimensiones: 512 x 512
Valor máximo: 255

$ cargar_volumen slice_ 10
Se cargó el volumen con 10 imágenes correctamente

$ info_volumen
Nombre base: slice_
Dimensiones: 512 x 512
Capas: 10
```

### Proyección 2D

```bash
$ proyeccion2D z promedio salida.pgm
Proyección (promedio) generada: 'salida.pgm'
``` 
Criterios válidos: `minimo`, `maximo`, `promedio`, `mediana`.

### Compresión y descompresión Huffman

```bash
$ codificar_imagen salida.huf
La imagen ha sido comprimida: 'salida.huf'

$ decodificar_archivo salida.huf restaurada.pgm
Imagen reconstruida y guardada como 'restaurada.pgm'
``` 
Los archivos `.huf` incluyen metadatos de tamaño para reconstruir correctamente la imagen.

### Segmentación de imágenes

```bash
$ segmentar resultado.pgm 30 30 10 100 50 20
Segmentación completada. Archivo guardado en 'resultado.pgm'
```
- Sintaxis: `segmentar <output.pgm> sx1 sy1 et1 [sx2 sy2 et2 ...]`
- Máximo 5 semillas, etiqueta entre 1 y 255.

---

## Estructura del repositorio

```plaintext
proyecto-pgm/
├── main.cpp             # Lógica del menú interactivo y dispatch de comandos
├── imagen.h/.hxx        # TAD imagen y volumen, lectura/escritura PGM/PPM
├── proyeccion.h/.hxx    # Implementación de proyecciones 2D
├── huffman.h/.hxx       # Árbol de Huffman y compresión/descompresión
├── dijkstra.h/.hxx      # Segmentación basada en Dijkstra multi-fuente
├── Makefile             # Reglas de compilación (opcional)
├── README.md            # Descripción general y guía rápida
└── docs/                # Documentación: diseño, plan de pruebas, TADs, UML
```

---

## Documentación adicional

En la carpeta `docs/` se incluyen:
- **Diseño.pdf**: descripción de entradas, salidas, pre/postcondiciones, TADs y diagramas UML.
- **PlanDePruebas.pdf**: casos de prueba detallados para cada comando.
- **ActaEvaluacion.pdf**: registro de observaciones de la primera y segunda entrega y correcciones aplicadas.

---

## Licencia

Este proyecto está bajo licencia MIT. Ver `LICENSE` para más detalles.

---

## Autores

- Santiago Hernández
- Juan Esteban Bello
- Esteban Navas

Para consultas o contribuciones, abre un _issue_ o un _pull request_. ¡Gracias por tu interés!
