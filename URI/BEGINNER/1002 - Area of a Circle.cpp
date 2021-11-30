// Author: Gustavo Policarpo
// Name: Area of a Circle
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1002

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double raio, area;
double pi=3.14159;

int main()
{	
	cin >> raio;
	
	area=pow(raio,2) * pi;
	
	cout << fixed << setprecision(4);
	cout<<"A="<<area<<endl;
	
	return(0);
}
