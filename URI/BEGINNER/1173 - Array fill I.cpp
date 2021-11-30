// Author: Gustavo Policarpo
// Name: Array fill I
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1173

# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

int N[10];

int main()
{
    cin >> N[0];
 	cout << "N[" << 0 << "]" << " = " << N[0] << endl;
    for( int i = 1 ; i < 10 ; i++ )
	{
        N[i]=2*N[i-1];
        cout << "N[" << i << "]" << " = " << N[i] << endl;
    }

 
return 0;
}
