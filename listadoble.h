#ifndef listadoble
#define listadoble;

using namespace std;

template <class T>
struct nodo{
	T dato;
	nodo<T> *sig;
	nodo<T> *ant;
};

template <class T>
class listadoble {
	nodo<T> *cabeza;
	int tam=1;
	public:
		listadoble(){
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
void listadoble<T>::insertar_inicio(nodo<T> *info){
	if(cabeza == NULL){
		cabeza = info;
		cabeza -> sig = NULL;
		cabeza -> ant = NULL;
	} else {
		info -> sig = cabeza;
		info -> ant = cabeza -> ant;
		cabeza = info;
	}
}