// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fila do Recreio
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1548

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		int M;
		cin >> M;
		int bk=M;
		vector<int>NN;
		int NA[M];	
		for(int i=0; i<M; i++)
		{
			int NT;
			cin >> NT;
			NA[i]=NT;
			NN.push_back(NT);
		}
		sort(NN.begin(), NN.end());
		reverse(NN.begin(), NN.end());
		for(int i=0; i<M; i++)
		{
			//cout << NN[i] << " " << NA[i] << endl;
			if(NN[i]!=NA[i]) bk--;	
		}
		cout << bk << endl;
		
	}
		

	
		

		
	
		
	
	
	

	
		
return(0); 
}

