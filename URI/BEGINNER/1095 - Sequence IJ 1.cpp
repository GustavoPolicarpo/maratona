// Author: Gustavo Policarpo
// Name: Sequence IJ 1
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1095

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int I=1, J=60;

int main()
{
	
	for(int con=60; con>=0; con=con-5)
	{
		cout << "I=" << I << " " << "J=" << J << endl;
		I=I+3; J=J-5;
	}
return 0;	
}
