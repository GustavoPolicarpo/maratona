// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Frequência de Números
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1171

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int N;
int C[2000][2000];
int X;
int M;



int main()
{
	cin >> N;
	while(N--)
	{
		cin >> X;
		C[1][X]++;
		C[2][X]=X;
		if(X>M) M=X;
	}
	for(int i=1; i<=M; i++)
	{
		if(C[1][i]!=0)	cout << C[2][i] << " aparece " << C[1][i] << " vez(es)" << endl;
		
	}
	
	
return(0);	
}
	



