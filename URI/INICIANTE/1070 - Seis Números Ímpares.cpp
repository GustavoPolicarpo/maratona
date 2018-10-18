// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Seis Números Ímpares
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1070

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N;


int main()
{
	// cout << fixed << setprecision(1);
	cin >> N;
	if (N%2==0) {N=N+1;
	}
	for (int I=0; I<6; I++) 
	{
	cout << N << endl; N=N+2;
	}

return 0;	
}
