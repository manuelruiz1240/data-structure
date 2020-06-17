#include <iostream>

using namespace std;
int main(int argc, char** argv) {

	int n;
	cout<<"Ingrese la cantidad de numero a pedir:"<<endl;
	cin>>n;
	
	int cad[n];
	
	for(int i=0; i<c; i++){
		cout<<"Ingrese un numero:"<<endl;
		cin>>cad[i];
	}
	
	int sum=0;
	double media, varianza, desviacion;
	for(int i=0; i<c; i++){
		sum+=cad[i];
	}
	media = sum/n;
	printf("La media es:\n %.2lf", media);
	double suma=0;
	for(int i=0; i<c; i++){
		suma += (cad[i]-media)*(cad[i]-media);
	}
	
	varianza = suma/n;
	
	printf("La varianza es:\n %.2lf",varianza);
	return 0;
}
