//LIBRARY HEADERS
#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;


//PROTOTYPES
void compute_print_matrix (int elements, int rank, char chirotope_mapping[]);
int chirotope(int tuple[], int elements, int rank, char chirotope_mapping[]);
void print_chirotope (int elements, int rank, char chirotope_mapping[]); 
int combinatorial(int n, int k);
int combinatorialHash (int a[], int length, int max);
long fact(int);
void printArray(int a[], int);

int main(){
	int op = 0;
	int op2 = 0;
	int length_chirotope;
	int rank;
	int elements;
	int change_element;
	char value;
	
	system("cls");
	
	do {
		cout<<"\n\n\n\nMENU DE CHIROTOPES\n\n";
		cout<<"[ 1 ] CREAR UN NUEVO CHIROTOPE\n";
		cout<<"[ 2 ] SALIR \nOPCION ELEGIDA: ";
		cin>>op;
		
		switch (op) {
			case 1://CHIROTOPE
				cout<<"\n\nCREACION DE NUEVA MATROIDE";
				cout<<"\nINGRESE EL NUMERO DE ELEMENTOS DE LA MATROIDE: ";
				cin>>elements;
				
				cout<<"INGRESE EL RANGO DE LA MATROIDE: ";
				cin>>rank;
				
				length_chirotope = combinatorial(elements, rank);
				//char chirotope_mapping [length_chirotope];
				char chirotope_mapping[250];
				
				for (int i = 0; i < length_chirotope; i++){
					if(i % 3 == 0) chirotope_mapping[i] = '+';
					else if(i % 3 == 1) chirotope_mapping[i] = '0';
					else chirotope_mapping[i] = '-';
				}
				print_chirotope (elements, rank, chirotope_mapping);
				compute_print_matrix (elements, rank, chirotope_mapping);
				
				//CHANGE CHIROTOPE
				do {
					cout<<"\n\nCAMBIAR SIGNOS DEL CHIROTOPE?\n";		
					cout<<"[ 1 ] SI\n";
					cout<<"[ 2 ] NO \nOPCION ELEGIDA: ";
					cin>>op2;
					if(op2 == 2) {
					} else {
						system("cls");
						print_chirotope (elements, rank, chirotope_mapping);
						//salt:
						//SIGN CHANGES
						cout<<"\n\nTECLEA EL ELEMENTO A CAMBIAR DEL CHIROTOPE: ";
						cin>>change_element;
						
						cout<<"\nVALOR DE REEMPLAZO ['-', '0', '+']: ";
						cin>>value;
						
						if(value != '-' && value != '+') value = '0';
						chirotope_mapping[change_element] = value;
						
						
						print_chirotope (elements, rank, chirotope_mapping);
					}
				} while(op2 != 2);//do-while
				compute_print_matrix (elements, rank, chirotope_mapping);
			break;
			case 2:
				cout<<"\n\nFINALIZANDO PROGRAMA...\n";
				//exit(0);
				return 0;
			break;
			default: cout<<"\n\nOPCION NO DISPONIBLE\n";
		}//switch
	} while (op != 2);
	//getch();
	cin.ignore();
	return 0;
}//int main

void compute_print_matrix (int elements, int rank, char chirotope_mapping[]){
	//DECLARING VARIABLES
	int aux = 0;
	int suma = 0;
	int g[elements][elements];
	int lim = pow(elements, rank);
	int k = 0;
	int tuple[rank];
	int aux_chirotope;
	
	//COMPUTING SMALL MATROID
	cout<<"\n\nMATRIZ DE LA MATROIDE:\n";
	for (int i = 0; i < elements; ++i) {
		for (int j = 0; j < elements; ++j) {
			suma = 0;
			
			
			k = 0;
			for (int m = 0; m < rank-k - 1; m++){
				tuple[m] = 1;
			}
			
			for (int m = 0; m < lim; m++){
				tuple[rank - 1] = i;
				aux_chirotope = chirotope(tuple, elements, rank, chirotope_mapping);
				tuple[rank - 1] = j;
				suma += aux_chirotope * chirotope(tuple, elements, rank, chirotope_mapping);
				
				
				tuple[rank - 2]++;
				for (int n = rank - 2; tuple[n] > elements && n > 0; n--){
					tuple[n] = 1;
					tuple[n - 1]++;
				}
			}

			g[i][j] = suma;
			cout<< setw(6)<< g[i][j]<< "  ";
		}//for-j
		cout << "\n";
	}//for-i
}//void calcular_matriz

//RETURN ASSOCIATED VALUE TO A TUPLE
int chirotope(int tuple[12], int elements, int rank, char chirotope_mapping[])  {
	int signo = 0;
	int aux = 0;
	int inversiones = 0;
	int hash = 0;

	for (int i = 0; i < rank - 1; ++i) {
		for (int j = i + 1; j < rank; ++j) {
			if (tuple[i] > tuple[j]) {
				++inversiones;
				aux = tuple[i];
				tuple[i] = tuple[j];
				tuple[j] = aux;
			} else if (tuple[i] == tuple[j] && i != j) {
				return 0;
			}
		}//for-j
	}//for-i
	
	hash = combinatorialHash(tuple,rank, elements);
	if(chirotope_mapping[hash] == '+') signo = 1;
	else if(chirotope_mapping[hash] == '-') signo = -1;
	else return 0;
	
	signo *= pow(-1, inversiones);
	return signo;
}//int chirotope

void print_chirotope (int elements, int rank, char chirotope_mapping[]) {
	cout<<"\n\nMAPEO DEL CHIROTOPE:\n";
	int tuple[rank];
	for(int i = 0; i < rank; i++){
		tuple[i] = i + 1;
	}
		
	int hash;
	int nck = combinatorial(elements, rank) - 1;
	int i = 0;
	int aux;
	while(hash < nck){
		hash = combinatorialHash(tuple, rank,elements);
		cout<<hash<<")   {";
		/*for(int j = 0; j < rank; j++){
			cout<<tuple[j]<<"";
			if(j < rank - 1) cout<<", ";
		}*/
		printArray(tuple, rank);
		cout<<"}   --> "<<chirotope_mapping[hash]<<"\n";
		for(i = rank - 1; i >= 0; i--){
			if(tuple[i] <= elements - rank + i) break;
		}
		
		aux = tuple[i];
		for (int j = 0; j < rank-i; j++){
			tuple[j+i] = aux + j + 1;
		}
	}
}//void print_chirotope

int combinatorial(int n, int k){
	if (n < 0 || k < 0) return 0;
	else if (n == k) return 1;
	else if (k == 1 || k == n - 1) return n;
	else if (k == 0) return 1;
	else if (n == 0) return 0;
	else return (combinatorial(n - 1, k - 1) + combinatorial(n - 1, k));
}

int combinatorialHash (int a[], int length, int max){
	int hash = 0;
	int j = 0;
	
	for (int i = 0; i < length; i++){
		
		if (i > 0) j = a[i-1] + 1;
		else j = 1;
		for (; j < a[i]; j++){
			hash += combinatorial(max - j, length - 1 - i);
		}
	}
	
	return hash;
}

// Returns factorial of n
long fact(int n) {
      if(n==0)
      return 1;
    long res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

void printArray (int a[], int length){
	for (int i = 0; i < length; i++){
		cout<<""<<a[i]<<"";
		if(i < length - 1) cout<<", ";
	}//FOR	
	//cout<<"\n";
}