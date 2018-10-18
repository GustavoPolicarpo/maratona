// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Carrega ou não Carrega?
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1026

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

unsigned long int A, B, S;


int main()
{
	while(cin >> A >> B)
	{
		S=A^B;
		cout << S << endl;
	}
return(0);
}
