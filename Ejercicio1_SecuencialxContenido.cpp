#include <iostream>
using namespace std;

class Lista{
	private:
		int* items;
		int cantMax;
		int cantItem;
		
	public:
		Lista(int xcantmax = 0){
			cantMax = xcantmax;
			cantItem = 0;
			items = new int[cantMax];
		}	
		
		int vacia(){
			return (cantItem == 0);
		}
		
		int insertar(int x){
			int i;
			if (cantItem < cantMax){
				if (vacia()){
					items[0] = x;
				}
				else{
					i = 0;
					while ((i < cantItem) && (items[i] < x)){
						i++;
					}
					for (int j = cantItem-1; j >= i; j--){
						items[j+1] = items[j];
					}
					items[i] = x;
				}
				cantItem++;
				return x;
			}
			else{
				cout << "Lista Llena" << endl;
				return -1;
			}
		}
		
		int suprimir (int i){
			int x;
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
					return -1;
				}
			}
			else{
				cout << "Lista vacia" << endl;
				return -1;
			}
		}
		
		int recuperar (int i){
			if(!vacia()){
				i--;
				if ((i >=0) && (i < cantItem)){
					return items[i];
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
			int i;
			i = 0;
			if (!vacia()){
				while ((i < cantItem) && (items[i] != x)){
					i++;
				}
				if (i < cantItem){
					return i;
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
			if (!vacia()){
				cout << "------------" << endl;
				for(int j = 0; j < cantItem; j++){
					cout << items[j] << endl;
				}
				cout << "------------" << endl;
			}
			else{
				cout << "Lista vacia" << endl;
			}
		}
		
		int supresion_binaria (int x){
			int inf, sup, medio;
			inf=0;
			sup = cantItem-1;
			medio=(inf+sup)/2;
			while((inf<=sup)&&(items[medio] != x)){
	  			if(x < items[medio]){
	  	  			sup = medio-1;
		 		}
				else{
		  			inf = medio+1;
		  		}
				medio=(inf+sup)/2;    
	  		}
			if(inf<=sup){
	  			for(int j = medio; j < cantItem-1; j++){
					items[j] = items[j+1];
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
	L = Lista(5);
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
