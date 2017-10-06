#include <iostream>
#include "listadoble.h"

using namespace std;

struct estud{
	string nombre;
	long int codigo;
	string carrera;
};

int main(int argc, char** argv) {
	int i;
	listad<int> lint;
	listad<float> lfloat;
	listad<estud> lestud;
	estud a;
	
	a.nombre = "Pedro";
	a.codigo = 2018004;
	a.carrera = "Sistemas";
	
	lestud.insertar_pos(a, 1);

	a.nombre = "Luis";
	a.codigo = 2018040;
	a.carrera = "Electronica";
	
	lestud.insertar_inicio(a);

	a.nombre = "andres";
	a.codigo = 2018040;
	a.carrera = "Electronica";

	lestud.insertar_inicio(a);

	a.nombre = "Marta";
	a.codigo = 2018043;
	a.carrera = "Industrial";

	lestud.insertar_pos(a,2);
	/*
	i = 1;
	while(i <= lestud.tam_lista()){
		a = lestud.consultar(i);
		cout<<a.nombre<<" ";
		i++;
		cout<<endl;
	}
*/
	lint.insertar_final(3);
	lint.insertar_inicio(8);
	lint.insertar_pos(10, 2);
	//cout<<"tamaño : "<<lint.tam_lista();
	lfloat.insertar_inicio(3.5);
	lfloat.insertar_final(8.2);
	lfloat.insertar_pos(3.8, 2);	
	
	while(i <= lint.tam_lista()){
		cout<<"primera revision : "<<lint.consultar(i)<<" ";
		i++;
		cout<<endl;
	}
	while(i <= lfloat.tam_lista()){
		cout<<"primera revision : "<<lfloat.consultar(i)<<" ";
		i++;
		cout<<endl;
	}
	/*for(int i=0;i<lint.tam_lista();i++){
		cout<< "dato : "<<lint.consultar(i)<<endl; 
	}*/
	/*
	i = 1;
	while(!lint.lista_vacia()){
		cout<<lint.eliminar_pos(i)<<" ";
		i++;
	}
	
	cout<<endl;
	i = 1;
	while(!lfloat.lista_vacia()){
		cout<<lfloat.eliminar_pos(i)<<" ";
		i++;
	}*/
}
