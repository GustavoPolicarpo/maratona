// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Divisibilidade Por 3
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1987

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int n, t;
	int aux;
	int soma;
	while(cin >> n)
	{
		cin >> t;
		int soma=0;
		for(int i=0; i<n; i++) 
		{
			aux=t%10;
			soma+=aux;
			t=t/10;			
		}
		if(soma%3==0) cout << soma << " sim" << endl;
		else cout << soma <<  " nao" << endl;
	}
		
return(0); 
}

