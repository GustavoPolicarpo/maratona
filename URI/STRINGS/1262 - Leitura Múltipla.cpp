// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Leitura Múltipla
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1262

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	string T; int N;
	while(cin >> T)
	{
		cin >> N;
		int NC=0, NR=0;
		bool r=false;
		for(int i=0; i<T.size(); i++)
		{
			if(T[i]=='W')
			{
				if(NR>0) NC++;
				NC++;
				NR=0;	
			} 
			else if(T[i]=='R')
			{
				NR++;
				if(NR==N)
				{
					NC++;
					NR=0;
				}
			}
		}
		if(NR>0) NC++;
		cout << NC << endl;
	}
	
	
	
return(0); 
}


