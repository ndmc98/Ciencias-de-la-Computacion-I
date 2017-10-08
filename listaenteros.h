#ifndef listaenteros
#define listaenteros

#define NULL __null

template <class T>
struct nodo{
    T dato;
    nodo<T> *sig;
};
template <class T>
class listae{
    nodo<T> *cabeza;
    int tam=0;
    int a[];
    public:
        listae(){
            cabeza=NULL;
        }
        void insertar_dato(int info);
        T consultar2(int pos);
        T tam_lista();
        T consultar3(int pos);
        void organizar();
        void arreglo();
};

template <class T>
void listae <T>::insertar_dato(int info){
    nodo<T> *nuevo = new nodo<T>;
    nuevo -> dato = info;
    if(tam==0){
        cabeza = nuevo;
        cabeza -> sig = NULL;
        tam++;
    }else{
        nodo <T> *aux;
        aux = cabeza;
        while(aux -> sig){
            aux = aux -> sig;
        }
        aux -> sig = nuevo;
        tam++;
    }
    arreglo();
}
template <class T>
void listae <T>::arreglo(){
    a[tam];
    nodo<T> *nuevo = new nodo<T>;
    nuevo = cabeza;
    int i=0;
    while(i<tam){
        a[i] = nuevo -> dato;
        nuevo = nuevo -> sig;
        i++;
    }
    organizar();
}
template <class T>
void listae <T>::organizar(){
    int ints, i, aux;
    bool band;
    ints = tam;
    while (ints > 1 ) {
      ints = (ints/2);
      band = true;
      while (band==true) {
        band=false;
        i=0;
        while ((i+ints)<=tam) {
          if (a[i]>a[i+ints]) {
            aux=a[i];
            a[i]=a[i+ints];
            a[i+ints]=aux;
            band=true;
          }
          i++;
        }
      }
    }
}

template <class T>
T listae <T>::consultar2(int pos){
	int i = 0;
	nodo<T> *aux;
	aux = cabeza;
	while (aux != NULL && i < pos){
		aux = aux -> sig;
		i++;
	}
	if (i == pos){ 
		return aux -> dato;
	}
}
template <class T>
T listae <T>::tam_lista(){
	return tam;
}
template <class T>
T listae <T>::consultar3(int pos){
    return a[pos];
}

#endif