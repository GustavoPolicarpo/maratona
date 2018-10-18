// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Reservatório de Mel
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2029

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

double D, V, H, A;

int main()
{
	while(cin >> V >> D)
	{
		cout << fixed << setprecision(2);
		
		D=D/2;
		A=pow(D,2)*3.14;
		H=V/A;
		cout << "ALTURA = " << H << endl;
		cout << "AREA = " << A << endl;
	}
	
return(0); 
}

