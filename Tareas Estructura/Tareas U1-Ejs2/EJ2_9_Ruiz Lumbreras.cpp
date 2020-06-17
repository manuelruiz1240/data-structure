#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	char linea[64];
	
	char abc[26];
	int suma[26];
	int i, j;
	abc[0]='A';
	abc[1]='B';
	abc[2]='C';
	abc[3]='D';
	abc[4]='E';
	abc[5]='F';
	abc[6]='G';
	abc[7]='H';
	abc[8]='I';
	abc[9]='J';
	abc[10]='K';
	abc[11]='L';
	abc[12]='M';
	abc[13]='N';
	abc[14]='O';
	abc[15]='P';
	abc[16]='Q';
	abc[17]='R';
	abc[18]='S';
	abc[19]='T';
	abc[20]='U';
	abc[21]='V';
	abc[22]='W';
	abc[23]='X';
	abc[24]='Y';
	abc[25]='Z';
	
	for(i=0; i<26; i++){
		suma[i] =0;
	}
	
	cout<<"Ingrese una palabra:"<<endl;
	cin >> linea;
	
	char c;
	bool salir = false;
	i=0;
	while(salir == false){
		c = linea[i];
		if(c >='a' && c<= 'z'){
			c -= 32;
			linea[i]=c; 
		}
		else{
			if(c >= 'A' && c <= 'Z'){
				
			}else{
				for(j=i; j<64; j++){
				linea[j] = '\0';
				salir = true;
				}
			}			
		}
	i++;
	}
	
	for(j=0; j<i-1; j++){
		c = linea[j];
		for(int k=0; k<26; k++){
			if(c == abc[k]){
			suma[k]+=1;
			}
		}
	}
		
	int mayor = suma[0];
	int pos;
	for(j=1; j<26; j++){
		if(suma[j] > mayor){
			mayor = suma[j];
			pos = j;
		}
	}
	
	for(i=0; i<64; i++){
		if(linea[i] == 'A' || linea[i] == 'E' || linea[i] == 'I' || linea[i] == 'O' || linea[i] == 'U'){
			linea[i] = abc[pos];
		}
	}
	for(i=0; i<64; i++){
		c = linea[i];
		c+=32;
		linea[i] = c;
		cout <<linea[i];
	}
	return 0;
}
