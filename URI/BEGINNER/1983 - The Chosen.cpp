// Author: Gustavo Policarpo
// Name: The Chosen
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1983

#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<cctype>
#include <cmath>


//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int N;
long long int m, aum;
double n, aun;

int main()
{
	cin >> N;
	while(N--)
	{
		cin >> m >> n;
		if(aun<n)
		{
			aum=m;
			aun=n;
		} 
	}
	if(aun>=8) cout << aum << endl;
	else cout << "Minimum note not reached" << endl;
	
	
	
return(0); 
}

