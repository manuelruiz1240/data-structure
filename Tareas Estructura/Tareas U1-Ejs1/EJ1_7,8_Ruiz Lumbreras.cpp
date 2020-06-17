#include <iostream>
#include <ctype.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	int i,j;
	int array[3][5];
	
	for(i=0; i<3; i++){
		for(j=0; j<5; j++){
			printf("Posicion[%d][%d]", i, j);
			cin >> array[i][j];
		}
	}
	
	for(i=0; i<3; i++){
		for(j=0; j<5; j++){
			cout << array[i][j]<<" ";
		}
		cout <<endl;
	}
	
	cout <<endl;
	//Traspuesta
	
	for(i=0; i<5; i++){
		for(j=0; j<3; j++){
			cout << array[j][i]<<" ";
		}
		cout <<endl;
	}
	
	//Suma de los elementos que no pertenecen a la diagonal
	int suma=0;
	int diagonal[4][4];
	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("Posicion[%d][%d]  ", i, j);
			cin >> diagonal[i][j];
		}
	}
	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(i!=j){
				suma += diagonal[i][j];
			}
		}
	}
	cout <<"La suma es: "<<suma<<endl;
	system("PAUSE");
	return 0;
}

