#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int j=0, i=0, k;
	int primero[21];
	
	for (j = 0; j <= 7; j++){
		cin >> primero[j++];
	}
	
	while ((j < 6) && (primero[j - 1] < primero[j])){
		i++;
		j++;
	}

	for (k = -1; k < j + 2; k++ ){
		cout << primero[++k];
	}

	return 0;
}
