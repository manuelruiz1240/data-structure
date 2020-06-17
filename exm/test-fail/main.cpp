#include <iostream>
#include <fstream>
using namespace std;
int main(){
	char phylipNAME;
    cout << "Ingrese nombre del archivo: ";
	cin >> phylipNAME;
	
	char cadena[128];
	ifstream phylipFILE("ANGI.txt", ios::in | ios::binary);	// phylipFILE es el objeto qie recibe ANGIE.txt como parametro
	if (phylipFILE.is_open()) { // Compruebo si he podido abrir
		while(!phylipFILE.eof()){
			//fe >> cadena;
			phylipFILE.getline(cadena, sizeof(cadena));
			cout << cadena << endl;
		}	//SI hasta aqui esta todo bien, entonces ya debio terminar de mostrar cada linea
			
		#cout << cadena[0-1]; cout << cadena[0]; cout << cadena[1]; cout << cadena[2]; cout << cadena[3];cout << cadena[4]; cout << cadena[5]; cout << cadena[6]; cout << cadena[7];
		phylipFILE.close(); // Finalmente, cierro
	} else {
		cout << "Archivo inexistente" << endl; // Si no he podido abrir, aviso
		return 0;
	}
}
