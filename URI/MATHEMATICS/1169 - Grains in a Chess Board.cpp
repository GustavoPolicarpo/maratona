// Author: Gustavo Policarpo
// Name: Grains in a Chess Board
// Level: 4
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1169

# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

unsigned long long int  N, X, G, K;

int main()
{
	cin >> N;
	for(N; N>=1; N--)
	{
		cin >> X;
		if (X==64)
		{
			K=1537228672809129;
			cout << K << " kg" << endl;
		}
		else
		{
			G=1;
			K=0;
			for(X; X>=1; X--)
			{
				G=G*2;
			}
			K=G/12/1000;
		
			cout << K << " kg" << endl;		
		}
		
		
	}
	
 
return 0;
}


