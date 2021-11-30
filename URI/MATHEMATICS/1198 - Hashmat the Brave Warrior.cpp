// Author: Gustavo Policarpo
// Name: Hashmat the Brave Warrior
// Level: 5
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1198

# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

long long int N1, N2;

int main()
{
	while(cin >> N1 , cin >> N2) 
	{
		cout << abs(N2-N1) << endl;
	}
return 0;
}


