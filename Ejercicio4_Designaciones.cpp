#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
//es necesario C++ 11 por la función stoi()
//https://es.stackoverflow.com/questions/59744/c%C3%B3mo-compilar-en-c11-o-superior-en-devcpp 

class designacion{
	private:
		int anio;
		string cargo;
		string instancia_tipo;
		string materia;
		int varones;
		int mujeres;
		
	public:
		designacion(int xanio=0, string xcargo=" ", string xinstancia_tipo=" ", string xmateria=" ", int xvarones=0, int xmujeres=0){
			anio = xanio;
			cargo =xcargo;
			instancia_tipo = xinstancia_tipo;
			materia = xmateria;
			varones = xvarones;
			mujeres = xmujeres;
		}	
		
		string getCargo (){
			return cargo;
		}
		
		int getAnio (){
			return anio;
		}
		
		int getMujeres (){
			return mujeres;
		}
		
		string getMateria (){
			return materia;
		}
		
		int getVarones (){
			return varones;
		}
		
		int comparar (designacion otro){
			int resultado;
			resultado = ((anio != otro.anio) && (cargo != otro.cargo) && (instancia_tipo != otro.instancia_tipo) && (materia != otro.materia) && (varones != otro.varones) && (mujeres != otro.mujeres));
			return resultado;
		}
		
		string mostrar(){
			string cadena;
			cadena = "anio = " + to_string(anio) + ", cargo_tipo = " + cargo + ", instancia_tipo = " + instancia_tipo;
			return cadena;
		}
};

//No hay necesidad de utilizar una lista por contenido ya que los datos vienen ordenados.
//La implementacion de lista que utilizaré es secuencial, ya que la insercion de elementos siempre es al final de la lista.
//Para esta situación en la representación encadenada se tienen que recorrer todos los elementos mientras que en la secuencial la insercion es directa (sin desplazamiento).

class Lista{
	private:
		designacion* items;
		int cantMax;
		int cantItem;
		
	public:
		Lista(int xcantmax = 0){
			cantMax = xcantmax;
			cantItem = 0;
			items = new designacion[cantMax];
		}	
		
		int vacia(){
			return (cantItem == 0);
		}
		
		designacion insertar(designacion x, int i){
			if (cantItem < cantMax){                          
				i--;                                          
				if ((i >= 0) && (i <= cantItem)){             
					for (int j = cantItem-1; j >= i; j--){    
						items[j+1] = items[j];                
					}
					items[i] = x;                             
					cantItem++;                               
					return x;                                 
				}
				else{
					cout << "Posicion invalida" << endl;                                
				}
			}                                                 
			else{
				cout << "Lista Llena" << endl;
			}
		}
		/*
		designacion suprimir (int i){
			designacion x;
			if (!vacia()){
				i--;
				if ((i >=0) && (i < cantItem)){
					x = items[i];
					for(int j = i; j < cantItem-1; j++){
						items[j] = items[j+1];
					}
					cantItem--;
					return x;
				}
				else{
					cout << "Posicion invalida" << endl;
				}
			}
			else{
				cout << "Lista vacia" << endl;
			}
		}
		
		designacion recuperar (int i){
			if(!vacia()){
				i--;
				if ((i >=0) && (i < cantItem)){
					return items[i];
				}
				else{
					cout << "Posicion invalida" << endl;
				}
			}
			else{
				cout << "Lista vacia" << endl;
			}
		}
		
		int buscar (designacion x){
			int i;
			i = 0;
			if (!vacia()){
				while ((i < cantItem) && (items[i].comparar(x))){  //items[i] != x
					i++;
				}
				if (i < cantItem){
					return i+1;
				}
				else{
					cout << "Elemento no encontrado" << endl;
				}
			}
			else{
				cout << "Lista vacia" << endl;
			}
		}
		
		void mostrar (){
			if (!vacia()){
				cout << "------------" << endl;
				for(int j = 0; j < cantItem; j++){
					cout << j+1 << ". " << items[j].mostrar() << endl;
				}
				cout << "------------" << endl;
			}
			else{
				cout << "Lista vacia" << endl;
			}
		}
		*/
		void contar_Mujeres (string cargo_elegido){
			int cant, i, anio;
			i = 0;
			while (i < cantItem){
				anio = items[i].getAnio();
				cant = 0;
				while (items[i].getAnio() == anio){
					if (items[i].getCargo() == cargo_elegido){
						cant += items[i].getMujeres();
					}
					i++;
				}
				cout << "En el anio " << anio << " y para el cargo " << cargo_elegido << " la cantidad de mujeres designadas es: " << cant << endl;
			}
		}
		
		void contar_Agentes (string materia_elegida, string cargo_elegido, int anio_elegido){
			int cant, i, band;
			i = 0;
			band = 0;
			cant = 0;
			while ((i < cantItem) && (!band)){
				if (items[i].getAnio() == anio_elegido){
					while ((items[i].getAnio() == anio_elegido) && (!band)){  
						if (items[i].getCargo() == cargo_elegido){
							while ((items[i].getCargo() == cargo_elegido) && (!band)){
								if (items[i].getMateria() == materia_elegida){
									while (items[i].getMateria() == materia_elegida){
										cant += items[i].getMujeres();
										cant += items[i].getVarones();
										band = 1;
										i++;
									}
								}
								i++;
							}
						}
						i++;
					}
				}
				i++;
			}
			cout << "La cantidad de agentes designados en el anio " << anio_elegido << ", con el tipo de cargo " << cargo_elegido << ", en la materia " << materia_elegida << " es de: " << cant << endl;
		}
};

