#include <iostream>
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include <fstream>

using namespace std;

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){
  
	LARGE_INTEGER freq;
  	QueryPerformanceFrequency(&freq);
  	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
  
}

int mayor(int num[], int pos){
	int aux;
    if(pos == 0){
    	return num[pos];
	} else {
		aux = mayor(num, pos - 1);
		if(num[pos] > aux){
			return num[pos];
		} else {
			return mayor(num, pos -1);
		}
	}
}

void muestraCadena(int tam, int a[]){
    int i;
    for(i = 0;i < tam;i++){
    	cout<<a[i]<<endl;
    }
}

int main(){
	
    int n = 0;
    LARGE_INTEGER t_ini, t_fin;
	double secs = 0, milis, temp;
    
    ofstream fs("Code2.txt");
    for(int i = 0;i < 20;i++){
      	n = n + 1;
      	cout << "n : " << n << endl;
		int num[n];
		
		for(int j = 0;j < n; j++){
			num[j] = j;
		}
		
		//muestraCadena(n, num);
		//cout << endl;

      	for(int i = 0;i < 100;i++){
      		QueryPerformanceCounter(&t_ini);
     			mayor(num, n-1);
    		QueryPerformanceCounter(&t_fin);
    		secs = performancecounter_diff(&t_fin, &t_ini) + secs;
    	}
      	
      	temp = secs/100;
		/* pasa a milisegundos */
		milis = temp * 1000.0;
		
		//fs << "n: " << n << " tiempo: "<< milis << endl;
		fs << milis << endl;
		//muestraCadena(n, a);
    	}
    fs.close();    
    return 0;
}
