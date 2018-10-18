// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sequência de Números e Soma
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1101

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int M, N, T, S;

int main()
{
	while(T==0)
	{
		S=0;
		cin >> M >> N;
		if (M<=0 || N<=0)
		{
			T=1;
		}
		
		else if (M>=N)
		{
			for (N; N<=M; N++)
			{
				cout << N << " ";
				S=S+N;
			}
			cout << "Sum=" << S << endl;
		}
		
		else if (M<N)
		{
			
			for (M; M<=N; M++)
			{
				cout << M << " ";
				S=S+M;
			}
			cout << "Sum=" << S << endl;
		}
		
		
	}
	
return 0;	
}
