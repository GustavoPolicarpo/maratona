// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Floco de Neve de Koch
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1760

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	int l;
	while(cin >> l)
	{
		double A1, A2;
		A1=l*l*sqrt(3)/4;
		A2=8*A1/5;
		cout << fixed<<setprecision(2) << A2 << endl;	
	}
	
return(0);
}

