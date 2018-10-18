// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Roberto e a Sala Desenfreada
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1953

#include<bits/stdc++.h>

using namespace std;

int main()
{
	long int N;
	while(cin >> N)
	{
		cin.ignore();
		string MAT, SIG;
		long int EPR=0, EHD=0, INT=0;
		while(N--)
		{
			cin >> MAT >> SIG;
			if(SIG=="EPR") EPR++;
			else if(SIG=="EHD") EHD++;
			else INT++;	
		}
		cout << "EPR: " << EPR << endl;
		cout << "EHD: " << EHD << endl;
		cout << "INTRUSOS: " << INT << endl;
	}
	
	
return(0);
}

