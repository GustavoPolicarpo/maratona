// Author: Gustavo Policarpo
// Name: Divisibility by 3
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1987

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int n, t;
	int aux;
	int soma;
	while(cin >> n)
	{
		cin >> t;
		int soma=0;
		for(int i=0; i<n; i++) 
		{
			aux=t%10;
			soma+=aux;
			t=t/10;			
		}
		if(soma%3==0) cout << soma << " sim" << endl;
		else cout << soma <<  " nao" << endl;
	}
		
return(0); 
}

