// Author: Gustavo Policarpo
// Name: S Sequence II
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1156

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double S, X=1, Y=1;


int main()
{
	for(Y; Y<=100; Y=Y+2, X=X*2)
	{
		S=S+Y/X;
	}
	cout << fixed << setprecision(2);
	cout << S << endl;
return 0;	
}
