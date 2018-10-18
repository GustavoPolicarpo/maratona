// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Getline One
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1216

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

string N;
long double D, cont, S, M;

int main()
{
	while(getline(cin,N))
	{
		cin >> D;
		cin.ignore();
		cont++;		
		S=S+D; 	
	}
	
	M=S/cont;
	cout << fixed << setprecision(1) << M << endl;

return(0);	
}	 
		
	



