#ifndef estrucArbol
#define estrucArbol

template <class T>
struct nodo{
    T info;
    nodo<T> *izq;
    nodo<T> *der;
};
#endif