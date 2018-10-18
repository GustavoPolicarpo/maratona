// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Bravo Guerreiro Hashmat
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1198

# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

long long int N1, N2;

int main()
{
	while(cin >> N1 , cin >> N2) 
	{
		cout << abs(N2-N1) << endl;
	}
return 0;
}


