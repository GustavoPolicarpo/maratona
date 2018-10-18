// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Matriz Quadrada IV
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1827

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		int bk=n;
		int M[n][n];
	
	
				for(int i=0; i<n; i++)
				{
					for(int j=0; j<n; j++)
					{
						M[i][j]=0;				
					}
						
				}
				for (int i=0, j=0; i<n; i++, j++)
				{
					M[i][j]=2;
				}
				for (int i=0, j=n-1; i<n; i++, j--)
				{
					M[i][j]=3;
				}
				for (int i=n/3; i<=(n-1)-n/3; i++)
				{
					for(int j=n/3; j<=(n-1)-n/3; j++)
					{
						M[i][j]=1;
					}	
				}
				if(n%2==1) M[n/2][n/2]=4;
				
			
			for(int i=0; i<bk; i++)
			{
				for(int j=0; j<bk; j++)
				{
					cout << M[i][j];
					if(j==bk-1) cout << endl;	
				}
			}
		
		cout << endl;	
	}
return(0);
}	
