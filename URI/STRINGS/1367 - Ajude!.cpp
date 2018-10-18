// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ajude!
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1367

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;



int main()
{
	int N;
	while(cin >> N)
	{	
		if(N==0) break;
		
		int e[26], c[26];
		for(int i=0; i<26; i++) e[i]=0;
		for(int i=0; i<26; i++) c[i]=0;
		int QC=0, TT=0;
		
		while(N--)
		{
			char Q; int T; string R;
			cin >> Q >> T >> R;
			if(R=="correct")
			{
				c[Q-65]=1;
				TT+=T;
				QC++;
			}
			else if(R=="incorrect" && c[Q-65]==0)
			{
				e[Q-65]++;	
			}
		}
		for(int i=0; i<26; i++)
		{
			if(e[i]>0&&c[i]==1) TT+=e[i]*20;
		}
		cout << QC << " " << TT << endl;
	}
				
		
	
return(0); 
}


