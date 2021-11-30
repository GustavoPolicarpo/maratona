// Author: Gustavo Policarpo
// Name: Lowest Number and Position
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1180

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N;
int M, P;



int main()
{
	cin >> N;
	int X[N];
	cin >> X[0];
	M=X[0]; P=0;
	for(int cont=1; cont<N; cont++)
	{
		cin >> X[cont];
		if(M>X[cont]) 
		{
			M=X[cont]; P=cont;
		}
	}
	cout << "Menor valor: " << M << endl;
	cout << "Posicao: " << P << endl;
		

return 0;	
}
