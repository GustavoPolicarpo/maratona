// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Leitura Ótica
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1129

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	int N;
	while(cin >> N)
	{
		if(N==0) break;
		while(N--)
		{
			int R[5];
			for(int i=0; i<5; i++) cin >> R[i];
			int r=10, nr=0;
			for(int i=0; i<5; i++)
			{
				if(R[i]<=127)
				{
					r=i;
					nr++;
				}
			}
			if(nr==1)
			{
				switch(r)
				{
					case 0: cout << 'A'; break;
					case 1: cout << 'B'; break;
					case 2: cout << 'C'; break;
					case 3: cout << 'D'; break;
					case 4: cout << 'E'; break;
				}
			}
			else cout << '*';
			cout << endl;
				
			
		}
	}
return(0); 
}


