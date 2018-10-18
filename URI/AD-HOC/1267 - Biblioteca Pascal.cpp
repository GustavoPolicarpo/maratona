// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Biblioteca Pascal
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1267

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int N, D;
	while(cin >> N >> D)
	{
		if(N==0&&D==0) break;
		int M[D][N];
		for(int i=0; i<D; i++)
			for(int j=0; j<N; j++)
			{
				int temp; cin >> temp;
				M[i][j]=temp;
			}
		bool did=false;
		for(int i=0; i<N; i++)
		{
			int soma=0;
			for(int j=0; j<D; j++)
			{
				if(M[j][i]==0) break;
				soma++;
			}
			if(soma==D)
			{
				did=true;
				break;
			}
		}
		if(did==false)	cout << "no";
		else cout << "yes";
		cout << endl;		
	}
}
