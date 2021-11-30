// Author: Gustavo Policarpo
// Name: Highest and Position
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1080

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N, M, C;

int main()
{
	
	for(int con=1; con<=100; con++)
	{
		
		cin >> N;
		if(N>M) { M=N; C=con;
		}
	}
	cout << M << endl << C << endl;
		
return 0;	
}
