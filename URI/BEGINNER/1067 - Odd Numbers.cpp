// Author: Gustavo Policarpo
// Name: Odd Numbers
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1067

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N;


int main()
{
	// cout << fixed << setprecision(1);
	cin >> N;
	for (int I=0; I<=N; I++) 
	{
		if (I%2!=0) { cout << I << endl;
		}
	}

return 0;	
}
