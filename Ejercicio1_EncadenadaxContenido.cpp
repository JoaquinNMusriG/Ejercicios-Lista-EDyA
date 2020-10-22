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
		
		int insertar(int x){
			Nodo *nuevo, *anterior, *posterior;
			nuevo = new Nodo;
			nuevo->SetItem(x);
			if (primero == NULL){
				primero = nuevo;
				nuevo->SetSig(NULL);
			}
			else{
				if (primero->GetItem() >= nuevo->GetItem()){
					nuevo->SetSig(primero);
					primero = nuevo;
				}
				else{
					posterior = primero;
					anterior = primero;
					while ((posterior != NULL) && (nuevo->GetItem() > posterior->GetItem())){
						anterior = posterior;
						posterior = posterior->GetSig();
					}
					anterior->SetSig(nuevo);
					nuevo->SetSig(posterior);
				}
			} 
			cantItem++;
			return nuevo->GetItem();
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
		
		int supresion_binaria (int x){
			int inf, sup, medio, item, j;
			Nodo *anterior, *posterior;
			inf = 1;
			sup = cantItem;
			medio=(inf+sup)/2;
			item = recuperar(medio);
			while((inf<=sup)&&(item != x)){
	  			if(x < item){
	  	  			sup = medio-1;
		 		}
				else{
		  			inf = medio+1;
		  		}
				medio=(inf+sup)/2;
				item = recuperar(medio);    
	  		}
			if(inf<=sup){
	  			if (medio == 1){
					posterior = primero;
					primero = primero->GetSig();
					free (posterior);
				}
				else{
					posterior = primero;
					anterior = primero;
					j = 1;
					while (j < medio){
						anterior = posterior;
						posterior = posterior->GetSig();
						j++;
					}
					anterior->SetSig(posterior->GetSig());
					free (posterior);
				}
				cantItem--;
				return x;
      		}
			else{
	  			cout << "Elemento no encontrado" << endl;
				return -1;
	  		} 	
		}
};

main(){
	Lista L;
	L = Lista();
	cout << L.vacia() << endl;
	L.insertar(1);
	L.insertar(3);
	L.insertar(4);
	L.insertar(2);
	L.insertar(0);
	L.mostrar();
	L.supresion_binaria(4);
	L.insertar(-2);
	L.mostrar();
}
