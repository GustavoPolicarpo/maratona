// Author: Gustavo Policarpo
// Name: Remaining 2
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1075

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N;

int main()
{
	cin >> N;

	for(int con=1; con<=10000  ; con++)
	{
		if(con%N==2) { cout << con << endl;
		}	
	}
return 0;	
}
