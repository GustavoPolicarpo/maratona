// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Figurinhas
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1028

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N;
int F1, F2;
int FA, FB;
int M;
int R;

int main()
{
	cin >> N;
	for(int cont=1; cont<=N; cont++)
	{
		cin >> F1 >> F2;
		if(F2>F1) swap(F1,F2);
		while(1)
		{
			R=F1%F2;
			if(R==0)
			{
				M=F2; break;
			}
			else
			{
				F1=F2; F2=R;
			}
		}
		cout << M << endl;	
	}
	
	
	return 0;
}
