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
		/*
		int insertar(int x, int i){
			if (cantItem < cantMax){                          //1
				i--;                                          //1
				if ((i >= 0) && (i <= cantItem)){             //3
					for (int j = cantItem-1; j >= i; j--){    //2+(j-i+1+1)+(j-i+1) = 2j-2i+5
						items[j+1] = items[j];                //4(j-i+1)            = 4j-4i+4
					}
					items[i] = x;                             //2
					cantItem++;                               //1
					return x;                                 //1
				}
				else{
					cout << "Posicion invalida" << endl;      //T(cantItem)=5+(2j-2i+5)+(4j-4i+4)+4
					return -1;                                //T(cantItem)=6j-6i+18
				}
			}                                                 //j=cantItem-1 -- 0<=i<=cantItem 
			else{
				cout << "Lista Llena" << endl;
				return -1;
			}
		}
		*/
		
		int insertar (int x, int i){
			if (cantItem < cantMax){                                   //1
            	if ((i > 0) && (i <= cantItem+1)){                     //4
                	for (int j = cantItem; j > i; j--){                //1+(j-i+1)+(j-i) = 2j-2i+2
                    	items [j] = items [j - 1];                     //4(j-posicion)  = 4j-4i
            		}
                	items [i-1] = x;                                   //3
                	cantItem++;                                        //1
                	return x;                                          //1
            	} 
				else{
                	cout << "Posicion invalida" << endl;               //T(cantItem)=5+(2j-2i+2)+(4j-4i)+5
                	return -1;                                         //T(cantItem)=6j-6i+12
            	}
        	} 
			else{                                                      //j = cantItem ----- 0 < i <= cantItem+1
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
					return i+1;
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
};

main(){
	Lista L;
	L = Lista(5);
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
