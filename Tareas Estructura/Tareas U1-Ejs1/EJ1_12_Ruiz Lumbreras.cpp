#include <iostream>
#include <stdlib.h>
using namespace std;

void traspuesta(int **, int, int);
void mostrar(int**, int, int);

int main(int argc, char** argv) {
	
	int f,c;
	cout<<"Ingrese el numero de filas: "<<endl;
	cin>>f;
	cout<<"Ingrese el numero de columnas: "<<endl;
	cin>>c;
	
	int **puntero = new int*[f];
	for(int i=0; i<f; i++){
		puntero[i] = new int[c];
	}
	
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			cout<<"Ingrese el valor para matriz["<<i<<"]["<<j<<"]"<<endl;
			cin>>*(*(puntero+i)+j);
		}
	}
	
	mostrar(puntero, f, c);
	cout<<endl;
	traspuesta(puntero,f,c);
	
	for(int i=0; i<f; i++){
		delete[] puntero[i];
	}
	delete puntero;
	return 0;
}

void mostrar(int **puntero, int f, int c){
	for(int i=0; i<f; i++){
	for(int j=0; j<c; j++){
		cout<<*(*(puntero+i)+j)<<" ";
	}
	cout<<endl;
	}
}
void traspuesta(int **puntero, int f, int c){
	for(int i=0; i<c; i++){
		for(int j=0; j<f; j++){
			cout<<*(*(puntero+j)+i)<<" ";
		}
		cout<<endl;
	}
}
