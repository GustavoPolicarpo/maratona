// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Maior e Posição
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1080

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N, M, C;

int main()
{
	
	for(int con=1; con<=100; con++)
	{
		
		cin >> N;
		if(N>M) { M=N; C=con;
		}
	}
	cout << M << endl << C << endl;
		
return 0;	
}
