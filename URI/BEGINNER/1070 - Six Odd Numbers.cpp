// Author: Gustavo Policarpo
// Name: Six Odd Numbers
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1070

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N;


int main()
{
	// cout << fixed << setprecision(1);
	cin >> N;
	if (N%2==0) {N=N+1;
	}
	for (int I=0; I<6; I++) 
	{
	cout << N << endl; N=N+2;
	}

return 0;	
}
