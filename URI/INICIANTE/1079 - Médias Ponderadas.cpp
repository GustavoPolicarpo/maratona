// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Médias Ponderadas
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1079

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N;
double A, B, C;

int main()
{
	cin >> N;
	
	cout << fixed << setprecision(1);
	
	for(int con=1; con<=N  ; con++)
	{
		cin >> A >> B >> C;
		cout << (A*2+B*3+C*5)/10 << endl;
		
	}
return 0;	
}
