// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fibonacci em Vetor
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1176

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int T, NN;
long long int N[61];
long long int N1=0, N2=1, N3;


int main()
{
	cin >> T;
	
	N[0]=N1;
	N[1]=N2;
		
	for (int f=2; f<=60; f++)
	{
		N3=N1+N2;
		N[f]=N3;
		N1=N2; N2=N3;	
	}	
	
	for(int cont=1; cont<=T; cont++)
	{
		cin >> NN;
		cout << "Fib(" << NN << ") = " << N[NN] << endl;
	}
return 0;	
}
