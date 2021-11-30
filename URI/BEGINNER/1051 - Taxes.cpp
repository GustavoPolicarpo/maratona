// Author: Gustavo Policarpo
// Name: Taxes
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1051

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double S, IR;

int main()
{
	cin >> S;
	
	cout << fixed << setprecision(2);
	
	if(S<=2000.00)
	{
		IR=0;
		cout << "Isento" << endl;
	}
	else if(S<=3000.00)
	{
		IR=0.08*(S-2000.00);
		cout << "R$ " << IR << endl;
	}
	else if(S<=4500.00)
	{	
		IR=0.08*1000 + 0.18*(S-3000.00);
		cout << "R$ " << IR << endl;
	}
	else if (S>4500)
	{
		IR=0.08*1000.00 + 0.18*1500.00 + 0.28*(S-4500);
		cout << "R$ " << IR << endl;
	}
	
return 0;	
	
}
