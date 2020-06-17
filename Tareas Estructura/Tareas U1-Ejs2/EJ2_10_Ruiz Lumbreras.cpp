#include <iostream>
#include <cstring>

using namespace std;

void anagrama(int, int);

	char p1[20];
	char p2[20];
	
int main(int argc, char** argv) {
	
	cout <<"Ingrese la primera palabra:"<<endl;
	cin.getline(p1,20,'\n');
	cout <<"Ingrese la segunda palabra:"<<endl;
	cin.getline(p2,20,'\n');
	
	int lon1 = strlen(p1);
	int lon2 = strlen(p2);
	
	anagrama(lon1, lon2);

	return 0;
}

void anagrama(int n1, int n2){
	int x=0;
	if(n1 == n2){	
		for(int i=0; i<n1; i++){
			for(int j=0; j<n1; j++){
				if(p1[j] == p2[i] || p1[j] == p2[i+32] || p1[j] == p2[i-32]){
					x++;
				}	
			}
		}
	}
	if(x==n1){
		cout<<"Las palabras son anagramas."<<endl;
	}else{
		cout<<"Las palabras no son anagramas."<<endl;
	}
	
}
