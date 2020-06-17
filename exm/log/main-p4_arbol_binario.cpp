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

typedef unsigned char pardata;
char** names;
char** nucle;

typedef struct _elemento {
	int data;
   _elemento* padre;
   _elemento* izq;
   _elemento* der;
   int scoreLocal, scoreTotal;             // cost
} elemento;


elemento* nuevoElemento(int data)
{
    elemento* nodo = (elemento*)
                             malloc(sizeof(elemento));
    nodo->data  = data;
    nodo->izq  = NULL;
    nodo->der = NULL;
    nodo->padre  = NULL;
    nodo->scoreLocal = data;
    return(nodo);
}

void actualizarArbol(elemento** arbol, elemento* dat);
int Vacio(elemento* r);

/* Aplicar una función a cada elemento del árbol: */
void InOrden(elemento*, void (*func)(int*));
void Mostrar(int *d);

void recorrerArbol(elemento* a)
{
    /*1. both empty */
    if (a==NULL)
        return;
    else
    {
        cout<<"recibidos:(a,b) "<< a->data << endl;
        recorrerArbol(a->izq);
		recorrerArbol(a->der);
    }
    /* 3. one empty, one not -> false */
    return;
}


pardata conversion(char nuc)
{
	switch(nuc){
		case '0': return 0x01;
		case '1': return 0x02;
		case 'A': return 0x04;
		case 'T': return 0x08;
		case 'C': return 0x10;
		case 'G': return 0x20;
		case '-': return 0x40;
		case '?': return 0xFF;
		default : return 0x80;
	}
}

pardata** listaBinaria;

pardata *convertirFila(string &s)
{
     pardata * p = new pardata[s.length()];
     for (int i=0; i < s.length(); i++)
     {
	     p[i]= conversion(s.at(i));
	     //p[i] = 0x80;
	 }
	 return p;
}


int main(int argc, char *argv[]){
	elemento *root1 = nuevoElemento(1);
    root1->izq = nuevoElemento(2);
    root1->der = nuevoElemento(3);
    root1->izq->izq  = nuevoElemento(4);
    root1->izq->der = nuevoElemento(5);

    root1->der->izq  = nuevoElemento(6);
    root1->der->der = nuevoElemento(7);

    recorrerArbol(root1);
	
	
	
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
					
					names = new char*[filasBIN];
					nucle = new char*[filasBIN];
					listaBinaria = new pardata*[filasBIN];
				}	//este bloque de IF busca filas y columnas en la primera linea, busca el salto de linea y pasa al siguiente bloque
				bInit = 1;
			} else {
				int a = line.find_first_of(" ");
				if(a!=string::npos){
					string name = line.substr(0, a);
					string d = line.substr(a+2); //Para cada linea empieza a omitir todo char y al encontrar "  " empieza a contar los datos por fila * columna
					int e = d.length();
					Listado[count].name = new char[name.length()];
					sprintf(Listado[count].name, "%s", name.c_str());
					//valores[count] = d;
					Listado[count].seq = new unsigned char[d.length()];
					sprintf((char*)Listado[count].seq, "%s", d.c_str());
					
					
					names[count]= new char[name.length()];
					nucle[count]= new char[d.length()];
					sprintf(names[count], "%s", name.c_str());
					sprintf(nucle[count], "%s", d.c_str());
					
					listaBinaria[count] = convertirFila(d);
					cout<< listaBinaria[count] << "\n";
					//listaBinaria[count]
					
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
	
	cout<<"\n datos guardados en names y nucle: \n";
	for (int k = 0; k<count; k++){
	   	cout<< names[k] << "   " << nucle[k] << "\n";
	}
	
	cout<<"\n datos guardados en listaBinaria: \n";
	for (int k = 0; k<count; k++){
	    	for (int t = 0; t<columnasBIN; t++){
	     	printf("%x ",listaBinaria[k][t] );
    	}
    	cout<< "\n";
   }
   
   
   elemento* Arbolbin;
   //construyendo un arbol con la lista binaria
   	for (int k = 0; k+1 < count; k+=2){
		int sLocal=0;
		
		for (int m = 0; m < columnasBIN; m++){
	        //p = new tipoNodo[1];
			if(listaBinaria[k][m]==listaBinaria[k+1][m]){
			   	//p->dato = valores[k].at(m);
			} else {
		    	sLocal++;
			}
			//insertar p en una lista; al final se tendran count/2 listas
		//	cout<<"\n nodo p " << p->dato << " ";
		}
		elemento *it = nuevoElemento(sLocal);
		actualizarArbol(&Arbolbin, it);
		cout<<"\n";
	}
	
	printf("InOrden: ");
    InOrden(Arbolbin, Mostrar);
   
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


void actualizarArbol(elemento** arbol, elemento* dat)
{
	//cout<< "\n en actualizarArbol \n ";
	
   elemento* padre = NULL;
   elemento* actual = *arbol;

   /* Buscar el dato en el árbol, manteniendo un puntero al nodo padre */
   while(!Vacio(actual) && dat->scoreLocal != actual->scoreLocal) {
      padre = actual;
      if(dat->scoreLocal < actual->scoreLocal) actual = actual->izq;
      else if(dat->scoreLocal > actual->scoreLocal) actual = actual->der;
   }
   //cout<<"\n 2 \n";
   /* Si se ha encontrado el elemento, regresar sin insertar */
   if(!Vacio(actual)) return;
   /* Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
      el nodo raiz */
   if(Vacio(padre)) {
      *arbol = (elemento*)malloc(sizeof(elemento));
      (*arbol)->scoreLocal = dat->scoreLocal;
      (*arbol)->izq = (*arbol)->der = NULL;
   }
   /* Si el dato es menor que el que contiene el nodo padre, lo insertamos
      en la rama izquierda */
   else if(dat->scoreLocal < padre->scoreLocal) {
     actual = (elemento*)malloc(sizeof(elemento));
      padre->izq = actual;
      actual->scoreLocal = dat->scoreLocal;
      actual->izq = actual->der = NULL;
   }
   /* Si el dato es mayor que el que contiene el nodo padre, lo insertamos
      en la rama derecha */
  else if(dat->scoreLocal > padre->scoreLocal) {
      actual = (elemento*)malloc(sizeof(elemento));
      padre->der = actual;
      actual->scoreLocal = dat->scoreLocal;
      actual->izq = actual->der = NULL;
  }
	
}


/* Comprobar si un árbol es vacío */
int Vacio(elemento* r)
{
	//cout<<"\n en vacioactual \n";
   return r==NULL;
}

void InOrden(elemento* a, void (*func)(int*))
{
   if(a->izq) InOrden(a->izq, func);
   func(&(a->scoreLocal));
   if(a->der) InOrden(a->der, func);
}

/* Función de prueba para recorridos del árbol */
void Mostrar(int *d)
{
   printf("%d, ", *d);
}
