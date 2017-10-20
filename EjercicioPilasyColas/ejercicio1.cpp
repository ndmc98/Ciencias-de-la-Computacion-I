#include "pilaTemplate.h"
#include "colaTemplate.h"
#include <iostream>

using namespace std;

template <class T>
void reemplazar(T nuevo, T viejo, pilaT<T>& a);

int main(){
    pilaT<int> a;
    for(int i = 0;i < 20;i++){
        a.Push(i);
    }
    
    reemplazar(50, 13, a);
	return 0;
}

template <class T>
void reemplazar(T nuevo, T viejo, pilaT<T>& a){
    pilaT<T> aux;
    T temp;
    while(!a.PilaVaciaT()){
		temp = a.Pop();        
        if(temp == viejo){
            aux.Push(nuevo);
        }else{
            aux.Push(temp);
        }
	}
   
    while(!aux.PilaVaciaT()){
        a.Push(aux.Pop());
    }
    
    while(!a.PilaVaciaT()){
        cout<<a.Pop()<<endl; 
    }
}


