// Author: Gustavo Policarpo
// Name: Average 2
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1006

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double A, B, C, MEDIA;

int main()
{	
	cin >> A >> B >> C;
	
	MEDIA=((A*2)+(B*3)+(C*5))/10;
	
	cout << fixed << setprecision(1);
	cout<<"MEDIA = "<< MEDIA << endl;
	
	return(0);
}
