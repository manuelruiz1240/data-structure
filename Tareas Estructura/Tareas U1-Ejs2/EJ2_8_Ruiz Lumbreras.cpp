#include <iostream>

using namespace std;
int main(int argc, char** argv) {
	
	int arreglo[5]{1,2,3,4,5};
	
	int *direccion = arreglo;
	
	for(int i=0; i<5; i++){
		cout<<"Arreglo["<<i<<"] : "<<*direccion<<endl;
		*direccion++;
	}
	return 0;
}
