// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Soma Natural
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1805

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


long long int  A, B, S;

int main()
{	

	cin >> A >> B;
	S=(A+B)*(B-A+1)/2;
	cout << S << endl;
	
	
	return(0);
}


