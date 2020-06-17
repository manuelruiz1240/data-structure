#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

typedef struct _node {
   char *name;
   unsigned char* seq;   // sequence, each position is a set of characters 
   int cost;             // cost
} node;
 
typedef node *pNodo;
pNodo Listado;

int main(int argc, char *argv[]){
	string filename;
	int filasBIN = 0;	//almacenara el primer numero de la primera fila, representa filas
	int columnasBIN = 0; //almacenara el segundo numero de la primera fila, representa columnas (solo los datos BIN)
	int advertenciaFilas = 0;
	int advertenciaColumnas = 0;

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
					Listado = new node[filasBIN];
				}	//este bloque de IF busca filas y columnas en la primera linea, busca el salto de linea y pasa al siguiente bloque
				bInit = 1;
			} else {
				int a = line.find_first_of(" ");
				if(a!=string::npos){
					string name = line.substr(0, a);
					string d = line.substr(a+2); //Para cada linea empieza a omitir todo char y al encontrar "  " empieza a contar los datos por fila * columna
					int e = d.length();
					Listado[count].name = new char[name.length()+1];
					sprintf(Listado[count].name, "%s", name.c_str());
					//valores[count] = d;
					Listado[count].seq = new unsigned char[d.length()+1];
					sprintf((char*)Listado[count].seq, "%s", d.c_str());
					//valores[count] = conversion(d);
					
				//	cout<< Listado[count].name << ",   " << Listado[count].seq << "\n";
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
	
	cout<<"\n datos guardados en Listado: \n";
	for (int k = 0; k<count; k++){
	   	cout<< Listado[k].name << "   " << Listado[k].seq << "\n";
	}
	/*	
	// recorriendo los valores por pares
	for (int k = 0; k+1 < count; k+=2){
		scores[(int)(k/2)]=0;
		for (int m = 0; m < columnasBIN; m++){
			//cout<<"\n k y m " << k << " " << m << endl;
			pNodo p;
	        p = new tipoNodo[1];
			if(valores[k].at(m)==valores[k+1].at(m)){
		    	p->dato = valores[k].at(m);
			} else {
		    	p->dato = valores[k].at(m);
		    	p->dato += valores[k+1].at(m);
		    	scores[(int)(k/2)]++;
			}
			//insertar p en una lista; al final se tendran count/2 listas
			cout<<"\n nodo p " << p->dato << " ";
		}
		cout<<"\n";
	}*/

/*
    cout<<"\n scores calculados y total \n";
    int scoreTotal = 0;
	for (int k = 0; k<count/2; k++){
	    cout<< scores[k] << "\n";
	    scoreTotal += scores[k];
	}
	cout<<"\n scores total " << scoreTotal << endl;*/
	return 0;
}
