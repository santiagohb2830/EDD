/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/

#include<iostream>
#include<set>
#include<map>
#include "kdtree.h"
#include "kdnodo.h"

using namespace std;

int main(int argc, char* argv[])
{
   /*cout<<"ARBOL BINARIO ORDENADO"<<endl;
    cout<<"****************************************************************"<<endl;
    kdtree<int> arbolito;
	for(int i=0; i<15; i++)
	{
	    cout<<"Inserte dato: ";
		int dato;
		cin>>dato;
		arbolito.insertar(dato);
	}*/
	kdtree<int> arbolito;
	vector<int> 	v1 = {1,2,3},
			v2 = {4,5,6,44},
			v3 = {9,8,7},
			v4 = {2,9};
	arbolito.insertar(v1);
	arbolito.insertar(v2);
	arbolito.insertar(v3);
	arbolito.insertar(v4);

	
	cout<<"In Orden:"<<endl;
	arbolito.inOrden();
	cout<<endl;
	/*cout<<"Pre Orden:"<<endl;
	arbolito.preOrden();
	cout<<endl;
	cout<<"Pos Orden: "<<endl;
	arbolito.posOrden();
	cout<<endl;*/

	return 0;
}
