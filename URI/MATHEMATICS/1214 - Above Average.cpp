// Author: Gustavo Policarpo
// Name: Above Average
// Level: 3
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1214

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

long int C;
double N;
int NOTA[1000]; 
long double SNOTA;
double M;
int S;
double P;

int main()
{
	cin >> C;
	for(int i1=1; i1<=C; i1++)
	{
		cin >> N;
		for(int i2=0; i2<N; i2++)
		{
			cin >> NOTA[i2];
			
			SNOTA=SNOTA+NOTA[i2];
		}
		M=SNOTA/N;
		for(int i2=0; i2<N; i2++)
		{
			if(NOTA[i2]>M) S++;
		}	
		P=S/N*100;
		cout << fixed << setprecision(3) << P << "%" << endl;
		P=0; S=0; M=0; SNOTA=0; N=0;
	}
	
return (0);
}
