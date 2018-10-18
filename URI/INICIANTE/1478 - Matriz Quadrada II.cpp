// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Matriz Quadrada II
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1478

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	while(1)
	{
		int n;
		cin >> n;
		int bk=n;
		if(n==0) break;
		int M[n][n];
		int put=1;
		int beg=0;
		
		if(n==1) cout << "  1" << endl;
		else
		{
			
				bool up=false;
				for(int i=0; i<n; i++)
				{
					for(int j=0; j<n; j++)
					{
						M[i][j]=put;
						
						if(up==false) put--;
						if(put<1)
						{
							up=true; put++;
						}
						if(up==true) put++;
								
					}
					up=false;
					put=i+2;	
				}
				
				put++;
			
			for(int i=0; i<bk; i++)
			{
				for(int j=0; j<bk; j++)
				{
					if(j==0 && M[i][j]/10>=1 && M[i][j]/10<10)  cout << " ";
					else if(j==0 && M[i][j]/10>=10);
					else if(j==0) cout << "  ";
					else if(M[i][j]/10<1) cout << "   ";
					else if(M[i][j]/10>=10) cout << " ";
					else cout << "  ";
					cout << M[i][j];
					if(j==bk-1) cout << endl;
					
				}
			}
		}
		cout << endl;	
	}
return(0);
}	
