// Author: Gustavo Policarpo
// Name: Feynman
// Level: 1
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1323

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int N;
long int NN;

int main()
{
	while(1)
	{
		cin >> N;
		if(N==0) break;
		for(int i=N; i>0; i--)
		{
			NN=NN+i*i;
		}
		cout << NN << endl;
		NN=0;		
	}
	
	
return (0);
}
