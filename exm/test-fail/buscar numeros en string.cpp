#include<iostream>
#include<cctype>
#include<string>
#include <sstream>
#include <iomanip>
using namespace std;

double num, nIndex;
string strName;
char number (string strName);
stringstream strStream;

int main()
{
cout << "Enter a string with numbers in it: ";
getline(cin, strName);
cout << number (strName) << endl;
}
 char number (string strName)
{
	while (1){

		for ( nIndex=0; nIndex < strName.length(); nIndex++)
			if (!isdigit(strName[nIndex])){
				continue;
			else 		
				strStream << strName[nIndex];
				strStream >>  num ;	
					cout <<   num ;
	break;
	}
return 0;
 }
