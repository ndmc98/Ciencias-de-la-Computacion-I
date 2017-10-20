#include <iostream>
#include "pilaTemplate.h"

using namespace std;

int simulafactorial(int n){
	pilaT<int> s;
	long int factorial;
	while(n != 0){
		s.Push(n);
		n--;
	}
	factorial = 1;
	while(!s.PilaVaciaT()){
		factorial *= s.Pop();
	}
	return factorial;
}

int main(){
	int n;
	cout <<"Ingrese un número : ";
    cin >> n;
    cout<<" Factorial de "<< n <<" : "<<simulafactorial(n)<<endl;
	return 0;
}
