#include <iostream>
#include "listadoble.h"

using namespace std;

int main(int argc, char** argv) {
	listad<int> lent;
	//Lista<char> lchar;

	nodo<int> *nuevo, *nuevo1, *nuevo2, *nuevo3, *nuevo4;
	//nodo<char> *nchar, *nchar1, *nchar2, *nchar3, *nchar4;
	
	//Creo nuevos nodos para ser ingresados en la lista
	nuevo = new nodo<int>;
	nuevo -> dato = 9;
	nuevo -> sig = NULL;
	nuevo -> ant = NULL;
	
	nuevo1 = new nodo<int>;
	nuevo1 -> dato = 8;
	nuevo1 -> sig = NULL;
	nuevo1 -> ant = NULL;
	
	nuevo2 = new nodo<int>;
	nuevo2 -> dato = 20;
	nuevo2 -> sig = NULL;
	nuevo2 -> ant = NULL;
	
	nuevo3 = new nodo<int>;
	nuevo3 -> dato = 12;
	nuevo3 -> sig = NULL;
	nuevo3 -> ant = NULL;
	
	nuevo4 = new nodo<int>;
	nuevo4 -> dato = 1;
	nuevo4 -> sig = NULL;
	nuevo4 -> ant = NULL;
	/*
	nchar = new nodo<char>;
	nchar -> dato = '*';
	nchar -> sig = NULL;
	nchar -> ant = NULL;
	
	nchar1 = new nodo<char>;
	nchar1 -> dato = '/';
	nchar1 -> sig = NULL;
	nchar1 -> ant = NULL;
	
	nchar2 = new nodo<char>;
	nchar2 -> dato = '@';
	nchar2 -> sig = NULL;
	nchar2 -> ant = NULL;
	
	nchar3 = new nodo<char>;
	nchar3 -> dato = ':';
	nchar3 -> sig = NULL;
	nchar3 -> ant = NULL;
	
	nchar4 = new nodo<char>;
	nchar4 -> dato = '?';
	nchar4 -> sig = NULL;
	nchar4 -> ant = NULL;
	*/

	//insertar al inicio de la lista
	lent.insertar_inicio(nuevo);
	lent.insertar_final(nuevo1);
	lent.insertar_final(nuevo2);
	lent.insertar_pos(nuevo3, 2);
	lent.insertar_inicio(nuevo4);
	
	cout<<"Tamaño lista : "<<lent.tam_lista()<<endl;

	for (int i = 1; i <= lent.tam_lista(); i++){
		cout<<lent.consultar(i)<<endl;
	}
	
	cout<<" ¿Lista vacia? "<<lent.lista_vacia()<<endl;
	
	lent.eliminar_pos(3);
	
	cout<<"Tamaño lista : "<<lent.tam_lista()<<endl;
	
	for (int i = 1; i <= lent.tam_lista(); i++){
		cout<<lent.consultar(i)<<endl;
	}
	
	cout<<" ¿Lista vacia? "<<lent.lista_vacia()<<endl;

	lent.eliminar_inicio();

	cout<<"Tamaño lista : "<<lent.tam_lista()<<endl;
	
	for (int i = 1; i <= lent.tam_lista(); i++){
		cout<<lent.consultar(i)<<endl;
	}
	
	cout<<" ¿Lista vacia? "<<lent.lista_vacia()<<endl;
	
	lent.eliminar_final();
	
	cout<<"Tamaño lista : "<<lent.tam_lista()<<endl;
	
	for (int i = 1; i <= lent.tam_lista(); i++){
		cout<<lent.consultar(i)<<endl;
	}
	
	cout<<" ¿Lista vacia? "<<lent.lista_vacia()<<endl;
	
	lent.eliminar_pos(2);
	
	cout<<"Tamaño lista : "<<lent.tam_lista()<<endl;
	
	for (int i = 1; i <= lent.tam_lista(); i++){
		cout<<lent.consultar(i)<<endl;
	}
	
	cout<<" ¿Lista vacia? "<<lent.lista_vacia()<<endl;
}
