// Author: Gustavo Policarpo
// Name: Divisors I
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1157

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N;


int main()
{	
	cin >> N;
	
	for(int cont=1; cont<=N; cont++)
	{
		if(N%cont==0)
		{
			cout << cont << endl;
		}
	}
	
return 0;	
}
