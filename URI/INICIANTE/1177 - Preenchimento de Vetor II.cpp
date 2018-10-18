// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Preenchimento de Vetor II
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1177

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int t, c=0;;
long long int N[1000];



int main()
{
	cin >> t;
		
	for (int p=0; p<1000; p++)
	{
		N[p]=c;
		c++;
		if(c>=t) c=0;
		
		cout << "N[" << p << "] = " << N[p] << endl;
	}	

return 0;	
}
