/************************************************
* Fecha 28 de Marzo 2025                    	*
* Autor: Santiago Hernandez, Juan Esteban Bello *
* Materia: Estructuras de Datos             	*
* Tema: Taller Arboles                      	*
************************************************/

#include "ArbolBinarioAVL.h"
#include <queue>

using namespace std;

//constructor vacio
template <class T>
ArbolBinarioAVL<T>::ArbolBinarioAVL(){
	this->raiz=NULL;
}

template <class T>
ArbolBinarioAVL<T>::~ArbolBinarioAVL(){
}

//contructor con parametros
template <class T>
void ArbolBinarioAVL<T>::setRaiz(NodoBinarioAVL<T>* raiz){
	this->raiz=raiz;
	return;
}

//getter de raiz
template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::getRaiz(){
	return this->raiz;
}

//funcion que valida si el arbol esta vacio
template <class T>
bool ArbolBinarioAVL<T>::esVacio(){
	if(this->raiz==NULL){
		return true;
	}
	return false;
}

//getter de dato raiz
template <class T>
T& ArbolBinarioAVL<T>::datoRaiz(){
	return (this->raiz)->getDato();
}

//funcion que calcula la altura de un subtree
template <class T>
int ArbolBinarioAVL<T>::altura(NodoBinarioAVL<T> *inicio){
	int alturaIzq=0;
	int alturaDer=0;
	if(inicio==NULL){
		return -1;
	}
	if(inicio->getHijoIzq()==NULL && inicio->getHijoDer()==NULL){
		return 0;
	}
	if(inicio->getHijoIzq()!=NULL){
		alturaIzq+=altura(inicio->getHijoIzq())+1;
	}
	if(inicio->getHijoDer()!=NULL){
		alturaDer+=altura(inicio->getHijoDer())+1;
	}
	if(alturaIzq>alturaDer){
		return (alturaIzq);
	}else{
		return (alturaDer);
	}
}

//funcio que cuanta los nodos de un sub-tree
template <class T>
int ArbolBinarioAVL<T>::tamano(NodoBinarioAVL<T> *inicio){
	int nodosIzq=0;
	int nodosDer=0;
	if(inicio==NULL){
		return 0;
	}
	if(inicio->getHijoIzq()==NULL && inicio->getHijoDer()==NULL){
		return 1;
	}
	if(inicio->getHijoIzq()!=NULL){
		nodosIzq+=tamano(inicio->getHijoIzq());
	}
	if(inicio->getHijoDer()!=NULL){
		nodosDer+=tamano(inicio->getHijoDer());
	}
	return nodosIzq+nodosDer+1;
}

//funcion que maneja el giro derecha
template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroDerecha(NodoBinarioAVL<T>* &padre){
	NodoBinarioAVL<T> *n_padre=padre->getHijoIzq();
	padre->setHijoIzq(n_padre->getHijoDer());
	n_padre->setHijoDer(padre);
	return n_padre;
}

//funcion que maneja el giro izquierda
template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroIzquierda(NodoBinarioAVL<T>* &padre){
	NodoBinarioAVL<T> *n_padre=padre->getHijoDer();
	padre->setHijoDer(n_padre->getHijoIzq());
	n_padre->setHijoIzq(padre);
	return n_padre;
}

//funcion que maneja el giro izquierda derecha
template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroIzquierdaDerecha(NodoBinarioAVL<T>* &padre){
	NodoBinarioAVL<T> **primGiro=&(padre->hijoIzq);
	padre->setHijoIzq(giroIzquierda(*primGiro));
	return giroDerecha(padre);
}

//funcion que maneja el giro derecha izquierda
template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroDerechaIzquierda(NodoBinarioAVL<T>* &padre){
	NodoBinarioAVL<T> **primGiro=&(padre->hijoDer);
	padre->setHijoDer(giroDerecha(*primGiro));
	return giroIzquierda(padre);
}

