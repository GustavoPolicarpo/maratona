// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Instruções do Robô
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1574

#include<bits/stdc++.h>

using namespace std;


using namespace std;


int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		int T;
		
		cin >> T;
		cin.ignore();
		
		int CO[T];
		for(int i=0; i<T; i++)
		{
			string GO;
			getline(cin, GO);
		
			if(GO=="LEFT") CO[i]=-1;
			else if(GO=="RIGHT") CO[i]=1;
			
			else
			{
				if(GO.size()==10)  CO[i]=CO[(GO[8]-48)*10+(GO[9]-49)];
				else CO[i]=CO[GO[8]-49];
			}
		}
		int P=0;
		for(int i=0; i<T; i++) 
		{
			P=P+CO[i];
			
		}
		
		cout << P << endl;
		
		
	}
return(0);	
}
