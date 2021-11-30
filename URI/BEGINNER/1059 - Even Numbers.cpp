// Author: Gustavo Policarpo
// Name: Even Numbers
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1059

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	for(int N=1; N<=100; N++)
	{
		if(N%2==0)
		cout << N << endl; 
	}	
return 0;
}
