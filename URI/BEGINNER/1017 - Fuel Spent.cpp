// Author: Gustavo Policarpo
// Name: Fuel Spent
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1017

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int T, V;
double X, L;

int main()
{	
	cin >> T >> V;
	
	X=T*V;
	L=X/12;

	cout << fixed << setprecision(3);
	cout << L << endl;
	
	return(0);
}
