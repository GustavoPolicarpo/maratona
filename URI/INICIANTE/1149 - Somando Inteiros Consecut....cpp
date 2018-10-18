// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Somando Inteiros Consecut...
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1149

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int A, N, S;
bool NP=false;

int main()
{
	cin >> A;
	while(NP==false)
	{
		cin >> N;
		if (N>0)
		{
			NP=true;
		}
	}
	for(N; N>0; N--)
	{
		S=S+A;
		A++;
	}
	cout << S << endl;
			
return 0;	
}
