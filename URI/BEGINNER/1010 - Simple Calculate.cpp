// Author: Gustavo Policarpo
// Name: Simple Calculate
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1010

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double CP1, NP1, VP1, CP2, NP2, VP2, T;

int main()
{	
	cin >> CP1 >> NP1 >> VP1 >> CP2 >> NP2 >> VP2;
	
	T = NP1*VP1 + NP2*VP2;
	
	cout << fixed << setprecision(2);
	cout << "VALOR A PAGAR: R$ "<< T << endl;
	
	return(0);
}
