// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Trilhos Novamente... Traç...
// Nível: 4
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1063

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int N;
	while(cin >> N)
	{
		if(N==0) break;
		
		int t[N], o[N];	
		stack <int> trem;
			
		for(int i=0; i<N; i++)
		{
			char temp; 
			cin >> temp;
			o[i]=temp; 
		}
		for(int i=0; i<N; i++)
		{
			char temp;
			cin >> temp;
			t[i]=temp;
		}

		
		bool did=false;
		bool take=true;
		int j=0;	
		
		for(int i=0; i<N; i=i)
		{ 
			if(take==true)
			{
				trem.push(o[i]);
				cout << 'I';
			}
			if(!trem.empty()&&trem.top()==t[j])
			{
				trem.pop();
				take=false;
				j++;
				cout << 'R';
			}
			else
			{
				take=true;
				i++;	
			}
					
		}
		if(!trem.empty()) cout << " Impossible";
		cout << endl;
		
	}	
	
	
return 0;
}
