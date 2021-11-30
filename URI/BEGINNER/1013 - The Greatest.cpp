// Author: Gustavo Policarpo
// Name: The Greatest
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1013

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int a, b, c;
int M1, M2;

int main()
{	
	cin >> a >> b >> c;
	
	M1=(a+b+abs(a-b))/2;
	M2=(c+M1+abs(c-M1))/2;
	cout << M2 << " eh o maior" << endl;
	
	return(0);
}
