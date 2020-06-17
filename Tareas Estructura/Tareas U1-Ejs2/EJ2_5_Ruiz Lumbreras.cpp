#include <iostream>

using namespace std;
int main(int argc, char** argv) {
	int fil, col, i, j;
	
	cout<<"Ingrese las filas de la Matriz:"<<endl;
	cin >> fil;
	cout<<"Ingrese las columnas de la Matriz:"<<endl;
	cin >> col;
	
	int matriz[fil][col];
	
	for(i=0; i<fil; i++){
		for(j=0; j<col; j++){
			printf("posicion[%d][%d]", i, j);
			cin>>matriz[i][j];
		}
	}
	int mayor = matriz[0][0];
	int y1,x1;
	
	for(i=0; i<fil; i++){
		for(j=0; j<col; j++){
			if(matriz[i][j]>=mayor){
				mayor = matriz[i][j];
				x1 = j;
				y1 = i;			
			}
		}
	}
	
	int menor = matriz[0][0];
	int x2, y2;
	for(i=0; i<fil; i++){
		for(j=0; j<col; j++){
			if(matriz[i][j]<=menor){
				menor = matriz[i][j];
				x2 = j;
				y2 = i;			
			}
		}
	}
	
	for(i=0; i<fil; i++){
		for(j=0; j<col; j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
	
	printf("El mayor se encuentra en la posicion[%d][%d]", y1,x1);
	cout<<endl;
	printf("El menor se encuentra en la posicion[%d][%d]", y2,x2);
	
	return 0;
}
