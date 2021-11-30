// Author: Gustavo Policarpo
// Name: Time Conversion
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1019

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int H, M, S, N;

int main()
{	
	cin >> N;
	
	H = N/3600;
	M = (N-(H*3600))/60;
	S = N-(H*3600+M*60);
		
	cout << H << ":" << M << ":" << S << endl;

	return(0);
}
