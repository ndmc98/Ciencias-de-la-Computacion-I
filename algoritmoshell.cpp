#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

void ordenShell(int A[],int n){
  int ints, i, aux;
  bool band;
  ints = n;
  while (ints > 1 ) {
    ints = (ints/2);
    band = true;
    while (band==true) {
      band=false;
      i=0;
      while ((i+ints)<=n) {
        if (A[i]>A[i+ints]) {
          aux=A[i];
          A[i]=A[i+ints];
          A[i+ints]=aux;
          band=true;
        }
        i++;
      }
    }
  }
}
void muestraCadena(int tam,int A[]){
    int i;
    for(i=0;i<tam;i++){
        cout<<A[i]<<endl;
    }
}

int main (){
    int n;
    clock_t t;
    float temp;
    ofstream fs("shell.txt");
    for(int i=0;i<1000;i++){
      n=n+20;
      cout << "n : " << n << endl;
      int A[n];
      for(int j=0;j<n;j++){
          A[j]=n-j;
      }
      //cout << "arreglo" << endl;
      //muestraCadena(n,A);
      t = clock();
      for(int i=0;i<100;i++){
        t = clock();
        ordenShell(A,n);
        t = clock() - t;
        temp = (((float)t)/CLOCKS_PER_SEC) + temp;
      }
      fs << " n : " << n << " tiempo : " << temp/100 << endl;
      //muestraCadena(n,A);
      std::cout << "n : " << n <<  '\n';
    }
    fs.close();
    return 0;
}
