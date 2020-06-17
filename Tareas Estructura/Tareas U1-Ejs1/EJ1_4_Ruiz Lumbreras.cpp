#include <iostream>

using namespace std;
int main(int argc, char** argv) {

	int primero[21];
	int segundo[21];
	int i, j, k;
	for (i = 0; i < 12; i++){
		cin >> primero[i];
	}

	for (j = 0; j < 6; j++){
		segundo[j] = primero[2 * j] + j;
	}

	for (k = 3; k <= 7; k++){
		cout << primero[k + 1] << " " << segundo [k - 1];
	}

	return 0;
}
