// Author: Gustavo Policarpo
// Name: Sequence IJ 3
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1097

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int I=1, J=7;

int main()
{
	
	for(int con=4; con>=0; con=con-1)
	{
		cout << "I=" << I << " " << "J=" << J << endl;
		I=I; J=J-1;
		cout << "I=" << I << " " << "J=" << J << endl;
		I=I; J=J-1;
		cout << "I=" << I << " " << "J=" << J << endl;
		I=I+2; J=J+4;
	}
return 0;	
}
