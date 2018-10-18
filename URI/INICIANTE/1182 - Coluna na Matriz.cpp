// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Coluna na Matriz
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1182

#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int col;
	char op;
	cin >> col >> op;
	
	double matriz[12][12];
	
	for(int i=0; i<12; i++){
		for(int j=0; j<12; j++){
			cin >> matriz[i][j];
		}
	}
	
	double soma=0;
	
	for( int i = 0; i < 12; i++ ){
		//soma = soma + matriz[i][col];
		soma += matriz[i][col];
	}
	
	cout << fixed << setprecision(1);
	
	if( op == 'S' ) 
		cout << soma << endl;
	else
		cout << soma/12 << endl;
	
	return 0;
	
}
