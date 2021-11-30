// Author: Gustavo Policarpo
// Name: Ones
// Level: 5
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1213

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED




using namespace std;



int main()
{
	int N;
	while(cin >> N)
	{
		int cont=1;
		long int num=1;
		while(1)
		{
			num=(num*10+1)%N;
			cont++;
			if(num%N==0)
			{
				cout << cont << endl;
				break;
			}
		}
	}
	
}


