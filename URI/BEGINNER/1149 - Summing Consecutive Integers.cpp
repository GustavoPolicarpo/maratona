// Author: Gustavo Policarpo
// Name: Summing Consecutive Integers
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1149

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int A, N, S;
bool NP=false;

int main()
{
	cin >> A;
	while(NP==false)
	{
		cin >> N;
		if (N>0)
		{
			NP=true;
		}
	}
	for(N; N>0; N--)
	{
		S=S+A;
		A++;
	}
	cout << S << endl;
			
return 0;	
}