//metodo de insercion recursiva con valaceo
template <class T>
bool ArbolBinarioAVL<T>::insertar(T& val){
	NodoBinarioAVL<T> *nodoActual=this->raiz;
	NodoBinarioAVL<T> *nNodo=new NodoBinarioAVL<T>();
	NodoBinarioAVL<T> *n_padre, *n_padre2;
	bool nodoInsertado,valorTomado=false;
	while(!valorTomado){
		if(nodoActual==NULL){
			nNodo->setDato(val);
			(this->raiz)=nNodo;
			nodoActual=this->raiz;
			nodoInsertado=true;
			valorTomado=true;
			break;
		}
		else if(val==nodoActual->getDato()){
			nodoInsertado=false;
			valorTomado=true;
			break;
		}
		else if(val>nodoActual->getDato() && nodoActual->getHijoDer()==NULL){
			nNodo->setDato(val);
			nodoActual->setHijoDer(nNodo);
			nodoInsertado=true;
			valorTomado=true;
			break;
		}
		else if(val<nodoActual->getDato() && nodoActual->getHijoIzq()==NULL){
			nNodo->setDato(val);
			nodoActual->setHijoIzq(nNodo);
			nodoInsertado=true;
			valorTomado=true;
			break;
		}
		
		if(val>nodoActual->getDato()){
			nodoActual=nodoActual->getHijoDer();
		}else{
			nodoActual=nodoActual->getHijoIzq();
		}

	}
	if(nodoInsertado){
		NodoBinarioAVL<T> **nBalanceo=&(this->raiz);
		while((*nBalanceo)!=NULL){
			if(altura((*nBalanceo)->getHijoIzq())-altura((*nBalanceo)->getHijoDer())>1 && altura(((*nBalanceo)->getHijoIzq())->getHijoIzq())>altura(((*nBalanceo)->getHijoIzq())->getHijoDer())){
				*nBalanceo=giroDerecha(*nBalanceo);
			}else if(altura((*nBalanceo)->getHijoIzq())-altura((*nBalanceo)->getHijoDer())>1 && altura(((*nBalanceo)->getHijoIzq())->getHijoIzq())<altura(((*nBalanceo)->getHijoIzq())->getHijoDer())){
				*nBalanceo=giroIzquierdaDerecha(*nBalanceo);
			}else if(altura((*nBalanceo)->getHijoDer())-altura((*nBalanceo)->getHijoIzq())>1 && altura(((*nBalanceo)->getHijoDer())->getHijoDer())>altura(((*nBalanceo)->getHijoDer())->getHijoIzq())){
				*nBalanceo=giroIzquierda(*nBalanceo);
			}else if(altura((*nBalanceo)->getHijoDer())-altura((*nBalanceo)->getHijoIzq())>1 && altura(((*nBalanceo)->getHijoDer())->getHijoDer())<altura(((*nBalanceo)->getHijoDer())->getHijoIzq())){
				*nBalanceo=giroDerechaIzquierda(*nBalanceo);
			}
			
			if((*nBalanceo)->getDato()<val){
				nBalanceo=&((*nBalanceo)->hijoDer);
			}else{
				nBalanceo=&((*nBalanceo)->hijoIzq);
			}
		} 
	}
	return nodoInsertado;
}

//funcion recursiva de eliminacion y valanceo
template <class T>
bool ArbolBinarioAVL<T>::eliminar(T& val){
	NodoBinarioAVL<T> *buscaNodo=this->raiz;
	if(this->raiz==NULL){
		return false;
	}else{
		while(buscaNodo->getHijoDer()!=NULL || buscaNodo->getHijoIzq()!=NULL || buscaNodo->getDato()==val){
			if(buscaNodo->getDato()==val){
				if(buscaNodo->getHijoDer()==NULL && buscaNodo->getHijoIzq()==NULL){
					NodoBinarioAVL<T> *buscaNodo3=this->raiz;
					if(this->raiz==buscaNodo){
						this->raiz=NULL;
					}
					else{
						while(buscaNodo3->getHijoIzq()!=NULL || buscaNodo3->getHijoDer()!=NULL){
							if(buscaNodo3->getHijoIzq()!=NULL){
								if((buscaNodo3->getHijoIzq())->getDato()==buscaNodo->getDato()){
									buscaNodo3->setHijoIzq(NULL);
									break;
								}
							}
							if(buscaNodo3->getHijoDer()!=NULL){
								if((buscaNodo3->getHijoDer())->getDato()==buscaNodo->getDato()){
									buscaNodo3->setHijoDer(NULL);
									break;
								}
							}
							if(buscaNodo->getDato()>buscaNodo3->getDato()){
								buscaNodo3=buscaNodo3->getHijoDer();
							}else{
								buscaNodo3=buscaNodo3->getHijoIzq();
							}
						}
					}
					delete(buscaNodo);
				}else if(buscaNodo->getHijoDer()==NULL){
					*(buscaNodo)=*(buscaNodo->getHijoIzq());
				}else if(buscaNodo->getHijoIzq()==NULL){
					*(buscaNodo)=*(buscaNodo->getHijoDer());
				}else{
					NodoBinarioAVL<T> *buscaNodo2=buscaNodo->getHijoIzq();
					while(buscaNodo2->getHijoDer()!=NULL){
						buscaNodo2=buscaNodo2->getHijoDer();
					}
					buscaNodo->setDato(buscaNodo2->getDato());
					if(buscaNodo2->getHijoIzq()==NULL){
						if((buscaNodo->getHijoIzq())->getHijoDer()!=NULL){
							NodoBinarioAVL<T> *buscaNodo3=buscaNodo->getHijoIzq();
							while((buscaNodo3->getHijoDer())->getDato()!=buscaNodo2->getDato()){
								buscaNodo3=buscaNodo3->getHijoDer();
							}
							buscaNodo3->setHijoDer(NULL);
						}else{
							buscaNodo->setHijoIzq(NULL);
						}
						delete(buscaNodo2);
					}else{
						*(buscaNodo2)=*(buscaNodo2->getHijoIzq());
					}
				}
				NodoBinarioAVL<T> **nBalanceo=&(this->raiz);
				while((*nBalanceo)!=NULL){
					if(altura((*nBalanceo)->getHijoIzq())-altura((*nBalanceo)->getHijoDer())>1 && altura(((*nBalanceo)->getHijoIzq())->getHijoIzq())>altura(((*nBalanceo)->getHijoIzq())->getHijoDer())){
						*nBalanceo=giroDerecha(*nBalanceo);
					}else if(altura((*nBalanceo)->getHijoIzq())-altura((*nBalanceo)->getHijoDer())>1 && altura(((*nBalanceo)->getHijoIzq())->getHijoIzq())<altura(((*nBalanceo)->getHijoIzq())->getHijoDer())){
						*nBalanceo=giroIzquierdaDerecha(*nBalanceo);
					}else if(altura((*nBalanceo)->getHijoDer())-altura((*nBalanceo)->getHijoIzq())>1 && altura(((*nBalanceo)->getHijoDer())->getHijoDer())>altura(((*nBalanceo)->getHijoDer())->getHijoIzq())){
						*nBalanceo=giroIzquierda(*nBalanceo);
					}else if(altura((*nBalanceo)->getHijoDer())-altura((*nBalanceo)->getHijoIzq())>1 && altura(((*nBalanceo)->getHijoDer())->getHijoDer())<altura(((*nBalanceo)->getHijoDer())->getHijoIzq())){
						*nBalanceo=giroDerechaIzquierda(*nBalanceo);
					}
			
					if((*nBalanceo)->getDato()<val){
						nBalanceo=&((*nBalanceo)->hijoDer);
					}else{
						nBalanceo=&((*nBalanceo)->hijoIzq);
					}
				} 
				return true;
			}else if(val<buscaNodo->getDato() && buscaNodo->getHijoIzq()!=NULL){
				buscaNodo=buscaNodo->getHijoIzq();
			}else if(val>buscaNodo->getDato() && buscaNodo->getHijoDer()!=NULL){
				buscaNodo=buscaNodo->getHijoDer();
			}else if(val<buscaNodo->getDato() && buscaNodo->getHijoIzq()==NULL){
				return false;
			}else if(val>buscaNodo->getDato() && buscaNodo->getHijoDer()==NULL){
				return false;
			}
		}
	}
	return false;
}

