// Author: Gustavo Policarpo
// Name: Interval
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1037

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double IN;

int main()
{	

	cin >> IN;
		
	if ( IN >= 0 && IN <= 25 )
	{
		cout << "Intervalo [0,25]" << endl;
	}
	else if( IN > 25 && IN <= 50 )
	{
		cout << "Intervalo (25,50]" << endl;
	}
	else if( IN > 50 && IN <= 75 )
	{
		cout << "Intervalo (50,75]" << endl;
	}
	else if( IN > 75 && IN <= 100 )
	{
		cout << "Intervalo (75,100]" << endl;
	}
	
	else
	{
		cout << "Fora de intervalo" << endl;
	}
	
	return(0);
}
