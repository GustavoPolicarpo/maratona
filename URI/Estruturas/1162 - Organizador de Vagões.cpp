// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Organizador de Vagões
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1162

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;







int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		int L, bk;
		cin >> L;
		bk=L;
		queue <int> o;
		int a[L+1];
		for(int i=1; i<=L; i++)
		{
			int temp;
			cin >> a[i];
				
		}
		int swap=0;
		int did=0;
		while(did!=L)
		{
			did=1;
			for(int i=1; i<L; i++)
			{
				/*for(int j=1; j<=L; j++) cout << a[j] << " ";
				cout << endl; */
				if(a[i]>a[i+1])
				{
					int temp=a[i];
					a[i]=a[i+1];
					a[i+1]=temp;
					swap++;	
				}	
				else did++;			
			}
		}
		cout << "Optimal train swapping takes " <<
		swap << " swaps." << endl;
	}

return 0;
}
