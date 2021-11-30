// Author: Gustavo Policarpo
// Name: Game Time
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1046

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int I, F;
int T;

int main()
{	
	cin >> I >> F;
	
	if (I>=F)
	{
		T=(24-I)+F;
	}
	else
	{
		T=F-I;
	}
	
	cout << "O JOGO DUROU " << T << " HORA(S)" << endl;
		
	return(0);
	
}
