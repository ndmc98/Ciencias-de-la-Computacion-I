#include <iostream>
#include "pilaTemplate.h"

using namespace std;
 int main(){
     string pal;
     pilaT<char> pal2;
     int cont=0;
     cout << "ingrese una palabra : ";
     cin >> pal;
     for(int i=0;i<pal.size();i++){
        pal2.Push(pal[i]);
     }
     for(int i=0;i<pal.size();i++){
         char temp = pal2.Pop();
         if(pal[i]==temp){
             cont++;
             cout << pal[i] << " " << temp << "contador : " <<cont << endl;
         }
     }
     if(pal.size()==cont){
         cout << "palindroma ";
     }
     return 0;
 }