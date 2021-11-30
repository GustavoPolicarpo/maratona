// Author: Gustavo Policarpo
// Name: Dividing X by Y
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1116

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double X, Y, R;
int N;

int main()
{
	cin >> N;
	
	for (N; N>0; N--)
	{
		cin >> X >> Y;
		
		cout << fixed << setprecision(1);
		
		if (Y==0)
		{
			cout << "divisao impossivel" << endl;
		}
		else 
		{
			cout << X/Y << endl;
		}
	}
	
return 0;	
}
