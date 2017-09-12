#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
//invierte la cadena
using namespace std;
int f(const char *const prts){
  if(prts[0]=='\0'){
    return 0;
  }else{
    f(&prts[1]);
    cout << prts[0] ;
  }
}
int main() {
  clock_t t;
  float temp;
  string n;
  string a[100];
  for (int i = 0; i < 100; i++) {
    a[i] = std::to_string(i);
    //std::cout << "number : "<< a[i] << '\n';
  }
  ofstream fs("invertir.txt");
  for(int i=1;i<100;i++){
    for(int j=0;j<i;j++){
      n=n+a[j];
    }
    cout << "n : " << n << endl;
    char *cstr = &n[0u];
    for(int i=0;i<100;i++){
      t = clock();
      f(cstr);
      t = clock() - t;
      temp = (((float)t)/CLOCKS_PER_SEC) + temp;
    }
    n="";
    fs << temp/100 << endl;
  }
  return 0;
}
