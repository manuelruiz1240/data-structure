#include <iostream>
using namespace std;
main(int argc, char *argv[]){
	if(argc<2){
		cout<<"Ha olvidado su nombre"<<endl;
		exit(1);
	}
	cout << "Hola " << argv[1] <<endl;
}
