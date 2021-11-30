// Author: Gustavo Policarpo
// Name: Multiplication Table
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1078

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N;

int main()
{
	cin >> N;

	for(int con=1; con<=10  ; con++)
	{
		cout << con << " x " << N << " = " << con*N << endl;
	}
return 0;	
}
