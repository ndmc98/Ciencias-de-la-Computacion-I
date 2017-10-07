#include <iostream>
#include "listaenteros.h"

using namespace std;

int main(int argc, char** argv) {
    listae<int> lint;
    cout<< "tamaño0 : "<<lint.tam_lista()<<endl;
    lint.insertar_dato(9);
    cout<< "tamaño1 : "<<lint.tam_lista()<<endl;
    lint.insertar_dato(2);
    cout<< "tamaño2 : "<<lint.tam_lista()<<endl;
    lint.insertar_dato(10);
    lint.insertar_dato(11);
    lint.insertar_dato(1);
    cout<< "tamaño5 : "<<lint.tam_lista()<<endl;
    for(int i=0;i<5;i++){
        cout<<"Dato : "<<lint.consultar2(i)<<endl;
    }
}