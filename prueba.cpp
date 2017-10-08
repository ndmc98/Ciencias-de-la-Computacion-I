#include <iostream>
#include "listaenteros.h"

using namespace std;

int main() {
    listae<int> lint;
    lint.insertar_dato(3);
    lint.insertar_dato(9);
    lint.insertar_dato(4);
    lint.insertar_dato(1);
    lint.insertar_dato(0);
    lint.insertar_dato(20);
    cout<< "tamaño0 : "<<lint.tam_lista()<<endl;
    lint.insertar_dato(11);
    
    cout<< "tamaño1 : "<<lint.tam_lista()<<endl;
    lint.insertar_dato(12);
    lint.insertar_dato(2);
    lint.insertar_dato(10);
    cout<< "tamaño2 : "<<lint.tam_lista()<<endl;
    cout<< "tamaño4 : "<<lint.tam_lista()<<endl;
    cout<< "tamaño5 : "<<lint.tam_lista()<<endl;
    for(int i=0;i<lint.tam_lista();i++){
        cout<<"Dato : "<<lint.consultar2(i)<<endl;
    }
    for(int i=0;i<lint.tam_lista();i++){
        cout<<"arreglo : "<<lint.consultar3(i)<<endl;
    }
    for(int i=0;i<lint.tam_lista();i++){
        cout<<"arreglo o: "<<lint.consultar3(i)<<endl;
    }
}