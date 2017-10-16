#ifndef PILATEMPLATE    
#define PILATEMPLATE    
#include "EstructuraTemplate.h"
#define NULL __null

template <class T>
class pilaT{
      nodo<T> *cab;
      public: pilaT(){
          cab= new nodo<T>;
          cab->sig=NULL;}
        void Push( T v);
        T Pop();
        bool PilaVaciaT();
             ~pilaT();
};

template <class T> 
void pilaT<T>::Push(T v){
     nodo<T> *t = new nodo<T>;
     t->dato=v; 
     t->sig=cab->sig;
     cab->sig= t;
}

template <class T>
T pilaT<T>::Pop(){
     T x;
     nodo<T> *t= cab->sig;
     cab->sig= t->sig; 
     x=t->dato;
     delete t;
     return x;
}

template <class T>
bool pilaT<T>::PilaVaciaT(){
      return cab->sig== NULL;
}

template <class T>
 pilaT<T>::~pilaT(){
      nodo<T> *t=cab;
     while (t!=NULL){
           cab=t;
           t=t->sig;
           delete cab;
           }
}

#endif
