#ifndef listadoble
#define listadoble

using namespace std;

template <class T>
struct nodo{
	T dato;
	nodo<T> *sig, *ant;
};

template <class T>
class listad{
	nodo<T> *cabeza;
	int tam = 1;

	public:
		listad(){
			cabeza = NULL;
		};
		
	void insertar_inicio(T info);
	void insertar_final(T info);
	void insertar_pos(T info, int pos);

	T eliminar_inicio();
	T eliminar_final();
	T eliminar_pos(int pos);
	
	T consultar(int pos);

	int tam_lista();
	bool lista_vacia();
};

template <class T>
void listad <T>::insertar_inicio(T info){
	nodo<T> *nuevo = new nodo<T>;
	nuevo -> dato = info;
	
	if(cabeza == NULL){
		cabeza = nuevo;
		cabeza -> sig = cabeza;
		cabeza -> ant = cabeza;
	} else {
		nuevo -> sig = cabeza;
		nuevo -> ant = cabeza -> ant;
		cabeza = nuevo;
		tam++;
	}
}

template <class T>
void listad <T>::insertar_final(T info){
	nodo<T> *nuevo = new nodo<T>;
	nuevo -> dato = info;
	
	if(cabeza == NULL){
		cabeza = nuevo;
		cabeza -> sig = cabeza;
		cabeza -> ant = cabeza;
	} else {
		cabeza -> ant -> sig = nuevo;
		nuevo -> ant = cabeza -> ant;
		cabeza -> ant = nuevo;
		tam++;
	}
}

template <class T>
void listad <T>::insertar_pos(T info, int pos){
	nodo<T> *nuevo = new nodo<T>;
	nuevo -> dato = info;
	
	if(pos >= tam){
		insertar_final(info);
	} else if(pos <= 1){
		insertar_inicio(info);
	} else {
		nodo<T> *aux;
		aux = cabeza;
		for(int i = 1; i < pos; i++){
			aux = aux -> sig;
		}
		nuevo -> ant = aux -> ant;
		aux -> ant -> sig = nuevo;
		aux -> ant = nuevo;
		nuevo -> sig = aux;
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
	nodo<T> *aux;
	T aux0;
	aux = cabeza -> ant;
	aux0 = aux -> dato;
	cabeza -> ant = cabeza -> ant -> ant;
	cabeza -> ant -> sig = cabeza;
	delete aux;
	tam--;
	return aux0;
}

template <class T>
T listad <T>::eliminar_pos(int pos){
	nodo<T> *aux;
	aux = cabeza;
	T aux0;
	if (pos <= 1){
		eliminar_inicio();
	} else if (pos >= tam){
		eliminar_final();
	} else {
		for(int i = 1; i < pos; i++){
			aux = aux -> sig;
		}
		aux -> ant -> sig = aux -> sig;
		aux -> sig -> ant = aux -> ant;
		aux0 = aux -> dato;
		delete aux;
		tam--;
		return aux0;
	}
}

template <class T>
T listad <T>::consultar(int pos){
	int i = 1;
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
int listad <T>::tam_lista(){
	return tam;
}

template <class T>
bool listad <T>::lista_vacia(){
	if(tam == 0){
		return true;
	} else {
		return false;
	}
}

#endif
