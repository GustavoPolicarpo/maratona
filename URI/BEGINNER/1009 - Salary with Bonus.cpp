// Author: Gustavo Policarpo
// Name: Salary with Bonus
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1009

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double F, V, T;
char NOM[20];

int main()
{	
	cin.getline(NOM,20);
	cin >> F >> V;
	
	T = F+(15*V/100);
	
	cout << fixed << setprecision(2);
	cout << "TOTAL = R$ "<< T << endl;
	
	return(0);
}
