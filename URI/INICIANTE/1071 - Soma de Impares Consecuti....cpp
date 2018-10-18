// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Soma de Impares Consecuti...
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1071

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int I, F, S;


int main()
{
	// cout << fixed << setprecision(1);
	cin >> I >> F;
	
	if (I<F) 
	{
			if ( I%2!=0 ) { I=I+2; }
			else { I=I+1; }
			if ( F%2!=0 )  {F=F-2; }
			else { F=F-1; }
		   	
			for (I; I<=F; I=I+2) 
		{
			S=S+I;
		}		
	}
	else if (F<I)
	{
			if ( F%2!=0 ) { F=F+2; }
			else { F=F+1; }
			if ( I%2!=0 ) { I=I-2; }
			else { I=I-1; }
		    
			for (F; F<=I; F=F+2) 
		{
			S=S+F;
		}		
	}
	else
	{
		S=0;
	}
		
	cout << S << endl;

return 0;	
}
