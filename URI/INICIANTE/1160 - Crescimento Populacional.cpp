// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Crescimento Populacional
// Nível: 2
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1160

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int T;
int PA, PB;
int anos;
double GA, GB;


int main()
{	
	cin >> T;
	for(int cont=1; cont<=T; cont++)
	{
		anos=0;
		cin >> PA >> PB >> GA >> GB;
		while(PA<=PB && anos<=100)
		{
			PA=PA*(1+GA/100); PB=PB*(1+GB/100); anos++;	
			
		}
		if(anos>100) { cout << "Mais de 1 seculo." << endl;
			}
		else		 { cout << anos << " anos." << endl;
			}
	}	
		
return 0;	
}
