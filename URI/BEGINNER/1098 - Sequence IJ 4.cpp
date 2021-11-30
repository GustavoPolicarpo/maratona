// Author: Gustavo Policarpo
// Name: Sequence IJ 4
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1098

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double I=0, J=1;

int main()
{
	
	for(int con=10; con>=0; con=con-1)
	{
		cout << "I=" << I << " " << "J=" << J << endl;
		I=I; J=J+1;
		cout << "I=" << I << " " << "J=" << J << endl;
		I=I; J=J+1;
		cout << "I=" << I << " " << "J=" << J << endl;
		I=I+0.2; J=J-2+0.2;
	}
return 0;	
}
