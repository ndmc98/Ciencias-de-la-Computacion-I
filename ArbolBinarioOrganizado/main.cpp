#include <iostream>
#include "Arbol.h"
#include "Estructura.h"
using namespace std;

int main(){
    arbinor<int> a; nodo<int> *p;  int i;
    cout << "Número a insertar? (fin =999)..."<< endl;
    cin >> i;
    while(i!=999){
           if (a.insertar(i)==-1) cout<<"Ya existe"<< endl;
           cout << "Número a insertar? (fin =999)..."<< endl;
           cin >> i;
        }
    cout << "Número a retirar (fin=999)" << endl;
    cin>>i;
    while(i!=999){
           if (a.eliminar(i)==-1)cout << "No existe" << endl;
           cout << "Número a retirar (fin=999)" << endl;
           cin >> i;
        }
        a.inorden(a.reRaiz()); 
        a.preorden(a.reRaiz());
        a.posorden(a.reRaiz());
    return 0;
}