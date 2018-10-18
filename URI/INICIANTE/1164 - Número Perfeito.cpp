// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Número Perfeito
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1164

# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

int N, X, S;

int main()
{
	cin >> N;
	for(int cont=1; cont<=N; cont++)
	{
		S=0;
		cin >> X;
		for(int cont2=1; cont2<X; cont2++)
		{
			if(X%cont2==0) S=S+cont2;
		}
		if (S==X) cout << X << " eh perfeito" << endl;
		else cout << X << " nao eh perfeito" << endl;
	}
	
	return 0;
}
