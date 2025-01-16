//LIBRARY HEADERS
#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

//PROTOTYPES
int chirotope (int,int,int,int);

int main(){
	system("cls");

	//DECLARING VARIABLES
	int k = 0;
	int l = 0;
	int m = 0;
	int suma = 0;
	int maxVal = 8;
	float g[8][8];
	//int chi1 = 0, chi2 = 0;
	
	cout<<"MATRIZ PARA LA MATROIDE U_4,8\n\n";

	//COMPUTING SMALL MATROID
	for (int i = 0; i < maxVal; ++i) {
		for (int j = 0; j < maxVal; ++j) {
			k = 1;
			l = 1;
			m = 1;
			suma = 0;
			
			//cout<<"\nOPERACIONES PARA g"<<i + 1<<","<<j + 1<<"\n";
			while (k <= maxVal) {
				if ((i + 1) != k && (i + 1) != l && (i + 1) != m && (j + 1) != k && (j + 1) != l && (j + 1) != m && k != l && k != m && l != m) {
	  		  		//chi1 = chirotope (i + 1,k,l,m);
					//chi2 = chirotope (j + 1,k,l,m);
					//cout<<"chi ("<< i + 1 <<", "<<k<<", "<<l<<", "<<m<<") * chi ("<<j + 1<<", "<<k<<", "<<l<<", "<<m<<") = "<<chi1<<" * "<< chi2<<" = "<< (chi1 * chi2)<<"\n";
					//suma += chi1 * chi2;
					suma += chirotope (i + 1,k,l,m) * chirotope (j + 1,k,l,m);
				}
				++m;
				if (m == maxVal + 1) {
					m = 1;
					++l;
				}//if-m

				if (l == maxVal + 1) {
					l = 1;
					++k;
				}//if-l
			}//while-k

			g[i][j] = suma/6.0;
			cout<< setw(6)<< g[i][j]<< "  ";
		}//for-j
		cout << "\n";
	}//for-i
	
	getch();
	return 0;
}

//RETURN ASSOCIATED VALUE TO 4 ELEMENTS
int chirotope (int x0, int x1, int x2, int x3)  {
	int x[] = {x0, x1, x2, x3};
	int signo = 0;
	int aux;
	int inversiones = 0;

	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 4; ++j) {
			if (x[i] > x[j]) {
				++inversiones;
				aux = x[i];
				x[i] = x[j];
				x[j] = aux;
			} else if (i != j && x[i] == x[j]) {
				return 0;
			}
		}//for-j
	}//for-i
	
	signo = 1;
	
	if(x[0] == 1 && x[1] == 2 && x[2] == 4 && x[3] == 7){
		signo = -1;
	} else if(x[0] == 1 && x[1] == 2 && x[2] == 5 && x[3] == 7){
		signo = -1;
	} else if(x[0] == 1 && x[1] == 2 && x[2] == 5 && x[3] == 8){
		signo = -1;
	} else if(x[0] == 1 && x[1] == 2 && x[2] == 6 && x[3] == 7){
		signo = -1;
	} else if(x[0] == 1 && x[1] == 2 && x[2] == 6 && x[3] == 8){
		signo = -1;
	} else if(x[0] == 1 && x[1] == 3 && x[2] == 4 && x[3] == 5){
		signo = -1;
	} else if(x[0] == 1 && x[1] == 3 && x[2] == 4 && x[3] == 7){
		signo = -1;
	} else if(x[0] == 1 && x[1] == 3 && x[2] == 6 && x[3] == 7){
		signo = -1;
	} else if(x[0] == 1 && x[1] == 3 && x[2] == 6 && x[3] == 8){
		signo = -1;
	} else if(x[0] == 1 && x[1] == 4 && x[2] == 5 && x[3] == 7){
		signo = -1;
	} else if(x[0] == 1 && x[1] == 4 && x[2] == 5 && x[3] == 8){
		signo = -1;
	} else if(x[0] == 1 && x[1] == 4 && x[2] == 6 && x[3] == 8){
		signo = -1;
	} else if(x[0] == 1 && x[1] == 5 && x[2] == 7 && x[3] == 8){
		signo = -1;
	} else if(x[0] == 2 && x[1] == 3 && x[2] == 4 && x[3] == 5){
		signo = -1;
	} else if(x[0] == 2 && x[1] == 3 && x[2] == 4 && x[3] == 6){
		signo = -1;
	} else if(x[0] == 2 && x[1] == 3 && x[2] == 4 && x[3] == 7){
		signo = -1;
	} else if(x[0] == 2 && x[1] == 3 && x[2] == 4 && x[3] == 8){
		signo = -1;
	} else if(x[0] == 2 && x[1] == 3 && x[2] == 6 && x[3] == 7){
		signo = -1;
	} else if(x[0] == 2 && x[1] == 4 && x[2] == 6 && x[3] == 7){
		signo = -1;
	} else if(x[0] == 2 && x[1] == 5 && x[2] == 7 && x[3] == 8){
		signo = -1;
	} else if(x[0] == 2 && x[1] == 6 && x[2] == 7 && x[3] == 8){
		signo = -1;
	} else if(x[0] == 3 && x[1] == 4 && x[2] == 5 && x[3] == 7){
		signo = -1;
	} else if(x[0] == 3 && x[1] == 4 && x[2] == 5 && x[3] == 8){
		signo = -1;
	} else if(x[0] == 3 && x[1] == 4 && x[2] == 6 && x[3] == 7){
		signo = -1;
	} else if(x[0] == 3 && x[1] == 4 && x[2] == 6 && x[3] == 8){
		signo = -1;
	} else if(x[0] == 3 && x[1] == 5 && x[2] == 7 && x[3] == 8){
		signo = -1;
	} else if(x[0] == 3 && x[1] == 6 && x[2] == 7 && x[3] == 8){
		signo = -1;
	} else if(x[0] == 4 && x[1] == 5 && x[2] == 6 && x[3] == 7){
		signo = -1;
	} else if(x[0] == 4 && x[1] == 5 && x[2] == 7 && x[3] == 8){
		signo = -1;
	} else if(x[0] == 4 && x[1] == 6 && x[2] == 7 && x[3] == 8){
		signo = -1;
	}	
	
	signo *= pow(-1, inversiones);
	return signo;
}