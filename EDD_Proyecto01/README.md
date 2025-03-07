# Proyecto - Estructuras de Datos

## Descripcion
Entrega 0 del Proyecto del curso de **Estructuras de Datos**. Implementa una interfaz de usuario basada en comandos para interactuar con el sistema de procesamiento de imagenes.

El programa recibe comandos a traves de la terminal, valida su formato y muestra la respuesta. No realiza operaciones sobre imagenes, solo se enfoca en la gestion de comandos y validacion de parametros.

---

## Autores
- Santiago Hernandez
- Juan Esteban
- Esteban Navas

---

## Comandos Disponibles

El programa acepta los siguientes comandos:

| Comando | Descripcion |
|---------|------------|
| `cargar_imagen <nombre>` | Carga una imagen con el nombre especificado |
| `cargar_volumen <nombre_base> <n_im>` | Carga una serie ordenada de imagenes numeradas |
| `info_imagen` | Muestra informacion de la imagen cargada |
| `proyeccion2D <direccion> <criterio> <nombre_archivo.pgm>` | Genera una proyeccion 2D del volumen cargado |
| `codificar_imagen <nombre_archivo.huf>` | Codifica y guarda la imagen en formato comprimido |
| `decodificar_archivo <nombre_archivo.huf> <nombre_imagen.pgm>` | Decodifica un archivo y genera una imagen PGM |
| `segmentar <salida_imagen.pgm> <sx1 sy1 sl1> ... <sx5 sy5 sl5>` | Segmenta la imagen cargada usando hasta 5 semillas |
| `ayuda` | Muestra la lista de comandos disponibles |
| `ayuda <comando>` | Muestra detalles sobre el uso de un comando especifico |
| `exit` | Cierra el programa |

---

PASO A PASO PARA COMPILAR Y EJECUTAR EL PROYECTO EN LINUX

1. ABRIR LA TERMINAL
   - Presiona "Ctrl + Alt + T" o busca "Terminal" en el menú de aplicaciones.

2. INSTALAR EL COMPILADOR G++
   - Escribe el siguiente comando y presiona "Enter":
     sudo apt update && sudo apt install g++ -y
   - Para verificar la instalación, ejecuta:
     g++ --version
   - Si ves un número de versión en pantalla, el compilador está instalado correctamente.

3. INSTALAR GIT
   - Si Git no está instalado, instálalo con:
     sudo apt install git -y
   - Verifica la instalación ejecutando:
     git --version

4. CLONAR EL REPOSITORIO DEL PROYECTO
   - Para descargar el código fuente, ejecuta:
     git clone https://github.com/santiagohb2830/proyecto-estructuras.git
   - Luego, entra en el directorio del proyecto:
     cd proyecto-estructuras

5. COMPILAR EL CÓDIGO
   - Dentro del directorio del proyecto, compila el código con:
     g++ -o proyecto main.cpp
   - Si no hay errores en la compilación, se generará un ejecutable llamado "proyecto".

6. EJECUTAR EL PROGRAMA
   - Para iniciar el programa, usa el siguiente comando:
     ./proyecto
   - Esto mostrará un indicador "$", lo que significa que el sistema está listo para recibir comandos.

7. PROBAR LOS COMANDOS
   - Puedes ingresar comandos en la terminal, por ejemplo:
     $ cargar_imagen ejemplo.pgm
   - Si introduces un comando incorrecto, el sistema mostrará un mensaje de error.

8. SALIR DEL PROGRAMA
   - Para cerrar el programa, simplemente escribe:
     $ exit

FIN.

