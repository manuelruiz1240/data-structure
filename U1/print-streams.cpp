#include <iostream>
#include <fstream>
using namespace std;
int main(){
	char cadena[128];
	ifstream fe("streams.cpp");
	
	while(!fe.eof()){
		//fe >> cadena;
		fe.getline(cadena, sizeof(cadena));
		cout << cadena << endl;
	}
	
	fe.close();
	return 0;
}
