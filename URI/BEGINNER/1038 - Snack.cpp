// Author: Gustavo Policarpo
// Name: Snack
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1038

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int C, Q;
double T;

int main()
{	

	cin >> C >> Q;
		
	if(C==1)
	{
		T=4*Q;	
	}
	else if(C==2)
	{
		T=4.5*Q;
	}
	else if(C==3)
	{
		T=5*Q;
	}
	else if(C==4)
	{
		T=2*Q;
	}
	else if(C==5)
	{
		T=1.5*Q;
	}
	
	cout << fixed << setprecision(2);
	cout << "Total: R$ " << T << endl;
			
	return(0);
}
