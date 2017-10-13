#ifndef Multilista
#define Multilista

using namespace std;

struct Estudiante{
	string nombre, carrera, hobby;
	int edad = 0;
	int signombre = 0, sigcarrera = 0, sigedad = 0, sighobby = 0;
};

struct Cabecera{
	string atributo;
	int pos = 0;
};

class multi{
	Estudiante stu[11];	
 	Cabecera cab[10];
 	
	public:
		multi(){
			int i;
			cab[0].atributo = "Nombre";
 			cab[1].atributo = "Electronica";
 			cab[2].atributo = "Industrial";
 			cab[3].atributo = "Sistemas";
 			cab[4].atributo = "Catastral";
 			cab[5].atributo = "Edad";
 			cab[6].atributo = "Danza";
 			cab[7].atributo = "Natacion";
 			cab[8].atributo = "Basket";
 			cab[9].atributo = "Beisbol";
			
 			for(i=0;i<=10;i++){
 				cab[i].pos = 0;
 			}
		}
		int buscarPorEdad(Cabecera cab, int age);
		int buscarPorNombre(Cabecera cab, string name);
		int encontrarAnteriorCarrera(Cabecera cab, int i);
		int encontrarAnteriorHobby(Cabecera cab, int i);
		void insertarEstudiante(string name, string career, int age, string hobb, int i);
		void imprimir();
		void imprimirNombreAZ();
		void imprimirNombreZA();
		void imprimirEdad();
		void imprimirEdadDes();
		void imprimirCarrera(string car);
		void imprimirhobby(string hob);
		void imprimirEstuandCar();
		void imprimirEstuandHob();
		void imprimirCarandHob(string car);
};

