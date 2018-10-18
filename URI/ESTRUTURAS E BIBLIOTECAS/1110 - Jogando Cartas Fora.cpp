// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Jogando Cartas Fora
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1110

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	int N;
	while(cin >> N)
	{
		if(N==0) break;
		queue <int> c;
		for(int i=1; i<=N; i++) c.push(i);
		cout << "Discarded cards: ";
		if(N>1)cout << c.front();
		while(c.size()>2)
		{
			cout << ", ";
			c.pop();
			int temp=c.front();
			c.pop();
			c.push(temp);
			cout << c.front();			
		}
		if(N>1) c.pop();
		cout << endl
			 << "Remaining card: " << c.front() << endl;	
	}	
return(0); 
}


