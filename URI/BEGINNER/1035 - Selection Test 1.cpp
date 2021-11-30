// Author: Gustavo Policarpo
// Name: Selection Test 1
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1035

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int A, B, C, D;

int main()
{	
	cin >> A >> B >> C >> D;
	
	if( (B>C) && (D>A) && ((C+D)>(A+B)) && (C>=0) && (D>=0)&& (A%2==0))
	{
		cout << "Valores aceitos" << endl;
	}
	else
	{
		cout << "Valores nao aceitos" << endl;
	}
	
	return(0);
}
