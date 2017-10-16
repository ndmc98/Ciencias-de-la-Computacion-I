#include <iostream>
#include "pilaTemplate.h"

using namespace std;
void quicksort(int a[],int izq, int der){
	int i, j, v, temp;
	if(der > izq){
		v = a[der];
		i = izq -1;
		j = der;
		for(;;){
			while(a[++i] < v);
			while(a[--j] > v);
			if(i >= j) break;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		temp = a[i];
		a[i] = a[der];
		a[der] = temp;
		quicksort(a, izq, i-1);
		quicksort(a, i+1, der);
    }
}    
int main(){
    pilaT<int> a;
    pilaT<int> b;
    pilaT<int> c;
    int *ar;
    int *br;
    int tama;
    int tamb;
    int cont=0;
    int i=0;
    a.Push(1);
    a.Push(5);
    a.Push(6);
    a.Push(7);
    b.Push(10);
    b.Push(9);
    b.Push(3);
    b.Push(2);
    while(!a.PilaVaciaT()){
        c.Push(a.Pop());
        cont++;
    }
    ar = new int[cont];
    while(!c.PilaVaciaT()){
        int temp = c.Pop();
        ar[i]=temp;
        cout << "c : "<< temp<<endl;
        a.Push(temp);
        i++;
    }
    tama= cont;
    cont = 0;
    i=0;
    while(!b.PilaVaciaT()){
        c.Push(b.Pop());
        cont++;
    }
    br = new int[cont];
    while(!c.PilaVaciaT()){
        int temp = c.Pop();
        br[i]=temp;
        cout << "c : "<< temp<<endl;
        b.Push(temp);
        i++;
    }
    tamb = cont;
    int total=tama+tamb;
    int totalar[total];
    for(int i=0;i<tama;i++){
        totalar[i]=ar[i];
        totalar[i+tama]=br[i];
    }
    quicksort(totalar, 0, total-1);
    for(int i=0;i<total;i++){
        cout << "arreglo : "<< totalar[i] << endl;
    }
    tama=total;
    for(int i=0;i<tama;i++){
        c.Push(totalar[i]);
    }
    while(!c.PilaVaciaT()){
        cout << "Pila Final : "<< c.Pop()<< endl;
    }
    return 0;
}