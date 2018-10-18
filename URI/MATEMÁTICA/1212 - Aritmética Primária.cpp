// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Aritmética Primária
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1212

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		if(n==0 && m==0) break;
		int carry=0;
		int a1=0, a2=0, go=0;
		while(n!=0 || m!=0)
		{
			a1=n%10; a2=m%10;
			if(a1+a2+go>9)
			{
				carry++;
				go=1;
			}
			else go=0;
			
			n/=10; m/=10;
		}
		if(carry==0) cout << "No carry operation." << endl;
		else if(carry==1) cout << carry << " carry operation." << endl;
		else cout << carry << " carry operations." << endl;
		
		
	}
		
return(0); 
}

