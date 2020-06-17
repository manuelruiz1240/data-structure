#include <iostream>
using namespace std;

int main(int argc, char** argv) {

	char cadena[64];
	int digitos=0, vocales = 0, consonantes = 0;
	for (int z =0; z<64; z++) cadena [z] = 0;
	cout <<"Ingrese un texto"<<endl;
	fgets (cadena, 64, stdin);
	printf("Texto ingresado = %s", cadena);
	
	for(int x=0; x<64; x++){
		if(cadena[x] != 0){
			digitos++;
		}
	}
	
	int i=0;
	while(cadena[i] != 0 && cadena[i] != '\n'){
		char c = cadena[i];
		
		if((c >= 'a') && (c <= 'z')){
            c -= 'a' - 'A'; 
        }
        
		if(c == 'A' || c == 'E' || c=='I' || c=='O' || c=='U'){
			vocales ++;
		} else {
			consonantes++;
		}
		i++;
	}
	
	cout<<"\nDigitos: "<<digitos-1<<endl;
	cout<<"Vocales: "<<vocales<<endl;
	cout<<"Consonantes: "<<consonantes<<endl;

	system("PAUSE");
	return 0;
}
