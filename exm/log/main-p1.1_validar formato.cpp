#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]){
	string filename;
	int filasBIN = 0;	//almacenara el primer numero de la primera fila, representa filas
	int columnasBIN = 0; //almacenara el segundo numero de la primera fila, representa columnas (solo los datos BIN)
	int advertenciaFilas = 0;
	int advertenciaColumnas = 0;
	
	//cout << "Nombre del archivo> ";
	//getline( cin, filename );
	fstream file(argv[1], ios::in | ios::binary);	//filename.c_str()
	if (!file){
		cout << "No se reconoce el nombre del fichero.\n";
		return 0;
	} else {
		string line;
		int count = 0; //Determina el numero de filas
		int bInit =0;
		while(!file.eof()){ //empieza a iterar desde la primera linea
		    getline(file, line);
		    cout << line << '\n';
			if(bInit==0){ //Si estoy en la linea 0 buscara los datos de filas por columnas
			    //cout << "primera fila" << endl;
			    int a = line.find_first_of(" "); //Busca el espacio en blanco
				if(a!=string::npos){
					string b = line.substr( 0, a );
					string c = line.substr(a+1);
					//cout << "Test: rows, cols> " << b << c << endl;
					sscanf(b.c_str(), "%d", &filasBIN);
					sscanf(c.c_str(), "%d", &columnasBIN);
					//columnasBIN = stoi(c);
					//cout << " aaaa: " << filasBIN << columnasBIN << endl;
				} 
				bInit = 1;
			} else {
				int a = line.find_first_of(" ");
				if(a!=string::npos){
					string d = line.substr(a+2); //Para cada linea empieza a omitir todo char y al encontrar "  " empieza a contar los datos por fila * columna
					int e = d.length();
					if(e!=columnasBIN){
						cout << "\n\tIncorrecto: No es igual el numero de columnas al numero indicado en la linea 1\n" << endl;
						 advertenciaColumnas = 0;
					} else {
						//cout << "Correcto: No es igual el numero de columnas al numero indicado en la linea 1" << endl;
						advertenciaColumnas = 1;
					}
				}
				count++; //cout << "valor actual de count: " << count << endl;
			}
		}
		//cout << "valor actual de count: " << count << endl; //Se refiere al numero de filas
		if(count==filasBIN){
			//cout << "Correcto: Es igual el numero de filas al numero indicado en la linea 1" << endl;
			advertenciaFilas = 1;
		} else {
			cout << "Incorrecto: No es igual el numero de filas al numero indicado en la linea 1." << endl;
			advertenciaFilas = 0;
		}
		if(advertenciaFilas==1 && advertenciaColumnas==1){
			cout << "\nCorrecto: EL formato del fichero esta validado por " << filasBIN << " filas & " << columnasBIN << " columnas. Predefinido en la linea 1." << endl;
		}
		file.close();
	}
	return 0;
}
