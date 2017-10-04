#ifndef listadoble
#define listadoble

using namespace std;

template <class T>
struct nodo{
	T dato;
	nodo<T> *sig;
	nodo<T> *ant;
};

template <class T>
class listad{
	nodo<T> *cabeza;
	int tam=1;

	public:
		listad(){
			cabeza = NULL;
		};
	void insertar_inicio(nodo<T> *info);
	void insertar_final(nodo<T> *info);
	void insertar_pos(nodo<T> *info,int pos);

	T consultar(int pos);
	T eliminar_inicio();
	T eliminar_final();
	T eliminar_pos(int pos);

	int tam_lista();
};

template <class T>
void listad <T>::insertar_inicio(nodo<T> *info){
	if(cabeza == NULL){
		cabeza = info;
		cabeza -> sig = NULL;
		cabeza -> ant = cabeza;
	} else {
		info -> sig = cabeza;
		info -> ant = cabeza -> ant;
		cabeza = info;
		tam++;
	}
}
template <class T>
void listad <T>::insertar_final(nodo<T> *info){
	nodo<T> *aux;
	if(cabeza==NULL){
		cabeza = info;
	} else {
		aux = cabeza -> ant;
		aux -> sig = info;
		info -> ant = aux;
		cabeza -> ant = info;
		tam++;
	}
}
template <class T>
void listad <T>::insertar_pos(nodo<T> *info,int pos){
	if(pos > tam){
		insertar_final(info);
	} else if(pos <= 1){
		insertar_inicio(info);
	} else {
		nodo<T> *aux,*aux2;
		aux = cabeza;
		for(int i = 1; i < pos; i++){
			aux = aux -> sig;
		}
		cout << "dato : " << aux -> dato;
		aux2 = aux -> ant;
		info -> ant = aux2;
		aux -> ant = info;
		info -> sig = aux;
		aux2 -> sig = info;
		tam++;
	}
}
template <class T>
T listad <T>::eliminar_inicio(){
	nodo<T> *aux;
	T aux0;
	aux = cabeza;
	cabeza = cabeza -> sig;
	cabeza -> ant = aux -> ant;
	aux0 = aux -> dato;
	delete aux;
	tam--;
	return aux0;
}
template <class T>
T listad <T>::eliminar_final(){
	nodo<T> *aux,*aux2;
	T aux0;
	aux = cabeza -> ant;
	aux2 = aux -> ant;
	cabeza -> ant = aux2;
	aux2 ->sig = cabeza;
	aux0 = aux -> dato;
	delete aux;
	tam--;
	return aux0;
}
template <class T>
T listad <T>::consultar(int pos){
	int i=1;
	nodo<T> *aux,*aux2;
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
int listad <T>::tam_lista(){
	return tam;
}
#endif