#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string.h>
#include <cstring>

using namespace std;


void Leer(){
	char delimitador;
	ifstream infile("forestales.csv");
	string line = "";
	vector <string> datos_csv;
	while (getline(infile,line)){
		stringstream strstr(line);
		string word="";
		while(getline(strstr,word, ',')){
			datos_csv.push_back(word);
		}
	}
	for(int i=0;i<datos_csv.size();i++){
		cout<<datos_csv.at(i)<<"\n";
	}
	int i=1;
	int ID;
	while(i<datos_csv.size()){
		getline(datos_csv.at(i),ID, ";");
		cout << "ID: " << ID << " " ;
		i++;
	}
}


//ALGORITMO PRINCIPAL
main ()
{
	Leer();

	
			
};
