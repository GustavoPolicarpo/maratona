// Author: Gustavo Policarpo
// Name: S Sequence
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1155

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double S, X=1;


int main()
{
	for(X; X<=100; X++)
	{
		S=S+1/X;
	}
	cout << fixed << setprecision(2);
	cout << S << endl;
return 0;	
}
