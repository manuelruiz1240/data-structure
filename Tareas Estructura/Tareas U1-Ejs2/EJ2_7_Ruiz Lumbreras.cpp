#include <iostream>

using namespace std;
int main(int argc, char** argv) {
	string candidato[2][5];
	candidato[0][0] = "Distrito";
	for(int i=1; i<5; i++){
		candidato[0][i] = "Candidato";
	}
	candidato[1][0] = "        ";
	candidato[1][1] = "    A    ";
	candidato[1][2] = "    B    ";
	candidato[1][3] = "    C    ";
	candidato[1][4] = "    D    ";
	
	int votos[5][5];
	votos[0][0]= 1;
	votos[1][0]= 2;
	votos[2][0]= 3;
	votos[3][0]= 4;
	votos[4][0]= 5;
	
	votos[0][1] = 194;
	votos[1][1] = 180;
	votos[2][1] = 221;
	votos[3][1] = 432;
	votos[4][1] = 820;
	
	votos[0][2] = 48;
	votos[1][2] = 20;
	votos[2][2] = 90;
	votos[3][2] = 50;
	votos[4][2] = 61;
	
	votos[0][3] = 206;
	votos[1][3] = 320;
	votos[2][3] = 140;
	votos[3][3] = 821;
	votos[4][3] = 946;

	votos[0][4] = 45;
	votos[1][4] = 16;
	votos[2][4] = 20;
	votos[3][4] = 14;
	votos[4][4] = 18;
		
	
	
	for(int i=0; i<2; i++){
		for(int j=0; j<5; j++){
			cout<<candidato[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			cout<<"   "<<votos[i][j]<<"    ";
		}
		cout<<endl;
	}
	int CA=0,CB=0,CC=0,CD=0;
	for(int i=0; i<5; i++){
		for(int j=1; j<5; j++){
			if(j==1){
				CA+=votos[i][j];
			}
			if(j==2){
				CB+=votos[i][j];
			}
			if(j==3){
				CC+=votos[i][j];
			}
			if(j==4){
				CD+=votos[i][j];
			}
		}
	}
	
	float suma = CA+CB+CC+CD;
	
	float pCA,pCB,pCC,pCD;
	pCA=CA/suma;
	pCB=CB/suma;
	pCC=CC/suma;
	pCD=CD/suma;
	
	cout<<"\nCA= "<<CA<<endl<<"CB= "<<CB<<endl<<"CC= "<<CC<<endl<<"CD= "<<CD<<endl;
	
	cout<<"El total de votos es: "<<suma<<endl<<"El promedio de cada candidato es: "<<endl;
	printf("CA = %.2f\n",pCA);
	printf("CB = %.2f\n",pCB);
	printf("CC = %.2f\n",pCC);
	printf("CD = %.2f\n",pCD);
	
	double mayor=pCA, segundo;
		if(pCB>mayor){
			mayor=pCB;
		}
		if(pCC>mayor){
			mayor=pCC;
		}
		if(pCD>mayor){
			mayor=pCD;
		}
			if(mayor==pCA){
				segundo=pCB;
				if(pCC>segundo){
					segundo=pCC;
				}
				if(pCD>segundo){
					segundo=pCD;
				}
				
				if(mayor>.50){
					cout<<"El Candidato ganador es el A"<<endl;
				}else{
					if(segundo==pCB){
						cout<<"Los candidatos que pasan a la segunda ronda son:"<<endl;
						cout<<"El candidato A y el candidato B"<<endl;
					}
					if(segundo==pCC){
						cout<<"Los candidatos que pasan a la segunda ronda son:"<<endl;
						cout<<"El candidato A y el candidato C"<<endl;
					}
					if(segundo==pCD){
						cout<<"Los candidatos que pasan a la segunda ronda son:"<<endl;
						cout<<"El candidato A y el candidato D"<<endl;
					}
					
				}
			}
			if(mayor==pCB){
				segundo=pCA;
				if(pCC>segundo){
					segundo=pCC;
				}
				if(pCD>segundo){
					segundo=pCD;
				}
				
				if(mayor>.50){
					cout<<"El Candidato ganador es el B"<<endl;
				}else{
					if(segundo==pCA){
						cout<<"Los candidatos que pasan a la segunda ronda son:"<<endl;
						cout<<"El candidato B y el candidato A"<<endl;
					}
					if(segundo==pCC){
						cout<<"Los candidatos que pasan a la segunda ronda son:"<<endl;
						cout<<"El candidato B y el candidato C"<<endl;
					}
					if(segundo==pCD){
						cout<<"Los candidatos que pasan a la segunda ronda son:"<<endl;
						cout<<"El candidato B y el candidato D"<<endl;
					}
					
				}
			}
			if(mayor==pCC){
				segundo=pCA;
				if(pCB>segundo){
					segundo=pCB;
				}
				if(pCD>segundo){
					segundo=pCD;
				}
				
				if(mayor>.50){
					cout<<"El Candidato ganador es el C"<<endl;
				}else{
					if(segundo==pCA){
						cout<<"Los candidatos que pasan a la segunda ronda son:"<<endl;
						cout<<"El candidato C y el candidato A"<<endl;
					}
					if(segundo==pCB){
						cout<<"Los candidatos que pasan a la segunda ronda son:"<<endl;
						cout<<"El candidato C y el candidato B"<<endl;
					}
					if(segundo==pCD){
						cout<<"Los candidatos que pasan a la segunda ronda son:"<<endl;
						cout<<"El candidato C y el candidato D"<<endl;
					}
					
				}
			}
			if(mayor==pCD){
				segundo=pCA;
				if(pCB>segundo){
					segundo=pCB;
				}
				if(pCC>segundo){
					segundo=pCC;
				}
				
				if(mayor>.50){
					cout<<"El Candidato ganador es el D"<<endl;
				}else{
					if(segundo==pCA){
						cout<<"Los candidatos que pasan a la segunda ronda son:"<<endl;
						cout<<"El candidato D y el candidato A"<<endl;
					}
					if(segundo==pCB){
						cout<<"Los candidatos que pasan a la segunda ronda son:"<<endl;
						cout<<"El candidato D y el candidato B"<<endl;
					}
					if(segundo==pCC){
						cout<<"Los candidatos que pasan a la segunda ronda son:"<<endl;
						cout<<"El candidato D y el candidato C"<<endl;
					}
					
				}
			}
			
		if(mayor > .50){
			
		}
		
	return 0;
}
