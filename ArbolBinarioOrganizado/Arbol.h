#include <cstdlib>
#include <iostream>
#include "Estructura.h"

#ifndef arbol
#define arbol

using namespace std;
#define NULL __null

template <class T>
class arbinor{
    nodo<T> *raiz;
    public:
        arbinor(){
            raiz = NULL;
        }
        nodo<T> *reRaiz(){return raiz;};
        int insertar (T dato);
        nodo<T> *buscar_arbol(T dato, nodo<T> *p,nodo<T> *q);
        int eliminar(T dato);
        void borrar_nodo(nodo<T> *p,nodo<T> *q);
        string buscarP(T dato);
        nodo<T> *buscar(T dato,nodo<T> **p,nodo<T> *q);
        void inorden(nodo<T> *p);
        void preorden(nodo<T> *p);
        void posorden(nodo<T> *p);
        T inordenP(nodo<T> *p);
        T preordenP(nodo<T> *p);
        T posordenP(nodo<T> *p);
 };
template <class T>
nodo<T> *arbinor<T>::buscar_arbol(T dato, nodo<T> *p,nodo<T> *q){
    if (p==NULL){
        return q;
    } 
    if (dato < p->info){
        q=p;
        q=buscar_arbol(dato,p->izq,q);
        return q;
    }else if (dato > p->info) {
        q=p;
        q=buscar_arbol(dato,p->der,q);
        return q;
    }else return NULL;
}
template <class T>
nodo<T> *arbinor<T>::buscar(T dato,nodo<T> **p,nodo<T> *q){
    if (*p==NULL) return NULL;
	if (dato <(*p)->info){
	          q=*p;
	           *p=(*p)->izq;
	          q=buscar(dato,p,q);
	          return q;}
	else if (dato>(*p)->info){
		q=*p;
		*p=(*p)->der;
		q =buscar(dato,p,q);
		return q;}
	       else return q;
}
template <class T>
int arbinor<T>::insertar(T dato){
    nodo<T> *q;
    if (raiz == NULL){
    raiz = new nodo<T>;
    raiz->info =dato;
    raiz->izq=raiz->der=NULL;
    return 0;
    }
    q =buscar_arbol(dato,raiz,NULL);
    if (q==NULL){
        return -1;
    }
    nodo<T> *nuevo;
    nuevo= new nodo<T>;
    nuevo->info = dato;
    nuevo->izq=nuevo->der=NULL;
    if (dato<q->info){
        q->izq=nuevo;
    }else   q->der=nuevo;
    return 0;
}
template <class T>
int arbinor<T>::eliminar(T dato){
    nodo<T> *q, *p=raiz;
    q=buscar(dato,&p,NULL);
    if (p==NULL) return -1;
    borrar_nodo(q,p);
    return 0;
}
template <class T>
void arbinor<T>::borrar_nodo(nodo<T> *p,nodo<T> *q){
    nodo<T>  *r, *s,*t;
    if (p->izq==NULL) r=p->der;
    else if (p->der==NULL) r=p->izq; 
           else {s =p;
      r=p->der;
      t=r->izq;
      while(t!=NULL){s=r; r=t; t=t->izq;}
    if (p!=s){
            s->izq=r->der;
        r->der=p->der; }
    r->izq =p->izq;
    }
        if (q==NULL) raiz= r;
        else if (p==q->izq) q->izq =r;
               else q->der = r;
        delete p;
}
template <class T>
void arbinor<T>::inorden(nodo<T> *p){
    if (p!=NULL){
        inorden(p->izq);
        cout<<p->info<<endl;
        inorden(p->der);}
}
template <class T>
void arbinor<T>::preorden(nodo<T> *p){
    if (p!=NULL){
        cout<<p->info<<endl;
        preorden(p->izq);
        preorden(p->der);
    }
}
template <class T>
void arbinor<T>::posorden(nodo<T> *p){
    if (p!=NULL){
        posorden(p->izq);
        posorden(p->der);
       cout<<p->info<<endl; 
    }
}
#endif