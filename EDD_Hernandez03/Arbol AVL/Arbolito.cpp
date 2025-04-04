/************************************************
* Fecha 28 de Marzo 2025			*
* Autor: Santiago Hernandez, Juan Esteban Bello	*
* Materia: Estructuras de Datos			*
* Tema: Taller Arboles				*
************************************************/

#include<iostream>
#include "ArbolBinarioAVL.h"		//correccion nombre de librerias
#include "NodoBinarioAVL.h"

using namespace std;

int main(int argc, char* argv[])
{
    ArbolBinarioAVL<int> arbolito;
	while(true)
	{
		int dato;
		char op;
		cin>>op>>dato;			//recibe que operacion desearealizar y que parametro
		
		if(op == 'A')
			arbolito.insertar(dato);
		else if(op == 'E')
			arbolito.eliminar(dato);
		else
			break;
	}
	
	//imprimir inorder,preorder,posorder
	cout << endl << "Inorden: " << endl;
	arbolito.inOrden(arbolito.getRaiz());
	cout << endl << "Preorden: " << endl;
	arbolito.preOrden(arbolito.getRaiz());
	cout << endl <<"Posorden: " << endl;
	arbolito.posOrden(arbolito.getRaiz());
	
	return 0;
}
