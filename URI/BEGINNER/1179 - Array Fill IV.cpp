// Author: Gustavo Policarpo
// Name: Array Fill IV
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1179

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int IN;
int A[5], B[5];
int a=0, b=0;



int main()
{
	for(int cont1=1; cont1<=15; cont1++)
	{
		cin >> IN;
		
		if(IN%2==0)
		{
			A[a]=IN;
			a++;
			if(a==5)
			{
				a=0;
				for(int cont2=0; cont2<5; cont2++) cout << "par[" << cont2 << "] = " << A[cont2] << endl;
			}
		}
		else
		{
			B[b]=IN;
			b++;
			if(b==5)
			{
				b=0;
				for(int cont2=0; cont2<5; cont2++) cout << "impar[" << cont2 << "] = " << B[cont2] << endl;
			}
		}	
	}
	for(int cont2=0; cont2<b; cont2++) cout << "impar[" << cont2 << "] = " << B[cont2] << endl;
	for(int cont2=0; cont2<a; cont2++) cout << "par[" << cont2 << "] = " << A[cont2] << endl;
	
		

return 0;	
}
