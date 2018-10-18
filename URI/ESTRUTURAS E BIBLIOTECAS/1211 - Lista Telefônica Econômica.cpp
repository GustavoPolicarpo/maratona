// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Lista Telefônica Econômica
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1211

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int N;
	while(cin >> N)
	{	
	int bk=N;
	long long int NO=0;
	vector <string> A;
		while(N--)
		{
			string S;
			
			cin >> S;
			A.push_back(S);	
		}	
		sort(A.begin(), A.end());
	//	reverse(A.begin(), A.end());
		for(int i=0; i<bk-1; i++)
		{
			string t1, t2;
			t1=A[i]; t2=A[i+1];
			for(int j=0; j<t1.size(); j++)
			{
				if(t1[j]==t2[j]) NO++;
				else break;
			}
		}
		cout << NO << endl;
	}
	
	
		
return(0); 
}

