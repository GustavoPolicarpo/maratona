// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sequência S
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1155

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double S, X=1;


int main()
{
	for(X; X<=100; X++)
	{
		S=S+1/X;
	}
	cout << fixed << setprecision(2);
	cout << S << endl;
return 0;	
}
