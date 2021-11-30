// Author: Gustavo Policarpo
// Name: Squared and Cubic
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1143

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N, SEQ=1;

int main()
{
	cin >> N;
	for(int con=1; con<=N; con++)
	{
		cout << SEQ << " " <<  SEQ*SEQ << " " << SEQ*SEQ*SEQ << endl;
		SEQ=SEQ+1;
	}
	
	
return 0;	
}
