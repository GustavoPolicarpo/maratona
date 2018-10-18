// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Formiguinha
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1612

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	while(N--)
	{
		unsigned long int T;
		cin >> T;
		if(T%2==0) cout << T/2 << endl;
		else cout << (T+1)/2 << endl;
	}
	
	
return(0);
}

