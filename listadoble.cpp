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
	
	a.nombre = "Marta";
	a.codigo = 2018043;
	a.carrera = "Industrial";
	
	lestud.insertar_final(a);
	
	i = 1;
	while(i <= lestud.tam_lista()){
		a = lestud.consultar(i);
		cout<<a.nombre<<" ";
		i++;
	}
	
	/*
	lint.insertar_final(3);
	lint.insertar_inicio(8);
	lint.insertar_pos(10, 2);

	lfloat.insertar_inicio(3.5);
	lfloat.insertar_final(8.2);
	lfloat.insertar_pos(3.8, 2);	
	
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
	}
	*/
	
}
