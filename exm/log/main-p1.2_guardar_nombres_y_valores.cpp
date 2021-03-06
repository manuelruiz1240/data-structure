#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct{
	string data;
}node;

int main(int argc, char *argv[]){
	string filename;
	int filasBIN = 0;	//almacenara el primer numero de la primera fila, representa filas
	int columnasBIN = 0; //almacenara el segundo numero de la primera fila, representa columnas (solo los datos BIN)
	int advertenciaFilas = 0;
	int advertenciaColumnas = 0;
	string *nombres, *valores;
	int count = 0; //Determina el numero de filas
	
	//cout << "Nombre del archivo> ";
	//getline( cin, filename );
	fstream file(argv[1], ios::in | ios::binary);	//filename.c_str()
	if (!file){
		cout << "No se reconoce el nombre del fichero.\n";
		return 0;
	} else {
		string line;
		int bInit =0;
		while(!file.eof()){ //empieza a iterar desde la primera linea
		    getline(file, line);
		    cout << line << '\n'; //Al llegar aqui busca el salto de linea.............
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
					cout << " filas: " << filasBIN << ", columnas" << columnasBIN << endl;
					nombres = new string[filasBIN];
					valores = new string[filasBIN];
				}	//este bloque de IF busca filas y columnas en la primera linea, busca el salto de linea y pasa al siguiente bloque
				bInit = 1;
			} else {
				int a = line.find_first_of(" ");
				if(a!=string::npos){
					string name = line.substr(0, a);
					string d = line.substr(a+2); //Para cada linea empieza a omitir todo char y al encontrar "  " empieza a contar los datos por fila * columna
					int e = d.length();
					nombres[count] = name;
					valores[count] = d;
					if(e!=columnasBIN){
						cout << "\n\tIncorrecto: No es igual el numero de columnas al numero indicado en la linea 1\n" << endl;
						 advertenciaColumnas = 0;
					} else {
						//cout << "Correcto: No es igual el numero de columnas al numero indicado en la linea 1" << endl;
						advertenciaColumnas = 1;
					}
				}
				count++; //cout << "valor actual de count: " << count << endl;
						//--- A partir de aqui, guardar cada linea ---
				
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
	
	cout<<"\n datos guardados en las listas de nombres y valores: \n";
	for (int k = 0; k<count; k++)
	{
	    cout<< nombres[k] << ",   " << valores[k] << "\n";
	}
		
	
	
	return 0;
}
