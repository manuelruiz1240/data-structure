#include <iostream>
using namespace std;
int main(){
	char nombre[80];
	cout << "Introduzca su nombre\n";
	cin.getline(nombre,sizeof(nombre));
	cout << "Hola " << nombre << " como estas " << endl;
	return 0;
}
