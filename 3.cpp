#include <iostream>
#include <fstream>
#include <stdio.h>
//MCD
using namespace std;
int calcular(int a,int b){
  if (b==0) {
    return a;
  }else{
    return calcular(b,a%b);
  }
}
int main() {
  clock_t t;
  float temp;
  int n;
  ofstream fs("mcd.txt");
  for(int j=1;j<20;j++){
    n=n+5;
    for(int i=0;i<100;i++){
      t = clock();
      calcular(n,n*j);
      t = clock() - t;
      temp = (((float)t)/CLOCKS_PER_SEC) + temp;
    }
    fs << temp/100 << endl;
  }
  return 0;
}
