// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A Resposta de Theon
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1858

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N; 
int T[101];
int M=20, NM;
int i;

int main()
{
	cin >> N ;
	for(i=1; i<=N; i++)
	{
		cin >> T[i];
		if(M>T[i]) 
		{
			M=T[i];
			NM=i;			
		}
	}
	cout << NM << endl;

	
	return 0;
}
