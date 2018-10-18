// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Conta
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1866

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int C, N;


int main()
{
	cin >> C;
	while(C--)
	{
		cin >> N;
		if(N%2==0) cout << 0 << endl;
		else cout << 1 << endl;
	}
		
	return 0;
}
