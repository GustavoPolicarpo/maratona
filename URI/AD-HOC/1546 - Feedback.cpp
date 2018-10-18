// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Feedback
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1546

#include<bits/stdc++.h>


using namespace std;
int N, K, F;
int main () 
{
	cin >> N;
	while(N--)
	{
		cin >> K;
		while(K--)
		{
			cin >> F;
			switch(F)
			{
				case 1: cout << "Rolien" << endl; break;
				case 2: cout << "Naej" << endl; break;
				case 3: cout << "Elehcim" << endl; break;
				case 4: cout << "Odranoel" << endl; break;
			} 
		}
					
	}
	
	
return(0);	
	
}
