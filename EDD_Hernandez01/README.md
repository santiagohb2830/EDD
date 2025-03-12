# Plan de Pruebas y Depuración de Código en C++

## Descripción
Este repositorio contiene el informe del **Taller 01: Plan de Pruebas**, realizado en el curso de **Estructuras de Datos**. El objetivo principal del taller es compilar, ejecutar y depurar los archivos **exercise1.cpp** y **exercise2.cxx**, utilizando herramientas como `g++` y `gdb`. Además, se implementa un **plan de pruebas** para evaluar la funcionalidad de las funciones involucradas en el cálculo del **perímetro**, **área** y **distancia al origen** de un rectángulo.

## Contenido del Repositorio
- **Documento principal**: Informe detallado del taller con la metodología aplicada, análisis de errores y correcciones implementadas.
- **Código fuente**: Archivos `exercise1.cpp` y `exercise2.cxx`, utilizados para la ejecución de las pruebas.
- **Capturas de pantalla**: Evidencia del proceso de compilación, ejecución y depuración.
- **Readme.md**: Este archivo con la explicación del proyecto.

## Metodología
1. **Compilación y ejecución de `exercise1.cpp`**: Se utilizó `g++` para compilar y ejecutar el código desde la terminal.
2. **Depuración de `exercise2.cxx` con `gdb`**: Se incorporaron símbolos de depuración y se analizaron los errores en tiempo de ejecución.
3. **Implementación del plan de pruebas**: Se realizaron pruebas unitarias para verificar la funcionalidad de las funciones y se identificaron errores en los cálculos.
4. **Corrección de errores**: Se modificaron las funciones `perimeterRect` y `areaRect` para obtener los resultados esperados.

## Resultados
Se detectaron errores en los cálculos del perímetro y área del rectángulo, los cuales fueron corregidos tras el análisis con `gdb` y la comparación con los valores esperados en las pruebas. Finalmente, el código corregido se ejecutó exitosamente, obteniendo los resultados correctos en todas las pruebas.

## Uso del Código
Para compilar y ejecutar los archivos:
```bash
# Compilar exercise1.cpp
g++ -std=c++11 -o exercise1 exercise1.cpp
./exercise1

# Compilar exercise2.cxx con depuración
g++ -std=c++11 -g -o exercise2 exercise2.cxx
gdb exercise2
```

## Autor
**Santiago Hernández Barbosa**
