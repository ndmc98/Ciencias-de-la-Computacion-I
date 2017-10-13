#include <iostream>
#include "Multilista.h"

using namespace std;

int main(int argc, char** argv) {
	multi listest;
	string nombres[] = {"Raquel", "Jaime", "Arturo", "Andres", "Ariana", "Juanny", "Mary Paz", "Italia", "Mario", "Pilar"};
	string carreras[] = {"Electronica", "Industrial", "Electronica", "Catastral", "Sistemas", "Industrial", "Sistemas", "Catastral", "Sistemas", "Sistemas"};
	string hobbys[] = {"Danza", "Natacion", "Basket", "Danza", "Basket", "Natacion", "Danza", "Beisbol", "Basket", "Beisbol"};
	int edades[] = {21,18,16,24,18,17,25,22,20,23};
	string nombre, carrera, hobby;
	int edad;
	int i, j, longitud;
	
 	for(i=1;i<11;i++){
 		//cout<<"Ingrese nombre: ";
 		//cin>>nombre; 	
 		nombre = nombres[i-1];
 		//cout<<"Ingrese carrera: ";
 		//cin>>carrera;
 		carrera = carreras[i-1];
 		//cout<<"Ingrese edad: ";
 		//cin>>edad;
 		edad = edades[i-1];
 		//cout<<"Ingrese hobby: ";
 		//cin>>hobby;
		hobby = hobbys[i-1];
		listest.insertarEstudiante(nombre, carrera, edad, hobby, i);
 	}

 	listest.imprimir();
 	listest.imprimirNombre();
 	listest.imprimirEdad();

    return 0;
}
