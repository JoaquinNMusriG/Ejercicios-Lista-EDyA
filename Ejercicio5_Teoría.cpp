//Pseudocódigo
/* 
	L=(10,5,7,5,2,10)
	Primer_elemento(L,Item)
	Buscar(Item,L,i)
	Mientras (No error)
		j = i+1
		Recuperar(L,j,Otro)
		Mientras (No error)
			Si (Item == Otro)
				Suprimir(L,j,Otro)
			finSi
			j = j+1
			Recuperar(L,j,Otro)
		finMientras
		i = i+1
		Recuperar(L,i,Item)
	finMientras
*/	

//Elementos aleatoreos sin orden

void eliminarRepetidos (Lista L){
	int Item, Otro, i, j;
	Item = L.primer_elemento();                	 //Primer_elemento(L,Item)
	i = L.buscar(Item);                        	 //Buscar(Item,L,i)
	while (Item != -1){                          //Mientras (No error)
		j = i+1;
		Otro = L.recuperar(j);                   //Recuperar(L,j,Otro)
		while (Otro != -1){                      //Mientras (No error)
			if (Item == Otro){
				L.suprimir(j);
			}
			j++:
			Otro = L.recuperar(j);               //Recuperar(L,j,Otro)
		}
		i++;
		Item = L.recuperar(i);                   //Recuperar(L,i,Item)
	}
}

//Lista ordenada por contenido

void eliminarRepetidos (Lista L){
	int Item, Otro, i, j;
	Item = L.primer_elemento();                	 
	i = L.buscar(Item);                        	 
	while (Item != -1){                          
		j = i+1;
		Otro = L.recuperar(j);                   
		while (Otro == Item){  
			L.suprimir(j);
			j++:
			Otro = L.recuperar(j);               
		}
		i++;
		Item = L.recuperar(i);                   
	}
}

