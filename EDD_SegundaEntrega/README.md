# Proyecto: Sistema de Procesamiento de Imágenes en Escala de Grises

## Descripción General

Este proyecto corresponde a la segunda entrega del curso de **Estructuras de Datos** de la Pontificia Universidad Javeriana. El sistema desarrollado permite trabajar con imágenes en formato PGM (Portable Gray Map) mediante una interfaz de consola interactiva. A través de comandos específicos, el usuario puede:

- Cargar imágenes individuales o volúmenes de imágenes.
- Generar proyecciones 2D de volúmenes.
- Codificar imágenes utilizando el algoritmo de Huffman para reducir su tamaño.
- Decodificar archivos comprimidos para recuperar las imágenes originales.

## Contenido del Proyecto

- `main.cpp`: Archivo principal que gestiona la ejecución del programa y los comandos del usuario.
- `imagen.h`, `imagen.hxx`: Definición y manipulación de imágenes individuales.
- `volumen.h`, `volumen.hxx`: Definición y manejo de volúmenes de imágenes (varias capas).
- `proyeccion.h`, `proyeccion.hxx`: Generación de proyecciones 2D a partir de volúmenes.
- `huffman.h`, `huffman.hxx`: Implementación del árbol de Huffman para codificar y decodificar imágenes.
- `DocumentacionSegundaEntrega.pdf`: Documento formal con la descripción completa del sistema, los TADs utilizados, plan de pruebas y análisis del código.

## Comandos Principales

- `cargar_imagen <nombre_archivo.pgm>`: Carga una imagen en memoria.
- `cargar_volumen <nombre_base> <n_imagenes>`: Carga un volumen de imágenes numeradas.
- `info_imagen`: Muestra información de la imagen cargada.
- `info_volumen`: Muestra información del volumen cargado.
- `proyeccion2D <direccion> <criterio> <nombre_salida.pgm>`: Genera una proyección 2D.
- `codificar_imagen <nombre_salida.huf>`: Comprime la imagen en memoria usando Huffman.
- `decodificar_archivo <archivo.huf> <imagen_salida.pgm>`: Recupera una imagen a partir de un archivo comprimido.
- `ayuda`: Muestra la lista de comandos disponibles.
- `salir`: Finaliza la ejecución del programa.

## Requisitos

- **Compilador**: g++ (versión 4.0.0 o superior)
- **Sistema operativo**: Linux, Windows o MacOS (consola compatible)

## Instrucciones de Compilación y Ejecución

### Compilación

Desde la terminal, ubicarse en el directorio que contiene los archivos del proyecto y ejecutar el siguiente comando:

```bash
g++ main.cpp -o prog
```

### Ejecución

Una vez compilado, ejecutar el programa con:

```bash
./prog
```

El sistema mostrará un mensaje de bienvenida y quedará a la espera de que el usuario ingrese los comandos.

## Consideraciones

- El sistema solo permite trabajar con una imagen o volumen cargado a la vez.
- Los archivos comprimidos `.huf` deben seguir la estructura generada por el sistema para poder ser decodificados correctamente.
- El proyecto está completamente documentado en el archivo `DocumentacionSegundaEntrega.pdf`.

## Autores

- Santiago Hernandez
- Juan Esteban Bello
- Esteban Nabas

**Profesor:** John Corredor Franco

Pontificia Universidad Javeriana - 2025
