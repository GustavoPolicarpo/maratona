// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Domingo de Manhã
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2003

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int H, M, HT;
char nothing;

int main()
{
	while(cin >> H >> nothing >> M)
	{
	
		HT=H*60+M;
		HT=HT-420;
		if(HT>0) cout << "Atraso maximo: " << HT << endl;
		else cout << "Atraso maximo: " << 0 << endl;
	
	}
	
	
return(0); 
}

