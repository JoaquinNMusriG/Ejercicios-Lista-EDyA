#include <iostream>
#include <stdlib.h>
using namespace std;

class Nodo{
	private:
		int item;
		Nodo* sig;
		
	public:           
        int GetItem(){
        	return item;
		}        

        void SetItem(int xitem){
        	item = xitem;
		}           

        Nodo* GetSig (){
        	return sig;
		}

        void SetSig(Nodo* xsig){
            sig = xsig;
        }     	
};

class Lista{
	private:
		Nodo *primero;
		int cantItem;
		
	public:
		Lista (Nodo *xp = NULL){
			primero = xp;
			cantItem = 0;
		}
		
		int vacia (){
			return (primero == NULL);
		}	
		
		int insertar(int x, int i){
			Nodo *nuevo, *anterior, *posterior;
			int j;
			i--;                                                             // no iría
			if ((i >= 0) && (i <= cantItem)){                                //(i >= 1) && (i <= cantItem+1)
				nuevo = new Nodo;
				nuevo->SetItem(x);
				if (i == 0){                                                 //(i == 1)
					nuevo->SetSig(primero);  //Insertar al inicio
					primero = nuevo;
				}
				else{
					posterior = primero;
					anterior = primero;
					j = 0;                                                   //j = 1;
					while (j < i){           //Insertar en medio o final
						anterior = posterior;
						posterior = posterior->GetSig();
						j++;
					}
					anterior->SetSig(nuevo);
					nuevo->SetSig(posterior);
				}
				cantItem++;
				return nuevo->GetItem();
			}
			else{
				cout << "Posicion invalida" << endl;
				return -1;
			}
		}
		
		int suprimir (int i){
			Nodo *anterior, *posterior;
			int j, eliminado;
			if (!vacia()){
				i--;
				if ((i >=0) && (i < cantItem)){
					if (i == 0){
						posterior = primero;
						primero = primero->GetSig();
						eliminado = posterior->GetItem();
						free (posterior);
					}
					else{
						posterior = primero;
						anterior = primero;
						j = 0;
						while (j < i){
							anterior = posterior;
							posterior = posterior->GetSig();
							j++;
						}
						eliminado = posterior->GetItem();
						anterior->SetSig(posterior->GetSig());
						free (posterior);
					}
					cantItem--;
					return eliminado;
				}
				else{
					cout << "Posicion invalida" << endl;
					return -1;
				}
			}
			else{
				cout << "Lista vacia" << endl;
				return -1;
			}
		}
		
		int recuperar (int i){
			Nodo *recuperado;
			int j, resultado;
			if(!vacia()){
				i--;
				if ((i >=0) && (i < cantItem)){
					if (i == 0){
						resultado = primero->GetItem();
					}
					else{
						recuperado = primero;
						j = 0;
						while (j < i){
							recuperado = recuperado->GetSig();
							j++;
						}
						resultado = recuperado->GetItem();
					}
					return resultado;
				}
				else{
					cout << "Posicion invalida" << endl;
					return -1;
				}
			}
			else{
				cout << "Lista vacia" << endl;
				return -1;
			}
		}
		
		int buscar (int x){
			Nodo *buscado;
			int j;
			if(!vacia()){
				buscado = primero;
				j = 1;
				while ((buscado != NULL) && (buscado->GetItem() != x)){
					buscado = buscado->GetSig();
					j++; 
				}
				if (buscado != NULL){
					return j;
				}
				else{
					cout << "Elemento no encontrado" << endl;
					return -1;
				}
			}
			else{
				cout << "Lista vacia" << endl;
				return -1;
			}
		}
		
		void mostrar (){
			Nodo *recorre;
			recorre = primero;
			if (!vacia()){
				cout << "------------" << endl;
				while (recorre != NULL){
					cout << recorre->GetItem() << endl;
					recorre = recorre->GetSig();
				}
				cout << "------------" << endl;
			}
			else{
				cout << "Lista vacia" << endl;
			}
		}
};

main(){
	Lista L;
	L = Lista();
	cout << L.vacia() << endl;
	cout << "------------" << endl;
	L.insertar(1,2);
	cout << "------------" << endl;
	L.insertar(1,1);
	L.insertar(2,2);
	L.insertar(3,3);
	L.insertar(4,4);
	L.insertar(5,5);
	cout << "------------" << endl;
	cout << "El 3 esta en la pos: " << L.buscar(3) << endl;
	cout << "En la pos 3 esta el: " << L.recuperar(3) << endl;
	L.mostrar();
	cout << "3 errores:" << endl;;
	L.buscar(6);
	L.recuperar(-1);
	L.suprimir(6);
	L.suprimir(1);
	L.suprimir(4);
	L.mostrar();
	L.insertar(8,1);
	L.mostrar();
}
