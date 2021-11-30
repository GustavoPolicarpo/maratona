// Author: Gustavo Policarpo
// Name: Distance Between Two Points
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1015

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double X1, X2, Y1, Y2, D;



int main()
{	
	cin >> X1 >> Y1 >> X2 >> Y2;
	
	D=sqrt(pow((X2-X1),2)+pow((Y2-Y1),2));
	
	cout << fixed << setprecision(4);
	cout << D << endl;
	
	return(0);
}
