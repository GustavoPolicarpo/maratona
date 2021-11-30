// Author: Gustavo Policarpo
// Name: Sphere
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1011

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double V;
double pi=3.14159;
int R;

int main()
{	
	cin >> R;
	
	V = (4/3.0)*pi*(pow(R,3));
	
	cout << fixed << setprecision(3);
	cout << "VOLUME = "<< V << endl;
	
	return(0);
}
