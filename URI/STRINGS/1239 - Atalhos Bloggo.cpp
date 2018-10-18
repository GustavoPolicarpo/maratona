// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Atalhos Bloggo
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1239

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	string T; 
	while(getline(cin, T))
	{
		int c1=0, c2=0;
		for(int i=0; i<T.size(); i++)
		{
			if(T[i]=='_')
			{
				if(c1==0)
				{
					T[i]='@'; c1++;
				}
				else if(c1==1)
				{
					T[i]='#'; c1--;
				}
			}
			else if(T[i]=='*') 
			{
				if(c2==0)
				{
					T[i]='$'; c2++;
				}
				else if(c2==1)
				{
					T[i]='%'; c2--;
				}
			}
		}
		for(int i=0; i<T.size(); i++)
		{
			if(T[i]=='@') cout << "<i>";
			else if(T[i]=='#') cout << "</i>";
			else if(T[i]=='$') cout << "<b>";
			else if(T[i]=='%') cout << "</b>";
			else cout << T[i];
		}
		cout << endl;
		
	}
		
	
		
	
	
	

	
		
return(0); 
}

