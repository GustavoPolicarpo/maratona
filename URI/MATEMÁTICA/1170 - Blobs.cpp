// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Blobs
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1170

# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

int  N, D;
double C;

int main()
{
	cin >> N;
	for(N; N>=1; N--)
	{
		cin >> C;
		D=0;
		for(C; C>1; C=C/2) D++;
		
		cout << D << " dias" << endl;
		
	}
	
 
return 0;
}


