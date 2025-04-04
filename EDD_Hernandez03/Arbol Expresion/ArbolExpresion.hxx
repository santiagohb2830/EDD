/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/

#include "ArbolExpresion.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Constructor: inicializa la raiz en NULL
ArbolExpresion::ArbolExpresion(){
	this->raiz=NULL;
}

// Destructor (vacio en esta implementacion)
ArbolExpresion::~ArbolExpresion(){
}

// Retorna la raiz del arbol
NodoExpresion* ArbolExpresion::getRaiz(){
	return this->raiz;
}

// Asigna la raiz del arbol
void ArbolExpresion::setRaiz(NodoExpresion* nod){
	this->raiz=nod;
	return;
}

// Funcion que evalua el resultado del arbol de expresion
int ArbolExpresion::evaluar(NodoExpresion* nodi){
	if(nodi->getHijoIzq()==NULL&&nodi->getHijoDer()==NULL){
		// Si es hoja, se convierte el caracter en entero
		return (int)(nodi->getDato()-48);
	}else{
		int resultado=0;
		int izquierda=evaluar(nodi->getHijoIzq());
		int derecha=evaluar(nodi->getHijoDer());
		char operando=nodi->getDato();

		// Se aplica el operador correspondiente
		switch (operando) {
			case '+':
				resultado=izquierda+derecha;
				break;
			case '-':
				resultado=izquierda-derecha;
				break;
			case '*':
				resultado=izquierda*derecha;
				break;
			case '/':
				resultado=izquierda/derecha;
				break;
			default:
				resultado=izquierda+derecha;
				break;
		}
		return resultado;
	}
}

// Construye el arbol a partir de una expresion prefija
void ArbolExpresion::llenarDesdePrefija(string &expresion){
	char cad[expresion.size()];
	strcpy(cad,expresion.c_str());

	stack<NodoExpresion* > miCola;
	NodoExpresion* n1;
	NodoExpresion* n2;
	NodoExpresion* n3;

	// Se recorre la expresion de derecha a izquierda
	for(int i=strlen(cad)-1;i>=0;i--){
		if(!siOperando(cad[i])){
			// Si es operador, se crea nodo y se agrega a la pila
			n1=new NodoExpresion();
			n1->setDato(cad[i]);
			miCola.push(n1);
		}else{
			// Si es operando, se crean nodos hijos y se enlazan
			n1=new NodoExpresion();
			n1->setDato(cad[i]);

			n2=miCola.top();
			miCola.pop();
			n3=miCola.top();
			miCola.pop();

			n1->setHijoDer(n2);
			n1->setHijoIzq(n3);

			miCola.push(n1);
		}
	}
	n1=miCola.top();
	this->setRaiz(n1);
	miCola.pop();
}

// Construye el arbol a partir de una expresion posfija
void ArbolExpresion::llenarDesdePosfija(string &expresion){
	char cad[expresion.size()];
	strcpy(cad,expresion.c_str());

	stack<NodoExpresion* > miCola;

	NodoExpresion* n1;
	NodoExpresion* n2;
	NodoExpresion* n3;

	// Se recorre la expresion de izquierda a derecha
	for(int i=0;i<strlen(cad);i++){
		if(!siOperando(cad[i])){
			// Si es operador, se crea y se agrega a la pila
			n1=new NodoExpresion();
			n1->setDato(cad[i]);
			miCola.push(n1);
		}else{
			// Si es operando, se crean nodos hijos y se enlazan
			n1=new NodoExpresion();
			n1->setDato(cad[i]);

			n2=miCola.top();
			miCola.pop();
			n3=miCola.top();
			miCola.pop();

			n1->setHijoDer(n2);
			n1->setHijoIzq(n3);

			miCola.push(n1);
		}
	}
	n1=miCola.top();
	this->setRaiz(n1);
	miCola.pop();
}

// Imprime la expresion en notacion prefija
void ArbolExpresion::obtenerPrefija(NodoExpresion* inicio){
	if(inicio==NULL){
		return;
	}else{
		cout<<inicio->getDato()<<" ";
		this->obtenerPrefija(inicio->getHijoIzq());
		this->obtenerPrefija(inicio->getHijoDer());
	}
}

// Imprime la expresion en notacion infija
void ArbolExpresion::obtenerInfija(NodoExpresion* inicio){
	if(this->raiz!=NULL){
		if(inicio->getHijoIzq()!=NULL){
			obtenerInfija(inicio->getHijoIzq());
		}
		cout << inicio->getDato()<<" ";
		if(inicio->getHijoDer()!=NULL){
			obtenerInfija(inicio->getHijoDer());
		}
	}else{
		cout << "El arbol esta vacio" << '\n';
	}
}

// Imprime la expresion en notacion posfija
void ArbolExpresion::obtenerPosfija(NodoExpresion* inicio){
	if(inicio==NULL){
		return;
	}else{
		this->obtenerPosfija(inicio->getHijoIzq());
		this->obtenerPosfija(inicio->getHijoDer());
		cout<<inicio->getDato()<<" ";
	}
}

// Verifica si un caracter es un operando (digito u operacion aritmetica)
bool ArbolExpresion::siOperando(char car){
	if(car=='+'||car=='-'||car=='/'||car=='*'||car=='%'){
		return true;
	}else{
		return false;
	}
}
