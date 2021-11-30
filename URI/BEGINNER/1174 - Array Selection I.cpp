// Author: Gustavo Policarpo
// Name: Array Selection I
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1174

# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

double A[100];

int main()
{
	cout << fixed << setprecision(1);
	for( int i = 0 ; i < 100 ; i++ )
	{
		cin >> A[i];	
	}
	for( int i = 0 ; i < 100 ; i++ )
	{
		if(A[i]<=10)
		{
			cout << "A[" << i << "]" << " = " << A[i] << endl;		
		}	
	}
 
return 0;
}



