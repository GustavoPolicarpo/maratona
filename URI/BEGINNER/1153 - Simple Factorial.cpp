// Author: Gustavo Policarpo
// Name: Simple Factorial
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1153

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N, S;

int main()
{
	cin >> N;
	S=N;
	for(N; N>1; N--)
	{		
		S=S*(N-1);		
	}
	cout << S << endl;
return 0;	
}
