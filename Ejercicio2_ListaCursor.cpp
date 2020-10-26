#include <iostream>
using namespace std;

class Nodo{
	private:
		int item;
		int sig;
		
	public:       
		Nodo (){
			sig = -2;
		}
	    
        int GetItem(){
        	return item;
		}        

        void SetItem(int xitem){
        	item = xitem;
		}           

        int GetSiguiente (){
        	return sig;
		}

        void SetSiguiente(int xsig){
            sig = xsig;
        }     	
};

class Lista{
	private:
		Nodo* items;
		int cantMax;
		int cantItem;
		int disponible;
		int cabeza;
		
		void buscarDisp(){
			int i;
			i=0;
			while ((i < cantMax) && (items[i].GetSiguiente() != -2)){
				i++;
			}
			disponible = i;
		}
		
	public:
		Lista(int xcantmax = 0){
			Nodo registro;
			cantMax = xcantmax;
			disponible = 0;
			cabeza = 0;
			cantItem = 0;
			items = new Nodo[cantMax];
			/*
			for (int i = 0; i < cantMax; i++){
                registro = Nodo();
				items[i] = registro; 
            }
            */
		}	
		
		int vacia(){
			return (cantItem == 0);
		}
		
		int insertar (int x, int i){
			int ant, p, j;
			if (cantItem < cantMax){                                   
            	if ((i > 0) && (i <= cantItem+1)){    
            		buscarDisp();
					items[disponible].SetItem(x); 
                	ant = cabeza;
					p = cabeza;   
					j = 1;
					while (j < i){
						j++;
						ant = p;
						p = items[p].GetSiguiente();
					}
					if (p == cabeza){
						if (vacia()){
							items[cabeza].SetSiguiente(-1);
						}
						else{
							items[disponible].SetSiguiente(cabeza);
						}
						cabeza = disponible;
					}
					else if (p == -1){
						items[disponible].SetSiguiente(-1);
						items[ant].SetSiguiente(disponible);
					}
					else{
						items[disponible].SetSiguiente(p);
						items[ant].SetSiguiente(disponible);
					} 
					cantItem++;
					return x;                                      
            	} 
				else{
                	cout << "Posicion invalida" << endl;               
                	return -1;                                         
            	}
        	} 
			else{                                                      
            	cout << "Lista Llena" << endl;
            	return -1;
            }
		}
		
		int suprimir (int i){
			int eliminado, p, ant, j;
			if (!vacia()){
				if ((i > 0) && (i <= cantItem)){
					if (i == 1){
						p = cabeza;
						if (cantItem == 1){
							cabeza = 0;
						}
						else{
							cabeza = items[cabeza].GetSiguiente();
						}
						eliminado = items[p].GetItem();
						items[p].SetSiguiente(-2);
					}
					else{
						p = cabeza;
						ant = cabeza;
						j = 1;
						while (j < i){
							ant = p;
							p = items[p].GetSiguiente();
							j++;
						}
						eliminado = items[p].GetItem();
						items[ant].SetSiguiente(items[p].GetSiguiente());
						items[p].SetSiguiente(-2);
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
            	cout << "Lista Llena" << endl;
            	return -1;
            }
		}
		
		int recuperar (int i){
			int j, resultado, cab;
			if (!vacia()){
				if ((i > 0) && (i <= cantItem)){
					j = 1;
					cab = cabeza;
					while (j < i){
						j++;
						cab = items[cab].GetSiguiente();
					}
					return items[cab].GetItem();
				}
				else{
                	cout << "Posicion invalida" << endl;               
                	return -1;                                         
        		}
			}
			else{
				cout << "Lista Llena" << endl;
            	return -1;
			}
		}
		
		int buscar (int x){
			int buscado, j;
			if (!vacia()){
				buscado = cabeza;
				j = 1;
				while ((buscado != -1) && (items[buscado].GetItem() != x)){
					buscado = items[buscado].GetSiguiente();
					j++; 
				}
				if (buscado != -1){
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
			int indice;
			if (!vacia()){  
				cout << "------------" << endl;
				indice = cabeza;    
				while (indice != -1){
					cout << "Item: " << items[indice].GetItem() << endl;
					cout << "Sig: " << items[indice].GetSiguiente() << endl;
					cout << "-- " << endl;
					indice = items[indice].GetSiguiente();
				}
				cout << "------------" << endl;
			}
			else{
				cout << "Lista vacia" << endl;
			}
		}
};

int main(){
	Lista L;
	L=Lista(5);
	cout << L.vacia() << endl;
	cout << "------------" << endl;
	L.insertar(1,2);
	cout << "------------" << endl;
	L.insertar(1,1);
	L.insertar(2,2);
	L.insertar(3,3);
	L.insertar(4,4);
	L.insertar(5,5);
	L.insertar(6,6);
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
