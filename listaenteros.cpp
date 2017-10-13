#include <iostream>
#include "listaenteros.h"

using namespace std;

int main() {
    listae lint;
    listae lo;
	
    lint.insertar_dato(100);
    lint.insertar_dato(102);
	lint.insertar_dato(82);
	lint.insertar_dato(11);
    lint.insertar_dato(3);
    lint.insertar_dato(9);
    lint.insertar_dato(4);
    lint.insertar_dato(1);
    lint.insertar_dato(0);
    lint.insertar_dato(20);
    lint.insertar_dato(12);
    lint.insertar_dato(2);
    lint.insertar_dato(10);
	
    cout<< "tama�o0 : "<<lint.tam_lista()<<endl;
    
	for(int i = 1;i <= lint.tam_lista();i++){
		cout<<lint.consultar(i)<<endl;
	}
}
