// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Preenchimento de Vetor III
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1178

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

 double t;
 double N[100];



int main()
{
	cin >> t;
		
	for (int p=0; p<100; p++)
	{
		N[p]=t;
		t=t/2.0000;
		
		cout << fixed << setprecision(4) << "N[" << p << "] = " << N[p] << endl;
	}	

return 0;	
}
