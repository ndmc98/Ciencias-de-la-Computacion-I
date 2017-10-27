#ifndef estructura
#define estructura

template <class T>
struct nodoAP{
    T info;
    nodoAP<T> *izq;
    nodoAP<T> *der;
    int pri;
};
#endif