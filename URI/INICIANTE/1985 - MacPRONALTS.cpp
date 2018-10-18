// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: MacPRONALTS
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1985

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int p, q, c;
double S;

int main()
{
	cin >> p;
	while(p--)
	{
		cin >> c >> q;
		switch(c)
		{
			case 1001: S=S+1.5*q; break;
			case 1002: S=S+2.5*q; break;
			case 1003: S=S+3.5*q; break;
			case 1004: S=S+4.5*q; break;
			case 1005: S=S+5.5*q; break;
		}
	}
	cout << fixed << setprecision(2) << S << endl;
	
	
return(0); 
}

