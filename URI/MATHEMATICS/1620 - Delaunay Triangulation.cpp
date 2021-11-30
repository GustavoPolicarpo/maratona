// Author: Gustavo Policarpo
// Name: Delaunay Triangulation
// Level: 4
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1620

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

long  double L, l, I, i;
long double X;
 

int main()
{
	while(1)
	{
		cin >> L;
		if(L==0) break;
		i=0;
		l=3;
		I=L+L-3;
		X=(I-L)/L;
		cout <<  fixed << setprecision(6) << X << endl;	
	}
	
	
return (0);
}
