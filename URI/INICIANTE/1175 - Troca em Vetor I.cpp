// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Troca em Vetor I
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1175

# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

int N[20];
int A[20];
int i=0;
int i2=19;

int main()
{
	for( i ; i < 20 ; i++ )
	{
		cin >> N[i];
		A[i2]=N[i];	
		i2--;
	}
	for( i2 = 0 ; i2 < 20 ; i2++ )
	{
		cout << "N[" << i2 << "]" << " = " << A[i2] << endl;			
	}
 
return 0;
}



