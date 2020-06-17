#include <iostream>

using namespace std;
int main(int argc, char** argv) {
	int Tercero[3][12];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 12; j++) 
		{	
			Tercero[i][j] = i + j + 1;
		} 
	}

	for (int i = 0; i< 3; i++){ 
		int j = 2; 
		while (j < 12){ 
			cout << i << " " << j << " " << Tercero[i][j]; 
			j += 3; 
		} 
	}
	
	return 0;
}
