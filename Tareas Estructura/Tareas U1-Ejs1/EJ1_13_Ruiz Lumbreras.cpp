#include <iostream>
#include <stdlib.h>

using namespace std;

void devolverCambio(int **, int, int);
void mostrar(int**, int, int);
int cont=0;
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
	devolverCambio(puntero,f,c);
	cout<<cont<<endl;
	
	for(int i=0; i<f; i++){
		delete[] puntero[i];
	}
	delete puntero;
	return 0;
	
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
void devolverCambio(int **puntero, int f, int c){
	int aux;
	for(int i=0; i<c; i++){
		for(int j=0; j<f; j++){
			aux = *(*(puntero+i)+j);
				if(j!=(c-1)){
					for(int k=i; k<f; k++){
						for(int l=j; l<c; l++){
							if(aux == *(*(puntero+k)+l+1)){
								*(*(puntero+k)+l+1) = -5;
								cont++;
							}
						}
					}
				}else if(i!=(f-1) && j!=(c-1)){
					for(int k=i; k<f; k++){
						for(int l=j; l<c; l++){
							if(aux == *(*(puntero+k+1)+l)){
								*(*(puntero+k+1)+l) = -5;
								cont++;
							}
						}
					}	
				}else if(j==(c-1) && (i+1)!=(f-1)){
					for(int k=i+1; k<f; k++){
						for(int l=0; l<c; l++){
							if(aux == *(*(puntero+k)+l)){
								*(*(puntero+k)+l) = -5;
								cont++;
							}
						}
					}
				}
				
			}	
	}
	mostrar(puntero,f,c);
}
