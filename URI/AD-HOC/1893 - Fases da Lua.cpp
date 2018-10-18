// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fases da Lua
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1893

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;



int main()
{
	int N, M;
	cin >> N >> M;
	if(M<=2) cout << "nova" << endl;
	else if(M>=97) cout << "cheia" << endl;
	else
	{
		if(N<M) cout << "crescente" << endl;
		else if(N>M) cout << "minguante" << endl;
		
	}
	
	
return(0); 
}


