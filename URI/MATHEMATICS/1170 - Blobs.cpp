// Author: Gustavo Policarpo
// Name: Blobs
// Level: 3
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1170

# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

int  N, D;
double C;

int main()
{
	cin >> N;
	for(N; N>=1; N--)
	{
		cin >> C;
		D=0;
		for(C; C>1; C=C/2) D++;
		
		cout << D << " dias" << endl;
		
	}
	
 
return 0;
}


