#include <string>
#include <list> 
#ifndef  multilista
#define  multilista

struct estudiante{
	std::string nombre,hobby,carrera;
	int edad;
	int signombre,sigcarrera,sighobby,sigedad;
};
class multi{
	estudiante *nuevo;
	int cabezas [4]={0,0,0,0};
	std::list<estudiante> datos;
	public:
		multi(){
		}
		void insertar_estu(std::string nombre,std::string carrera,std::string hobby,int edad);
	private:
		int organizar(std::string dato,int d);
		int organizar_int(int dato);
		void recorrer();
};
//DEFINICION METODOS
void multi::insertar_estu(std::string nombre,std::string carrera,std::string hobby,int edad){
	nuevo -> nombre=nombre;
	nuevo -> carrera=carrera;
	nuevo -> hobby=hobby;
	nuevo -> edad=edad;
	std::list<estudiante>::iterator aux;
	estudiante es[datos.size()];
	int i=0;
	aux=datos.begin();
	while(aux != datos.end()){
		es[i] = *aux;
		i++;
		aux++;
	}
	datos.push_back(*nuevo);
	if(datos.empty()){
		nuevo -> signombre=0;
		nuevo -> sigcarrera=0;
		nuevo -> sighobby=0;
		nuevo -> sigedad=0;
	}else{
		es[i].sigcarrera = datos.size();
		nuevo -> signombre=organizar(nuevo -> nombre,0);
		nuevo -> sigcarrera=NULL;
		nuevo -> sighobby=organizar(nuevo -> hobby,1);
		nuevo -> sigedad=organizar_int(nuevo -> edad);
	}
}
void multi::recorrer(){
	std::list<estudiante>::iterator aux;
	estudiante es[datos.size()];
	int i=0;
	aux=datos.begin();
	while(aux != datos.end()){
		es[i] = *aux;
		i++;
		aux++;
	}
	for(int i=0;i<datos.size()-1;i++){
		if(es[i].signombre==nuevo -> signombre&& nuevo -> signombre!=datos.size()&&nuevo -> signombre!=0){
			es[i-1].signombre=datos.size();
		}
	}
}
int multi::organizar(std::string dato,int d){
	int i=0;
	std::string es[datos.size()];
	std::list<estudiante>::iterator aux;
	if(d==0){
		aux=datos.begin();
		while(aux != datos.end()){
			es[i] = aux -> nombre;
			i++;
			aux++;
		}
	}else if(d==1){
		aux=datos.begin();
		while(aux != datos.end()){
			es[i] = aux -> hobby;
			i++;
			aux++;
		}
	}
	int pos=0;
	while(dato>es[pos]){
		pos++;
	}
	return pos;
}
int multi::organizar_int(int dato){
	std::list<estudiante>::iterator aux;
	aux=datos.begin();
	int es[datos.size()];
	int i=0;
	while(aux != datos.end()){
		es[i] = aux -> edad;
		i++;
		aux++;
	}
	int pos=0;
	while(dato>es[pos]){
		pos++;
	}
	return pos;
} 
#endif