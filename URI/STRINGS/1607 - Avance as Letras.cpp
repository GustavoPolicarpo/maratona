// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Avance as Letras
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1607

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	cin.ignore();
	
	while(N--)
	{
		string A, B;
		cin >> A >> B;
		long int C;
		C=0;
		
		for(int i=0; i<A.size(); i++)
		{
			if(A[i]<B[i]) C += B[i]-A[i];
			else if(A[i]>B[i])
			{
				C += 122-A[i];
				C += B[i]- 96;
			}
		}
		cout << C << endl;
	}
	
	
return(0);
}