void cargarLista(Lista *lista, int cant){
	ifstream archivo;
	string linea, dato;
	string cargo, instancia_tipo, materia;
	int anio, varones, mujeres; 
	designacion UnaDesignacion;
	archivo.open("estadistica-designacion-magistrados-federal-nacional-por-genero-20190913.csv", ios::in);
	if (archivo.fail()){
		cout << "Error" << endl;
	}
	else{
		getline(archivo, linea);  //obtengo del archivo la primera linea, hasta el caracter '\n', para obviarla
		for (int i=1; i<=cant; i++){
			getline(archivo, linea);
			stringstream registro(linea);        //registro << linea
			for (int columna = 0; getline(registro,dato,','); columna++){
				switch (columna){
            	case 0: // AÑO
            		anio = stoi(dato);
            		break;
            	case 1: // CARGO
               	 	cargo = dato.substr(1,dato.length()-2);
            		break;
           		case 2: // TIPO
                	instancia_tipo = dato.substr(1,dato.length()-2);
            		break;
            	case 3: // MATERIA
            		if (dato != ""){                               //Hay veces en la que esta es la cadena "" estro provocará un error al realizar la funcion substr()
            			materia = dato.substr(1,dato.length()-2);	
					}
					else{
						materia = dato;
					}
            		break;
            	case 4: // VARONES
            		varones = stoi(dato);
            		break;
            	case 5: // MUJERES
                	mujeres = stoi(dato);
            		break;
    			}
			}
			UnaDesignacion = designacion(anio,cargo,instancia_tipo,materia,varones,mujeres);
			lista->insertar(UnaDesignacion,i);  //inserta en la lista la designacion creada con la linea actual
		}
		archivo.close();
	}
}

void MujeresDesignadas(Lista *lista);
void AgentesDesignados(Lista *lista);

int main(){
	ifstream archivo;
	int cant;
	Lista L;
	archivo.open("estadistica-designacion-magistrados-federal-nacional-por-genero-20190913.csv", ios::in);
	cant = 0;
	if (archivo.fail()){
		cout << "Error" << endl;
	}
	else{
		while(archivo.good()) if(archivo.get()=='\n') cant++;  //cantidad de designaciones
		archivo.close();
		L = Lista(cant-1);   //la primera linea del csv no es una designacion
		cargarLista(&L,cant-1);
		MujeresDesignadas(&L);
		AgentesDesignados(&L);
	}
}

void MujeresDesignadas(Lista *lista){
	string cargo_elegido;
	cout << "Ingrese un tipo de cargo para mostrar la cantidad de mujeres designadas en ese cargo por anio: ";
	getline(cin,cargo_elegido);
	if ((cargo_elegido == "Defensor") || (cargo_elegido == "Fiscal") || (cargo_elegido == "Juez")){
		lista->contar_Mujeres(cargo_elegido);
	} 
	else{
		cout << "El cargo elegido no  es valido." << endl;
	}
}

void AgentesDesignados(Lista *lista){
	string materia_elegida, cargo_elegido;
	int anio_elegido;
	cout << "A continuaacion ingrese la informacion necesaria para mostrar la cantidad de agentes designados." << endl;
	cout << "Materia: ";
	getline(cin,materia_elegida);
	cout << "Tipo de Cargo: ";
	getline(cin,cargo_elegido);
	cout << "Anio: ";
	cin >> anio_elegido;
	if ((materia_elegida == "Penal") || (materia_elegida == "Múltiple") || (materia_elegida == "Civil y/o comercial") || (materia_elegida == "Electoral") || (materia_elegida == "Laboral") || (materia_elegida == "Seguridad social") || (materia_elegida == "Penal económico") || (materia_elegida == "Contencioso administrativo")){
		if ((cargo_elegido == "Defensor") || (cargo_elegido == "Fiscal") || (cargo_elegido == "Juez")){
			if ((anio_elegido == 2000) || (anio_elegido == 2001) || (anio_elegido == 2002) || (anio_elegido == 2003) || (anio_elegido == 2004) || (anio_elegido == 2005) || (anio_elegido == 2006) || (anio_elegido == 2007) || (anio_elegido == 2008) || (anio_elegido == 2009) || (anio_elegido == 2010) || (anio_elegido == 2011) || (anio_elegido == 2012) || (anio_elegido == 2013) || (anio_elegido == 2014) || (anio_elegido == 2015) || (anio_elegido == 2016) || (anio_elegido == 2017) || (anio_elegido == 2018) || (anio_elegido == 2019)){
				lista->contar_Agentes(materia_elegida,cargo_elegido,anio_elegido);
			}
			else{
				cout << "Anio invalido." << endl;
			}
		}
		else{
			cout << "Cargo invalido." << endl;
		}
	}
	else{
		cout << "Materia invalida." << endl;
	}
}
