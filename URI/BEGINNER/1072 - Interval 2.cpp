// Author: Gustavo Policarpo
// Name: Interval 2
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1072

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N, X;
int IN, OUT;



int main()
{
	cin >> N;
	for(N; N>0; N--)
	{
		cin >> X;
		if(X>=10 && X<=20) { IN++;
		}
		else { OUT++;
		}
	}
	cout << IN << " in" << endl << OUT << " out" << endl;	

return 0;	
}
