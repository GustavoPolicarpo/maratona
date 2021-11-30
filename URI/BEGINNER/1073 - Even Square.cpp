// Author: Gustavo Policarpo
// Name: Even Square
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1073

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N, Q;

int main()
{
	cin >> N;
	if(N%2!=0) { N--;
	}
	for(int con=2; con<=N; con=con+2)
	{
		Q=pow(con,2);
		cout << con << "^2 = " << Q << endl;
	}
return 0;	
}
