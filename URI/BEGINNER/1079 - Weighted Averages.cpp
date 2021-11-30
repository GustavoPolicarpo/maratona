// Author: Gustavo Policarpo
// Name: Weighted Averages
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1079

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N;
double A, B, C;

int main()
{
	cin >> N;
	
	cout << fixed << setprecision(1);
	
	for(int con=1; con<=N  ; con++)
	{
		cin >> A >> B >> C;
		cout << (A*2+B*3+C*5)/10 << endl;
		
	}
return 0;	
}
