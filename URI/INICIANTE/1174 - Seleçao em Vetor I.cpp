// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Seleçao em Vetor I
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1174

# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

double A[100];

int main()
{
	cout << fixed << setprecision(1);
	for( int i = 0 ; i < 100 ; i++ )
	{
		cin >> A[i];	
	}
	for( int i = 0 ; i < 100 ; i++ )
	{
		if(A[i]<=10)
		{
			cout << "A[" << i << "]" << " = " << A[i] << endl;		
		}	
	}
 
return 0;
}



