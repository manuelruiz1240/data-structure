#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int k, j;
	int segundo[21];
	cin >> k;
	for(int i=3; i<k; k++){
		cin >> segundo[i++];
		j = 4;
		cout << segundo[k] << " " << segundo[j+1];
	}
	return 0;
}
