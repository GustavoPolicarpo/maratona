// Author: Gustavo Policarpo
// Name: Age in Days
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1020

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int I, A, M, D;

int main()
{	
	cin >> I;
	
	
	A=I/365;
	M=(I-(A*365))/30;
	D=(I-(A*365+M*30));
		
	cout << A << " ano(s)" << endl;
	cout << M << " mes(es)" << endl;
	cout << D << " dia(s)" << endl;
	
	return(0);
}
