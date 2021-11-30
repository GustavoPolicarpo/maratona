// Author: Gustavo Policarpo
// Name: Game Time with Minutes
// Level: 9
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1047

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int HI, HF, MI, MF;
int TI, TF, T;
int H, M;

int main()
{	
	cin >> HI >> MI >> HF >> MF;
	
	TI = HI*60+MI;
	TF = HF*60+MF;
	
	T=abs(TF-TI);
	
	if (TF>TI)
	{
		H=T/60;
		M=T%60;	
	}
	else if (TF<TI)
	{
		H=23-T/60;
		M=60-T%60;
	}
	else
	{
		H=24;
		M=0;
	}
	
	if(M==60)
	{
		M=0;
		H++;
	}
		
	cout << "O JOGO DUROU " << H << " HORA(S) E " << M << " MINUTO(S)" << endl;
		
	return(0);
	
}
