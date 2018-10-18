// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: De Dentro para Fora
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1235

#include<bits/stdc++.h>
//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int N, tam;
string S, O;

int main()
{
	cin >> N;
	cin.ignore();
	while(N--)
	{
		getline(cin, S);
		tam=S.size();
		tam=tam/2;
		stack <char> s;
		for(int i=tam-1; i>=0; i--) 
		{
			s.push(S[i]);
			cout << s.top();
		}
		for(int i=tam*2-1; i>=tam; i--) 
		{
			s.push(S[i]);
			cout << s.top();
		}
		cout << endl;
		
	}
}
