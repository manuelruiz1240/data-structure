#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])  {
	string filename;
	int filasBIN = 0;	//almacenara el primer numero de la primera fila, representa filas
	int columnasBIN = 0; //almacenara el segundo numero de la primera fila, representa columnas (solo los datos BIN)
	
	//cout << "Nombre del archivo> ";
	//getline( cin, filename );
	fstream file(argv[1], ios::in | ios::binary);	//filename.c_str()
	if (!file){
		cout << "No se reconoce el nombre del fichero.\n";
		return 0;
	} else {
		string line;
		int count = 49; //Determina el numero de filas
		while ((count > 0) && getline( file, line )){ //empieza a iterar desde la primera linea
			/*if(count==0){	//Si estoy en la linea 0 buscara los datos de filas por columnas
			    cout << 'primera fila';
			}*/
			
			cout << line << '\n';
			count--;
		}
		file.close();
	}
	return 0;
}
