// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Contando Carneirinhos
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1609

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int N;
	cin >> N;
	set <long int> carneiro;
	while(N--)
	{
		carneiro.clear();
		int n;
		cin >> n;
		while(n--)
		{
			int temp; cin >> temp;
			carneiro.insert(temp);
		}
		cout << carneiro.size() << endl;	
	}		
}
