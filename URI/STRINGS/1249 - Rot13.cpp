// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Rot13
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1249

#include<bits/stdc++.h>

using namespace std;

int main()
{
	string t; int go;
	
	while(getline(cin, t))
	{
		for(int i=0; i<t.size(); i++)
		{
			int aux;
			aux=0;
			if(isalpha(t[i]))
			{
				if(isupper(t[i]))
				{
					if(t[i]+13>90)
					{
						aux=91-t[i];
						t[i] = 65;	
					}
					else aux=0;
					t[i] += 13-aux;
				}
				else
				{
					if(t[i]+13>122)
					{
						aux=123-t[i];
						t[i] = 97;	
					}
					else aux=0;
					t[i] += 13-aux;
				}
			}
	
		}
		
		cout << t << endl;
	}
	
	
return(0);
}

