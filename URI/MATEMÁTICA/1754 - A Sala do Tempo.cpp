// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A Sala do Tempo
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1754

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		unsigned long long int  X, Y;
		cin >> X >> Y;
		unsigned long long int k;
		if(Y>=X)
			 k=2;
		else	
		{
			k=X/Y;
			if(X%Y>0) 
				k++;
		}	
		cout << k << endl;
	}
		

return 0;
}