int multi::buscarPorEdad(Cabecera cab, int age){
	Cabecera aux, aux1;
	aux = cab;
	aux1 = cab;	
	if(cab.pos == 0){
		return 0;				
	}else{
		if(stu[aux.pos].sigedad == 0){
			if(age > stu[aux.pos].edad){
				return 0;			
			}else{
				return 1; 			
			}
		}else{
			if(age > stu[aux.pos].edad){
				return 0;			
			}else{	
				while(stu[aux.pos].sigedad != 0){	
					aux.pos = stu[aux.pos].sigedad;
					if(age > stu[aux.pos].edad){
						return aux1.pos;		
					}
					if(stu[aux.pos].sigedad == 0){
						return aux.pos;		
					}
					aux1 = aux;
				}
			}
		}
	}	
}
int multi::buscarPorNombre(Cabecera cab, string name){
	Cabecera aux, aux1;
	aux = aux1 = cab;	
	if(cab.pos == 0){
		return 0;				
	}else{
		if(stu[aux.pos].signombre == 0){
			if(name < stu[aux.pos].nombre){
				return 0;			
			}else{
				return 1; 			
			}
		}else{
			if(name < stu[aux.pos].nombre){
					return 0;			
			}else{	
				while(stu[aux.pos].signombre != 0){	
					aux.pos = stu[aux.pos].signombre;
					if(name < stu[aux.pos].nombre){
						return aux1.pos;		
					}
					if(stu[aux.pos].signombre == 0){
						return aux.pos;			
					}
					aux1 = aux;
				}
			}
		}
	}	
}
int multi::encontrarAnteriorCarrera(Cabecera cab, int i){
	int aux = cab.pos;
	if (cab.pos == 0){		
		return 0;				
	}else{
		if(stu[cab.pos].sigcarrera == 0){		
			return 1;
		}else{	
			while(stu[aux].sigcarrera != 0){
				aux = stu[aux].sigcarrera;
				if(stu[aux].sigcarrera == 0){
					return aux;
				}				
			}		
		}
	}	
}
int multi::encontrarAnteriorHobby(Cabecera cab, int i){
	int aux = cab.pos;
	if (cab.pos == 0){		
		return 0;				
	}else{
		if(stu[cab.pos].sighobby == 0){		
			return 1;
		}else{	
			while(stu[aux].sighobby != 0){
				aux = stu[aux].sighobby;
				if(stu[aux].sighobby == 0){
					return aux;
				}				
			}		
		}
	}
}
void multi::insertarEstudiante(string name, string career, int age, string hobb, int i){
	Estudiante nuevo;
	int anteriorNombre, anteriorEdad;	
	nuevo.nombre = name;
	nuevo.carrera = career;
	nuevo.edad = age;
	nuevo.hobby = hobb;
	
	anteriorNombre = buscarPorNombre(cab[0], name);	
	if(anteriorNombre == 0){
		if(stu[1].nombre == ""){		
			cab[0].pos = 1;			
		}else{					
			nuevo.signombre = cab[0].pos;			
			cab[0].pos = i;
		}		
	}else{				
		nuevo.signombre = stu[anteriorNombre].signombre;			
		stu[anteriorNombre].signombre = i;		
	}
	
	anteriorEdad = buscarPorEdad(cab[5], age);
	if(anteriorEdad == 0){
		if(stu[1].edad == 0){					
			cab[5].pos = 1;			
		}else{							
			nuevo.sigedad = cab[5].pos;			
			cab[5].pos = i;
		}		
	}else{					
		nuevo.sigedad = stu[anteriorEdad].sigedad;			
		stu[anteriorEdad].sigedad = i;		
	}	
	
	int posCarrera = -1;
	if(career == "Electronica"){		
		posCarrera = encontrarAnteriorCarrera(cab[1], i);
		if(posCarrera == 0){			
			cab[1].pos = i;			
		}else if(posCarrera == 1){
			stu[cab[1].pos].sigcarrera = i;
		}else{			
			stu[posCarrera].sigcarrera = i;
		}
	}else if(career == "Industrial"){
		posCarrera = encontrarAnteriorCarrera(cab[2], i);
		if(posCarrera == 0){
			cab[2].pos = i;			
		}else if(posCarrera == 1){
			stu[cab[2].pos].sigcarrera = i;
		}else{
			stu[posCarrera].sigcarrera = i;
		}	
	}else if(career == "Sistemas"){
		posCarrera = encontrarAnteriorCarrera(cab[3], i);
		if(posCarrera == 0){
			cab[3].pos = i;			
		}else if(posCarrera == 1){
			stu[cab[3].pos].sigcarrera = i;
		}else{		
			stu[posCarrera].sigcarrera = i;
		}
	}else if(career == "Catastral"){
		posCarrera = encontrarAnteriorCarrera(cab[4], i);
		if(posCarrera == 0){
			cab[4].pos = i;			
		}else if(posCarrera == 1){
			stu[cab[4].pos].sigcarrera = i;
		}else{		
			stu[posCarrera].sigcarrera = i;
		}
	}
	
	int posHobbi = -1;
	if(hobb == "Danza"){		
		posHobbi = encontrarAnteriorHobby(cab[6], i);
		if(posHobbi == 0){			
			cab[6].pos = i;			
		}else if(posHobbi == 1){
			stu[cab[6].pos].sighobby = i;
		}else{			
			stu[posHobbi].sighobby = i;
		}
	}else if(hobb == "Natacion"){
		posHobbi = encontrarAnteriorHobby(cab[7], i);
		if(posHobbi == 0){
			cab[7].pos = i;			
		}else if(posHobbi == 1){
			stu[cab[7].pos].sighobby = i;
		}else{
			stu[posHobbi].sighobby = i;
		}	
	}else if(hobb == "Basket"){
		posHobbi = encontrarAnteriorHobby(cab[8], i);
		if(posHobbi == 0){
			cab[8].pos = i;			
		}else if(posHobbi == 1){
			stu[cab[8].pos].sighobby = i;
		}else{		
			stu[posHobbi].sighobby = i;
		}
	}else if(hobb == "Beisbol"){
		posHobbi = encontrarAnteriorHobby(cab[9], i);
		if(posHobbi == 0){
			cab[9].pos = i;			
		}else if(posHobbi == 1){
			stu[cab[9].pos].sighobby = i;
		}else{		
			stu[posHobbi].sighobby = i;
		}
	}
	stu[i] = nuevo;	
}
void multi::imprimirNombreAZ(){
	int a = cab[0].pos;
	for(int i=1;i<11;i++){
		cout<<stu[a].nombre<<endl;
		a = stu[a].signombre;
	}
	cout<<endl;	
}
void multi::imprimirNombreZA(){
	string nom[11];
	int temp=10;
	int a = cab[0].pos;
	for(int i=1;i<11;i++){
		//cout<<stu[a].nombre<<endl;
		nom[temp]=stu[a].nombre;
		a = stu[a].signombre;
		temp--;
	}
	for(int i=1;i<11;i++){
		cout<<nom[i]<<endl;
	}
	cout<<endl;	
}
void multi::imprimirEdad(){
	int b = cab[5].pos;
	for(int i=1;i<11;i++){
		cout<<stu[b].edad<<endl;
		b = stu[b].sigedad;
	}	
	cout<<endl;
}
void multi::imprimirEdadDes(){
	int ed[11];
	int temp=10;
	int b = cab[5].pos;
	for(int i=1;i<11;i++){
		ed[temp]= stu[b].edad;
		b = stu[b].sigedad;
		temp--;
	}
	for(int i=1;i<11;i++){
		cout<<ed[i]<<endl;
	}	
	cout<<endl;
}
void multi::imprimir(){
	for(int j=1; j<11; j++){
		cout<<j<<" "<<stu[j].nombre<<" "<<stu[j].carrera<<" "<<stu[j].edad<<" "<<stu[j].hobby<<endl;
	}
	
	cout<<endl<<endl<<"Lista de cabeceras:"<<endl<<endl;

	for (int k=0; k<=8; k++){
		cout<<cab[k].atributo<<" "<<cab[k].pos<<endl;
	}
	cout<<endl;
}
void multi::imprimirCarrera(string car){
	int b=0;
	if(car=="Electronica"){
		b = cab[1].pos;
	}else if(car=="Industrial"){
		b = cab[2].pos;
	}else if(car=="Sistemas"){
		b = cab[3].pos;
	}else if(car=="Catastral"){
		b = cab[4].pos;
	}
	for(int i=1;i<11;i++){
		cout<<stu[b].nombre<<endl;
		b = stu[b].sigcarrera;
	}	
	cout<<endl;
}
void multi::imprimirhobby(string car){
	int b;
	if(car=="Danza"){
		b=cab[6].pos;
	}else if(car=="Natacion"){
		b=cab[7].pos;
	}else if(car=="Basket"){
		b=cab[8].pos;
	}else if(car=="Beisbol"){
		b=cab[9].pos;
	}
	for(int i=1;i<11;i++){
		cout<<stu[b].nombre<<endl;
		b = stu[b].sighobby;
	}	
	cout<<endl;
}
void multi::imprimirEstuandCar(){
	int a = cab[0].pos;
	cout<<"Nombre    "<<"Carrera    "<<endl;
	for(int i=1;i<11;i++){
		cout<<stu[a].nombre<<"    "<<stu[a].carrera<<endl;
		a = stu[a].signombre;
	}
	cout<<endl;
}
void multi::imprimirEstuandHob(){
	int a = cab[0].pos;
	cout<<"Nombre    "<<"Hobby    "<<endl;
	for(int i=1;i<11;i++){
		cout<<stu[a].nombre<<"    "<<stu[a].hobby<<endl;
		a = stu[a].signombre;
	}
	cout<<endl;
}
void multi::imprimirCarandHob(string car){
	int b=0;
	int nat=0,dan=0,bas=0,bei=0;
	if(car=="Electronica"){
		b = cab[1].pos;
	}else if(car=="Industrial"){
		b = cab[2].pos;
	}else if(car=="Sistemas"){
		b = cab[3].pos;
	}else if(car=="Catastral"){
		b = cab[4].pos;
	}
	for(int i=1;i<11;i++){
		if(stu[b].hobby=="Natacion"&&nat==0){
			cout<<stu[b].hobby<<endl;
			b = stu[b].signombre;
			nat=1;
		}else if(stu[b].hobby=="Danza"&&dan==0){
			cout<<stu[b].hobby<<endl;
			b = stu[b].signombre;
			dan=1;
		}else if(stu[b].hobby=="Basket"&&bas==0){
			cout<<stu[b].hobby<<endl;
			b = stu[b].signombre;
			bas=1;
		}else if(stu[b].hobby=="Beisbol"&&bei==0){
			cout<<stu[b].hobby<<endl;
			b = stu[b].signombre;
			bei=1;
		}else{
			b = stu[b].signombre;
		}
	}
	cout<<endl;
}
#endif




