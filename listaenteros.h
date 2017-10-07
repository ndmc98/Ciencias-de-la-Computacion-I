#ifndef listaenteros
#define listaenteros

template <class T>
struct nodo{
    int dato;
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
        int consultar2(int pos);
        int tam_lista();

    private:
        void organizar(int a[]);
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
        nodo <T> *aux,*aux2;
        aux = cabeza;
        while(aux -> sig){
            aux = aux -> sig;
        }
        aux -> sig = nuevo;
        tam++;
        a[tam];
        aux = cabeza;
        int i=0;
        while(aux -> sig){
            a[i]=aux->dato;
            aux = aux -> sig;
            i++;
        }
        //organizar(a);
        
    }
}
template <class T>
void listae <T>::organizar(int a[]){
    int i,j,temp;
    for(i=1;i<tam;i++){
      temp = a[i];
      j=i-1;
      while ((a[j] > temp) && (j>=0)) {
        a[j+1] = a[j];
        j--;
      }
      a[j+1] = temp;
    }
}

template <class T>
int listae <T>::consultar2(int pos){
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
int listae <T>::tam_lista(){
	return tam;
}

#endif