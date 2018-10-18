// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Tabuada
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1078

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N;

int main()
{
	cin >> N;

	for(int con=1; con<=10  ; con++)
	{
		cout << con << " x " << N << " = " << con*N << endl;
	}
return 0;	
}
