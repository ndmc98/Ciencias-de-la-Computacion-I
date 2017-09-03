#include <iostream>
#include <fstream>
#include <stdio.h>
#include <windows.h>

using namespace std;

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){
  
	LARGE_INTEGER freq;
  	QueryPerformanceFrequency(&freq);
  	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
  
}

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

void muestraCadena(int tam, int a[]){
    int i;
    for(i=0;i<tam;i++){
        cout<<a[i]<<endl;
    }
}

int main (){
	
	LARGE_INTEGER t_ini, t_fin;
	double secs, temp, milis;
	
    int n;
    ofstream fs("quicksortT.txt");
    for(int i=0;i<100;i++){
      	n=n+20;
      	//cout << "n : " << n << endl;
      	int a[n];
      	for(int j=0;j<n;j++){
        	a[j]=n-j;
      	}
      	//cout << "arreglo" << endl;
      	//muestraCadena(n,a);
      
      	for(int i=0;i<100;i++){
      	QueryPerformanceCounter(&t_ini);
    		quicksort(a, 0, n-1);
    	QueryPerformanceCounter(&t_fin);
    	secs = performancecounter_diff(&t_fin, &t_ini) + secs;
    	}
      	
		temp = secs/100;
		/* pasa a milisegundos */
		milis = temp * 1000.0;
		
		//cout << " n : " << n << " tiempo : " << secs * 1000.0 << endl;
		//fs << n << " : "<< temp * 1000.0 << endl;
		
		fs << milis << endl;
      	//muestraCadena(n,a);
    }
    fs.close();
    return 0;
}
