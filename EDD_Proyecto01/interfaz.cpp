#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

//funcion que combierte el string del ususario en un vector de strings con los comandos
vector<string> userIn(){
	string in;
	cout<<"$ ";
	getline(cin, in);
	stringstream ss(in);
	vector<string> comando;
	while(ss >> in){
		comando.push_back(in);
	}
	
	return comando;

}

int main(int argc,char *argv[]){
	
	
	while(true){
		vector<string> comando = userIn();
	
		if (comando[0] == "exit"){
			cout<<"\nsaliendo\n";
			exit(0);
		}
		else if (comando[0] == "cargar_imagen" && comando.size() == 2){
			cout<<"\nse cargo "<<comando[1]<<" exitosamente\n"<<endl;
		}
		else if (comando[0] == "cargar_volumen" && comando.size() == 3){
			cout<<"\nse cargo "<<comando[1]<<" con "<<comando[2]<<" imagenes exitosamente\n"<<endl;
		}
		else if (comando[0] == "info_imagen" && comando.size() == 1){
			cout<<"\ninformacion de la imagen\n"<<endl;
		}
		else if (comando[0] == "proyeccion2D" && comando.size() == 4){
			cout<<"\nse cargo "<<comando[3]<<"\ndireccion: "<<comando[1]<<"\ncriterio: "<<comando[2]<<endl<<endl;
		}
		else if (comando[0] == "codificar_imagen" && comando.size() == 2){
			cout<<"\nse guardo la imagen "<<comando[1]<<" exitosamente\n"<<endl;
		}
		else if (comando[0] == "decodificar_archivo" && comando.size() == 3){
			cout<<"\nse decodifico "<<comando[1]<<" y se creo "<<comando[2]<<" exitosamente\n"<<endl;
		}
		else if (comando[0] == "segmentar" && comando.size() > 3){
			cout<<"\nse segmento "<<comando[1]<<" con las semillas: "<<comando[2]<<endl<<endl;
		}
		else if (comando[0] == "ayuda" && comando.size() == 1){
			cout<<"\n*****comandos*****\n"
			<<"cargar_imagen \n"
			<<"cargar_volumen \n"
			<<"info_imagen \n"
			<<"proyeccion2D \n"
			<<"codificar_imagen \n"
			<<"decodificar_archivo \n"
			<<"segmentar \n"
			<<"exit\n\n";
		}
		else if(comando[0] == "ayuda" && comando.size() > 1){		
		
			if (comando[1] == "cargar_imagen")
				cout<<"\ncargar_imagen (nombre_imagen)\n\n"
				<<"carga la imagen con el nombre dado en el sistema\n"<<endl;	
			else if (comando[1] == "cargar_ivolumen")
				cout<<"\ncargar_volumen (nombre_base) (n_im)\n\n"
				<<"carga imagenes con el mismo nombre base que esten enumeradas \n"
				<<"en orden ascendente (hasta 99 imagenes) con el nombre: nombrebaseXX\n"
				<<"donde n_im es el numero de imagenes del volumen\n"<<endl;
			else if (comando[1] == "info_imagen")
			        cout<<"\ninfo_imagen\n\n"
			        <<"muestra informacion basica de la imagen cargada\n"<<endl;
			else if (comando[1] == "proyeccion2D")
				cout<<"\nproyeccion2D (direccion) (criterio) (nombre_archivo.pgm)\n\n"
				<<"Genera la imagen basandose en la direccion la cual pueden ser:\n"
				<<"x (en dirección de las columnas), y (en dirección de las filas) o \n"
				<<"z (en dirección de la profundidad) La intensidad del color se define \n"
				<<"por criterio el cual puede ser: minimo, maximo , promedio o mediana\n"<<endl;
			else if (comando[1] == "codificar_imagen")
				cout<<"\ncodificar_imagen (nombre_archivo.huf)\n\n"
				<<"Se codifica y guarda la imagen en un archivo de nombre: nombre_archivo\n"<<endl;
			else if (comando[1] == "decodificar_archivo")
				cout<<"\ndecodificar_archivo (nombre_archivo.huf) (nombre_imagen.pgm)\n\n"
				<<"Se decodifica un archivo de nombre: nombre_archivo y se crea una imagen \n"
				<<"de nombre: nombre:_imagen\n"<<endl;
			else if (comando[1] == "segmentar")
				cout<<"\nsegmentar (salida_imagen.pgm) (sx1) (sy1) (sl1) ... (sx5) (sy5) (sl5)\n\n"
				<<"Se segmenta la imagen cargada en el sistema utilizando el algoritmo Dijkstra \n"
				<<"utilizando hasta cinco semillas con el formato: [x y] [numero], donde [x y] \n"
				<<"representa la posicion de un pixel en la imagen y [numero] un valor entre 0 \n"
				<<"y 255 el cual representa el color que se espera encontrar en esa cordenada\n"<<endl;
			else
				cout<<"\ncomando inexistente\n"<<endl;	
		}
		else{cout<<"\ncomando invalido\n"<<endl;}
	}


	return 0;

}
