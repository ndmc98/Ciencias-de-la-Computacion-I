#ifndef listaenteros
#define listaenteros

using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};

class listae{
    nodo *cabeza;
    int tam = 0;

    public:
        listae(){
            cabeza = NULL;
        }
        void insertar_dato(int info);
        void ordenar();
        int consultar(int pos);
        int tam_lista();
        
        bool lista_vacia();
};

void listae::ordenar(){
    nodo *aux = new nodo;
    nodo *aux2 = NULL;
    aux = cabeza;
    int dat;
	while(aux -> sig != NULL){
		aux2 = aux -> sig;
		while(aux2 != NULL){
			if(aux -> dato > aux2 -> dato){
				dat = aux2 -> dato;
				aux2 -> dato = aux -> dato;
				aux -> dato = dat;
			}
			aux2 = aux2 -> sig;
		}
		aux = aux -> sig;
	}
}

void listae::insertar_dato(int info){
    nodo *nuevo = new nodo;
    nuevo -> dato = info;
    nuevo -> sig = NULL;
    
    if(tam == 0){
        cabeza = nuevo;
        cabeza -> sig = NULL;
        tam++;
    }else{
        nodo *aux;
        aux = cabeza;
        while(aux -> sig){
            aux = aux -> sig;
        }
        aux -> sig = nuevo;
        tam++;
    }
	ordenar();
}

int listae::consultar(int pos){
	int i = 1;
	nodo *aux;
	aux = cabeza;
	while (aux != NULL && i < pos){
		aux = aux -> sig;
		i++;
	}
	if (i == pos){ 
		return aux -> dato;
	}
}

int listae::tam_lista(){
	return tam;
}

bool listae::lista_vacia(){
	if(tam == 0){
		return true;
	} else {
		return false;
	}
}

#endif
