#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;
int main(int argc, char** argv) {
	
	char arreglo[50][100];
	bool salir = false;
	int i=0, linea;
	cout<<"Escriba texto Pulse (0 + enter) para salir:"<<endl;
	while(salir == false){
		if(arreglo[i-1][0] == '0'){
			linea= i-2;
			for(int x=i-1; x<50; x++){
				for(int z=0; z<100; z++){
					arreglo[x][z] = '\0';
				}
			}
			salir = true;
		}
		else{
			char cadena[100];
			cin.getline(cadena,100);
			int longi = strlen(cadena);
			
			if(cadena[0] != '0'){
				for(int j=0; j<longi; j++){
					arreglo[i][j] = cadena[j]; 
				}
				for(int k=longi; k<100; k++){
					arreglo[i][k] = '\0';
				}
			}
			else{
				arreglo[i][0] = '0';	
			}
		}	
	i++;
	}
	char com ='#';
	int comodin = rand()% linea;
	arreglo[comodin][99] = com; 
	
	for(i=0; i< 50; i++){
		for(int j=0; j<100; j++){
			cout <<arreglo[i][j];
		}
		cout<<endl;
	}
	
	for(i=0; i< 50; i++){
		for(int j=0; j<100; j++){
			if(arreglo[i][j] == com){
				for(int k=0; k<100; k++){
					arreglo[i][k] = '\0';
				}
			}
		}
	}
	for(i=0; i< 50; i++){
		for(int j=0; j<100; j++){
			cout <<arreglo[i][j];
		}
		cout<<endl;
	}	
	return 0;
}
