// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Mensagem Oculta
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1272

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{

	int N;
	cin >> N;
	cin.ignore();
	while(N--)
	{
		string T;
		getline(cin, T);
		bool t=true;
		for(int i=0; i<T.size(); i++)
		{
			if(isalpha(T[i])&&t==true)
			{
				cout << T[i];
				t=false;
			}
			else if(isspace(T[i])) t=true;
		}
		cout << endl;
			
	}
		
return (0);
}
