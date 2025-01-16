//LIBRARY HEADERS
#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

//PROTOTYPES
int chirotope (int,int);

int main(){
	system("cls");

	//DECLARATION VARIABLES
	int k = 0;
	int suma = 0;
	int maxVal = 4;
	double g[4][4];
	int chi1 = 0, chi2 = 0;
	
	cout<<"MATRIZ PARA LA MATROIDE U_2,4\n\n";

	//COMPUTING SMALL MATROID
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			suma = 0;
			k = 1;
			
			cout<<"\nOPERACIONES PARA g"<<i + 1<<","<<j + 1<<"\n";
			while (k < 5) {
				if(k != (i + 1) && k != (j + 1)) {
					chi1 = chirotope (i + 1, k);
					chi2 = chirotope (j + 1, k);
					cout<<"chi ("<< i + 1 <<", "<<k<<") * chi ("<<j + 1<<", "<<k<<") = "<<chi1<<" * "<< chi2<<" = "<< (chi1 * chi2)<<"\n";
					suma += chi1 * chi2;
				}
				
				k++;
			}
			
			g[i][j] = suma;
		}//for-j
	}//for-i
	
	//PRINTING MATRIX
	cout << "\n\n\n";
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			
			cout<< setw(6)<< g[j][i]<< "  ";
		}//for-j
		cout << "\n";
	}//for-i

	getch();
	return 0;
}

//RETURN ASSOCIATED VALUE TO 4 ELEMENTS
int chirotope (int x0, int x1)  {
	int x[] = {x0, x1};
	int signo = 0;
	int aux = 0;
	int inversiones = 0;
	
	if (x0 == x1) return 0;

	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 4; ++j) {
			if (x[i] > x[j]) {
				++inversiones;
			}
		}//for-j
	}//for-i
	
	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 4; ++j) {
			if (x[i] > x[j]) {
				aux = x[i];
				x[i] = x[j];
				x[j] = aux;
			}
		}//for-j
	}//for-i
	
	signo = 1;
	
	if(x[0] == 1 && x[1] == 4){
		signo = -1;
	} else if(x[0] == 2 && x[1] == 3){
		signo = -1;
	} else if(x[0] == 2 && x[1] == 4){
		signo = -1;
	} else if(x[0] == 3 && x[1] == 4){
		signo = -1;
	} 	
	
	signo *= pow(-1, inversiones);
	return signo;
}