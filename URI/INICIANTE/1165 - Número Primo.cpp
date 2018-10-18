// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Número Primo
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1165

# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

int N, X, S;
int cont2;

int main()
{
	cin >> N;
	for(int cont=1; cont<=N; cont++)
	{
		S=0;
		cont2=1;
		cin >> X;
		while(cont2<=X && S<=3)
		{
			if(X%cont2==0) S++;
			cont2++;
		}
		if (S>2) cout << X << " nao eh primo" << endl;
		else cout << X << " eh primo" << endl;
	}
	
	return 0;
}
