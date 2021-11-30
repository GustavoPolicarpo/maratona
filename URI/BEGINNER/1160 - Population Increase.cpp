// Author: Gustavo Policarpo
// Name: Population Increase
// Level: 5
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1160

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
