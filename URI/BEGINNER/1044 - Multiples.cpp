// Author: Gustavo Policarpo
// Name: Multiples
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1044

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int A, B;

int main()
{	
	cin >> A >> B;
	
	if(A%B==0 || B%A==0)
	{
		cout << "Sao Multiplos" << endl;
	}
	else
	{
		cout << "Nao sao Multiplos" << endl;
	}
			
	return(0);
}