//funcion recursiva para buscar un nodo
template <class T>
bool ArbolBinarioAVL<T>::buscar(T& val){
	NodoBinarioAVL<T> *buscaNodo=this->raiz;
	if(this->raiz==NULL){
		return false;
	}else{
		while(buscaNodo->getHijoDer()!=NULL || buscaNodo->getHijoIzq()!=NULL || buscaNodo->getDato()==val){
			if(buscaNodo->getDato()==val){
				return true;
			}else{
				if(val>buscaNodo->getDato() && buscaNodo->getHijoDer()!=NULL){
					buscaNodo=buscaNodo->getHijoDer();
				}else if(val<buscaNodo->getDato() && buscaNodo->getHijoIzq()!=NULL){
					buscaNodo=buscaNodo->getHijoIzq();
				}else if(val>buscaNodo->getDato() && buscaNodo->getHijoDer()==NULL){
					return false;
				}else{
					return false;
				}
			}
		}
		return false;
	}
}

//funcion imprime arbol en preOrder (DLR)
template <class T>
void ArbolBinarioAVL<T>::preOrden(NodoBinarioAVL<T> *inicio){
	cout<<inicio->getDato()<<" ";
	if(inicio->getHijoIzq()!=NULL){
		preOrden(inicio->getHijoIzq());
	}
	if(inicio->getHijoDer()!=NULL){
		preOrden(inicio->getHijoDer());
	}
	return;
}

//funcion imprime arbol en inOrder (LDR)
template <class T>
void ArbolBinarioAVL<T>::inOrden(NodoBinarioAVL<T> *inicio){
	if(inicio->getHijoIzq()!=NULL){
		inOrden(inicio->getHijoIzq());
	}
	cout<<inicio->getDato()<<" ";
	if(inicio->getHijoDer()!=NULL){
		inOrden(inicio->getHijoDer());
	}
	return;
}

//funcion imprime arbol en posOrder (LRD)
template <class T>
void ArbolBinarioAVL<T>::posOrden(NodoBinarioAVL<T> *inicio){
	if(inicio->getHijoIzq()!=NULL){
		posOrden(inicio->getHijoIzq());
	}
	if(inicio->getHijoDer()!=NULL){
		posOrden(inicio->getHijoDer());
	}
	cout<<inicio->getDato()<<" ";
	return;
}

//funcion imprime arbol por nivel
template <class T>
void ArbolBinarioAVL<T>::nivelOrden(NodoBinarioAVL<T> *inicio){
	queue<NodoBinarioAVL<T>> colaNivel;
	NodoBinarioAVL<T> nodo;
	colaNivel.push(*inicio);
	while(!colaNivel.empty()){
		nodo=colaNivel.front();
		colaNivel.pop();
		cout<<nodo.getDato()<<" ";
		if(nodo.getHijoIzq()!=NULL){
			colaNivel.push(*nodo.getHijoIzq());
		}
		if(nodo.getHijoDer()!=NULL){
			colaNivel.push(*nodo.getHijoDer());
		}
	}
	return;
}
