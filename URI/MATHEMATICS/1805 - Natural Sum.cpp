// Author: Gustavo Policarpo
// Name: Natural Sum
// Level: 6
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1805

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


long long int  A, B, S;

int main()
{	

	cin >> A >> B;
	S=(A+B)*(B-A+1)/2;
	cout << S << endl;
	
	
	return(0);
}


