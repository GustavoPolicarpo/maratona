// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Numerando Estradas
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1306

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;



int main()
{
	int R, N, i=0;
	while(cin >> R >> N)
	{
		if(R==0 && N==0) break;
		i++;
		cout << "Case " << i << ": ";
		if(N>=R) cout << 0;
		else
		{
			double temp=ceil(double(R-N)/N);
			if(temp>26) cout << "impossible";
			else cout << temp;
		}
		cout << endl;	
	}
	
	
return 0;
}
