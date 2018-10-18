// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Par ou Ímpar
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2286

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b,cont=1;
	char j1[100],j2[100];
	while(cin>>n and n!=0)
	{
		cin>>j1;
		cin>>j2;
		cout<<"Teste "<<cont<<endl;
		cont++;
		while(n--)
		{
			cin>>a>>b;
			if((a+b)%2==0)
				cout<<j1<<endl;
			else
				cout<<j2<<endl;	
	
		}
		cout<<endl;
	}
	
	return 0;
}
