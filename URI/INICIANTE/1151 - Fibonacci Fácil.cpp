// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fibonacci Fácil
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1151

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N;
int N1=0, N2=1, N3;


int main()
{
	cin >> N;
	
	cout << N1 << " ";
	if(N>=2) { cout << N2 << " ";
	}
	
	for (int cont=3; cont<=N; cont++)
	{
		N3=N1+N2;
		
		if(cont==N) { cout << N3 << endl;
		}
		else { cout << N3 << " ";
		}
			
		N1=N2; N2=N3;
	}
return 0;	
}
