// Author: Gustavo Policarpo
// Name: Salary
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1008

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double P, SALARY;

int NUM, HRS;

int main()
{	
	cin >> NUM >> HRS >> P;
	
	SALARY = HRS*P;
	
	cout << "NUMBER = " << NUM << endl;	
	cout << fixed << setprecision(2);
	cout << "SALARY = U$ "<< SALARY << endl;
	
	return(0);
}
