// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Matriz Quadrada III
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1557

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		if(n==0) break;
		int bk=n;
		int i=0, j=0;
		int M[n][n];
	
	
				for(i=0; i<n; i++)
				{
					for(j=0; j<n; j++)
					{
						M[i][j]=pow(2,i)*pow(2,j);				
					}		
				}
				stringstream tam;
				tam << M[i-1][j-1];
				string T=tam.str();
				int TAM=T.size();
				
				
			
			for(int i=0; i<bk; i++)
			{
				for(int j=0; j<bk; j++)
				{
					int tw;
					stringstream tam;
					tam << M[i][j];
					string T=tam.str();
					int twa=T.size();
					
					if(j==0)cout << setw(TAM) << M[i][j];
					else cout << setw(TAM+1) << M[i][j];
					if(j==bk-1) cout << endl;	
				}
			}
		
		cout << endl;	
	}
return(0);
}	
