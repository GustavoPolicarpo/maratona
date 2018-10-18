// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Quadrado de Pares
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1073

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N, Q;

int main()
{
	cin >> N;
	if(N%2!=0) { N--;
	}
	for(int con=2; con<=N; con=con+2)
	{
		Q=pow(con,2);
		cout << con << "^2 = " << Q << endl;
	}
return 0;	
}
