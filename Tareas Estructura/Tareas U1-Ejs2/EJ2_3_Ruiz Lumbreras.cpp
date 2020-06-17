#include <iostream>

using namespace std;
int main(int argc, char** argv) {
	int n;
	do{
		cout<<"Ingrese un numero impar del 3 al 11:"<<endl;
		cin>>n;
	}while(n%2 == 0 && n<=11);

	int cuadrado[n][n];
	int x=0,d=n*n, y=(n-1)/2;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cuadrado[i][j]=0;
		}
	}
	cuadrado[x][y]=1;
	
	for(int i=2; i<=d; i++){
		if(x==0 && y== n-1){
			if(cuadrado[n-1][0] != 0){
				cuadrado[x+1][y] =i;
				x=x+1;
			}else{
				cuadrado[n-1][0] = i;
				x=n-1;
				y=0;	
			}
			
		}else if(x==0 && y != n){
			if(cuadrado[n-1][y+1] !=0){
				cuadrado[x+1][y] = i;
				x= x+1;
			}
			else{
				cuadrado[n-1][y+1] = i;
				x=n-1;
				y=y+1;
			}
		}else if(x!=0 && y==n-1){
			if(cuadrado[x-1][0] !=0){
				cuadrado[x+1][y] = i;
				x=x+1;
			}else{
				cuadrado[x-1][0] =i;
				x=x-1;
				y=0;
			}
		}
		
		else{
			if(cuadrado[x-1][y+1] !=0){
				cuadrado[x+1][y] =i;
				x=x+1;
			}
			else{
				cuadrado[x-1][y+1] = i;
				x= x-1;
				y=y+1;
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<cuadrado[i][j]<<" ";
		}
		cout<<endl;
	}
		
	return 0;
}
