// Author: Gustavo Policarpo
// Name: Brick Game
// Level: 2
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1436

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int T;
int N;
int J[12];

int main()
{
	cin >> T;
	for(int i1=1; i1<=T; i1++)
	{
		cin >> N;
		for(int i2=0; i2<N; i2++)
		{
			cin >> J[i2];
		}
		cout << "Case " << i1 << ": " << J[N/2] << endl;	
	}
return (0);
}
