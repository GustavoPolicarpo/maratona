// Author: Gustavo Policarpo
// Name: Type of Fuel
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1134

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N, A, G, D; 
bool T=true;


int main()
{
	while(T==true)
	{
		cin >> N;
		if (N==1) { A++;
		}
		else if (N==2) { G++;
		}
		else if (N==3) { D++;
		}
		else if (N==4) { T=false; 
		}
	}
	
	cout << "MUITO OBRIGADO" << endl;
	cout 
	<< "Alcool: " << A << endl
	<< "Gasolina: " << G << endl
	<< "Diesel: " << D << endl;
	
	
return 0;	
}
