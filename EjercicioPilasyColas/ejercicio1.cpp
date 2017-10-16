#include "pilaTemplate.h"
#include "colaTemplate.h"
#include <iostream>

template <class T>
void reemplazar(T nuevo,T viejo,pilaT<T> a){
    pilaT<T> aux;
    while(!a.PilaVaciaT()){
        T temp = a.Pop();
        if(temp==viejo){
            aux.Push(nuevo);
        }else{
            aux.Push(temp);
        }
    }
    while(!aux.PilaVaciaT()){
        cout << "Pila Final re : "<< aux.Pop()<< endl;
    }
    while(!aux.PilaVaciaT()){
        a.Push(aux.Pop());
    }
}

using namespace std;

int main(){
    pilaT<int> a;
    pilaT<int> b;
    for(int i=0;i<20;i++){
        a.Push(i);
    }
    //reemplazar(50,10,a);
    //Codigo de la funcion --------
    pilaT<int> aux;
    int viejo=10;
    int nuevo= 50;
    while(!a.PilaVaciaT()){
        int temp = a.Pop();
        if(temp==viejo){
            aux.Push(nuevo);
        }else{
            aux.Push(temp);
        }
    }
    while(!aux.PilaVaciaT()){
        a.Push(aux.Pop());
    }
    //------------------------------
    // al ponerlo en la funcion genera un problema por dejar elementos vacios
    while(!a.PilaVaciaT()){
        cout << "Pila Final : "<< a.Pop()<< endl;
    }
}