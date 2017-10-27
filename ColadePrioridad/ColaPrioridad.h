#include <cstdlib>
#include <iostream>
#include "estructuraCP.h"
#include "colaTemplate.h"
#include "pilaTemplate.h"
#ifndef colaPri
#define colaPri

using namespace std;
#define NULL __null

template <class T>
class colaPrioridad{
    nodoAP<T> *raiz;
public:
    colaPrioridad(){
        raiz = NULL;
        raiz -> izq = NULL;
        raiz -> der = NULL;
    }
    nodoAP<T> *reRaiz(){return raiz;};
    void insertar(nodoAP<T> in);
    T atender ();
};

template <class T>
void colaPrioridad<T>::insertar(nodoAP<T> in){
    pilaT<nodo<T> *ar> a;
    nodoAP<T> *aux;
    nodoAP<T> *aux2;
    bool hd =false;
    if(raiz == NULL){
        raiz = in;
    }else {
        aux = raiz;
        bool terniv=false;
        while(aux!=NULL){
            if(aux->izq == NULL){
                aux -> izq = in;
            }else if(aux-> der == NULL){
                aux -> der = in;
            }else{
                nodoAP<T> niveles[2];
                niveles[0]=aux -> izq;
                niveles[1]=aux -> der;
                a.Push(niveles);
                aux = aux -> izq;
            }
        }
    }
}
#endif