#include <iostream>

using namespace std;
int main(int argc, char** argv) {
	int primero[21];
	
	for (int i = 1; i <= 6; i++){
		printf("POSICION[%d]", i);
		cin >> primero[i];
	}

	for (int i = 3; i > 0; i--){
		cout << primero[2*i] << " ";
	}	
	return 0;
}
