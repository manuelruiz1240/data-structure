#include <iostream>

using namespace std;
int main(int argc, char** argv) {
	
	int primero[21];
	int i, k, j;
	
	for (i=0; i<10; i++){
		primero[i] = i+3;
	}
	
	cin >> j >> k;
	
	for(i = j; i<=k;){
		cout << primero[i++];
	}

	return 0;
}
