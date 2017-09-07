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

unsigned bits(int x, int k, int j){
	return(x>>k) & ~(~0<<j);
} 

void cambioresiduos(int a[], int izq, int der, int b){
	int i, j, t;
	if(der>izq && b>=0){
		i = izq;
		j = der;
		while(j!=i){
			while(!bits(a[i], b, 1) && i<j) i++;
			while(bits(a[j], b, 1) && j>i) j--;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		if (!bits(a[i], b, 1)) j++;
		cambioresiduos(a, izq, j-1, b-1);
		cambioresiduos(a, j, der, b-1);	
	}
}

void muestraCadena(int tam, int a[]){
    int i;
    for(i = 0;i < tam;i++){
        cout<<a[i]<<endl;
    }
}

int main (){
	
	srand(time(NULL));
	LARGE_INTEGER t_ini, t_fin;
	double secs, milis, temp;
	int n = 0;
    
    ofstream fs("residuos.txt");
    for(int i = 0;i < 20;i++){
      	n = n + 5;
      	cout << "n : " << n << endl;
    	int a[n];
    	for(int j = 0;j < n;j++){
          	a[j] = 0 + rand()%(512 - 0);
      	}
      	
      	//cout << "arreglo" << endl;
      	//muestraCadena(n,a);
      	//cout << endl;
      	for(int i = 0;i < 100;i++){
      		QueryPerformanceCounter(&t_ini);
    			cambioresiduos(a, 0, n-1, 8);
    		QueryPerformanceCounter(&t_fin);
    		secs = performancecounter_diff(&t_fin, &t_ini) + secs;
    	}
      	
      	temp = secs/100;
		/* pasa a milisegundos */
		milis = temp * 1000.0;
		
		/* pasa a milisegundos */
		//fs << "n: " << n << " tiempo: "<< milis << endl;
		fs << milis << endl;
		//muestraCadena(n, a);
		//cout << endl;
    	}
    fs.close();
    return 0;
}
