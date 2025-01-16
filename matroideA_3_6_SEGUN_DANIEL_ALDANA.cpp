//LIBRERIAS
#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;

//PROTOTYPES
int valor(int,int,int);
void ordenar(int[]);
string presentar(int);

int main(){
	system("cls");

	//DECLARATION VARIABLES
	int l = 0, m = 0;
	int suma = 0;
	int maxVal = 6;
	int g[maxVal][maxVal];
	
	cout<<"MATRIZ PARA LA MATROIDE A_3,6\n\n";

	//COMPUTING SMALL MATROID
	for (int i = 0; i < maxVal; ++i) {
		for (int j = 0; j < maxVal; ++j) {
			l = 1;
			m = 1;
			suma = 0;

			while (l <= maxVal) {
				suma += valor(i + 1,l,m) * valor(j + 1,l,m);//UNO CON i, OTRO CON j
				++m;
				
				if (m == maxVal + 1) {
					m = 1;
					++l;
				}//if-m
			}//while-l

			g[i][j] = suma;
		}//for-j
	}//for-i
	

	//PRINTING MATRIX
	for (int i = 0; i < maxVal; ++i) {
		for (int j = 0; j < maxVal; ++j) {

			//CHECHAR LOS MÁRGENES DEL ACOMODO DE LA MATRIZ
			/*if ( (9 < abs(g[i][j])) && ( abs(g[i][j]) < 100 ) ) {
				if (g[i][j] < 0) {
					cout << g[i][j];
				} else {
					cout << " " << g[i][j];
				}
			}

			if ((99 < g[i][j]) && (g[i][j] < 1000)) {
				cout << g[i][j];
			}
			cout << "  ";
			*/
			g[i][j] /=4;
			cout<< setw(6)<< g[i][j]<< "  ";
			//cout<<presentar(g[i][j]) << "   ";
		}//for-j
		cout << "\n";
	}//for-i

	getch();
	return 0;
}

void ordenar (int x[3]) {
	int aux;

	//BUBBLE SORT. NOTHING NEW.
	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 4; ++j) {	
			if (x[i] > x[j]) {//ANALIZE <>
				aux = x[i];
				x[i] = x[j];
				x[j] = aux;
			}
		}//for-j
	}//for-i
}//void ordenar

//RETURN ASSOCIATED VALUE TO 3 ELEMENTS
int valor(int x0, int x1, int x2)  {
	int x[] = {x0, x1, x2};
	int signo = 0;
	int inversiones = 0;

	for (int i = 0; i < 2; ++i) {
		for (int j = i + 1; j < 3; ++j) {
			if (x[i] > x[j]) {
				++inversiones;
			} else if (x[i] == x[j] && i != j) return 0;
		}//for-j
	}//for-i

	ordenar (x);
	
	
	//COMPARING WITH CHIROTOPE
	signo = 1;
	if(x[0] == 1 && x[1] == 3 && x[2] == 4){
		signo = -1;
	} else if(x[0] == 2 && x[1] == 3 && x[2] == 4){
		signo = -1;
	} else if(x[0] == 2 && x[1] == 3 && x[2] == 5){
		signo = -1;
	}	
	
	//arreglo matematico para las inversiones
	signo *= pow(-1, inversiones);
	return signo;
}

string presentar(int x){
	string s = "";
	int d = 0;
	for (int i = 0; i <= ceil(log10(x)) + 1; ++i)  {
		d = x % 10;
		x = floor(x / 10.0);
		
		if(i == 0){
			s = to_string(d) + s;
		} else {
			s = to_string(d) + "," + s;
		}
		
	}

	return "{" + s + "}";
}
