#include <iostream>
#include <string.h>

using namespace std;
char arreglo[80][100];

void leerTexto(){
	for(int i=0; i< 80; i++){
		for(int j=0; j<100; j++){
			cout <<arreglo[i][j];
		}
		cout<<endl;
	}
}
int main(int argc, char** argv) {
	
	bool salir = false;
	int i=0;
	cout<<"Escriba texto Pulse (0 + enter) para salir:"<<endl;
	while(salir == false){
		if(arreglo[i-1][0] == '0'){
			for(int x=i-1; x<80; x++){
				for(int z=0; z<100; z++){
					arreglo[x][z] = ' ';
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
				for(int k=longi+1; k<100; k++){
					arreglo[i][k] = ' ';
				}
			}
			else{
				arreglo[i][0] = '0';	
			}
		}	
	i++;
	}
	leerTexto();
		
	return 0;
}

