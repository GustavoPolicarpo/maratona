// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Estimando a Média
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1779

#include<bits/stdc++.h>
//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int T, MMC, MS, O;
long int N, P, MM;


int main () 
{
	cin >> T;
	for(int cont=1; cont<=T; cont++)
	{
		MM=0; MMC=0; MS=0;
		cin >> N;
		while(N--)
		{
			cin >> P;
			if(MM<P) 
			{
				MM=P;
				MMC=1;
				MS=0;
			}
			else if(MM==P)
			{
				MMC++;
			} 
			else
			{
				//sequencia break
				if(MS<MMC) MS=MMC;
				MMC=0;
			}
			
			
			
		}
		if(MMC>MS) O=MMC;
		else O=MS;
		cout << "Caso #" << cont << ": " << O << endl;
	}
	
	
	
}
