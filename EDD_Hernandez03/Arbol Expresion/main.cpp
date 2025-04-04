/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/
#include<iostream>
#include "ArbolExpresion.h"
#include "NodoExpresion.h"
#include <string>
using namespace std;

int main(int argc, char* argv[]){

  // EJERCICIO 1 - Expresion prefija
  cout<<"EJERCICIO 1 "<<endl;
  cout<<endl;
  cout<<"1. Construir Arbol Expresion: "<<endl;
  cout<<"-*/5-7+113-+2+1*43*2-68"<< endl;

  // Crear arbol y construirlo desde expresion prefija
  ArbolExpresion* arbexp = new ArbolExpresion();
  string exp = "-*/5-7+113-+2+1*43*2-68";
  arbexp->llenarDesdePrefija(exp);

  // Imprimir recorrido posfijo
  cout<<"2. Imprimir Version Posfija = " << endl;
  arbexp->obtenerPosfija(arbexp->getRaiz());
  cout<<endl;

  // Evaluar el resultado de la expresion
  cout<<"3. Imprimir Resultado = " << endl;
  cout<<arbexp->evaluar(arbexp->getRaiz())<<endl;

  // EJERCICIO 2 - Expresion posfija
  cout<<"EJERCICIO 2"<<endl;
  cout<<endl;
  cout<<"1. Construir Arbol Expresion: "<<endl;
  ArbolExpresion* arbexp2 = new ArbolExpresion();
  cout<< "45+23+*6+87+/12+3*6+23+/*"<< endl;

  // Construir desde expresion posfija
  string exp2 = "45+23+*6+87+/12+3*6+23+/*";
  arbexp2->llenarDesdePosfija(exp2);

  // Imprimir recorrido prefijo
  cout<<"2. Imprimir Version Prefija = " << endl;
  arbexp2->obtenerPrefija(arbexp2->getRaiz());
  cout<<endl;

  // Evaluar la expresion
  cout<<"3. Imprimir Resultado = " << endl;
  cout<<arbexp2->evaluar(arbexp2->getRaiz())<<endl;

  return 0;
}
