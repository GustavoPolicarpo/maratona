// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fechem as Portas!
// Nível: 6
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1371

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	long int N;
	while(cin >> N)
	{
		if(N==0) break;
		int b=sqrt(N);
		int s=1;
		for(int i=0; i<b; i++)
		{
			long long int S=pow(s,2);
			cout << S;
			if(i+1==b) cout << endl;
			else
			{
				cout << " ";
				s++;	
			} 
		}
		
	}
	
	

	
		
return(0); 
}

