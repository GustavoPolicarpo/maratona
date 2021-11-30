// Author: Gustavo Policarpo
// Name: Triangle
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1043

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double A, B, C;
double P, AREA; 

int main()
{	
	cin >> A >> B >> C;
	
	cout << fixed << setprecision(1);
	
	if (A+B<= C || A+C<= B || B+C<=A)
	{
		AREA = (A+B)*C/2.0;
		cout << "Area = " << AREA << endl;
	}
	else 
	{
		P = A+B+C;
		cout << "Perimetro = " << P << endl;
	}
			
	return(0);
}
