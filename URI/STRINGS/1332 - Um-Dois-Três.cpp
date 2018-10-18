// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Um-Dois-Três
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1332

#include<bits/stdc++.h>

using namespace std;

int N;
string word;

int main()
{
	cin >> N;
	while(N--)
	{
		cin >> word;
		if(word.size()>3) cout << 3 << endl;
		else if(word[0]=='o' && word[1]=='n' || word[0]=='o' && word[2]=='e' || word[1]=='n' && word[2]=='e' || word[0]=='o' && word[1]=='n' && word[2]=='e')
		{
			cout << 1 << endl;
		}
		else cout << 2 << endl;	
	}
	
}

