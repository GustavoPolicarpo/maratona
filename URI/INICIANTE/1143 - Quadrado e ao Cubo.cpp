// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Quadrado e ao Cubo
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1143

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N, SEQ=1;

int main()
{
	cin >> N;
	for(int con=1; con<=N; con++)
	{
		cout << SEQ << " " <<  SEQ*SEQ << " " << SEQ*SEQ*SEQ << endl;
		SEQ=SEQ+1;
	}
	
	
return 0;	
}
