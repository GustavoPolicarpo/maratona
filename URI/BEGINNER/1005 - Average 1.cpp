// Author: Gustavo Policarpo
// Name: Average 1
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1005

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double A, B, MEDIA;

int main()
{	
	cin >> A >> B;
	
	MEDIA=((A*3.5)+(B*7.5))/11;
	
	cout << fixed << setprecision(5);
	cout<<"MEDIA = "<< MEDIA << endl;
	
	return(0);
}
