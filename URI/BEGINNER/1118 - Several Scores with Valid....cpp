// Author: Gustavo Policarpo
// Name: Several Scores with Valid...
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1118

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double N1, N2;
int cont=2, X;
bool FIM;


int main()
{
while(FIM==false)
{
	cout << fixed << setprecision(2);
	while(cont==2)
	{
		cin >> N1;
		if( N1<0 || N1>10 )
		{
			cout << "nota invalida" << endl;
		}
		else
		{
			cont--;
		}
	}
	while(cont==1)
	{
		cin >> N2;
		if( N2<0 || N2>10 )
		{
			cout << "nota invalida" << endl;
		}
		else
		{
			cont--;
			cout << "media = " << (N1+N2)/2 << endl;
			
			while(cont==0)
			{
				cout << "novo calculo (1-sim 2-nao)" << endl;
				cin >> X;
				if(X==2) {FIM=true; cont=3;
				}
				else if(X==1) { cont=2;
				}
			}
		}
	}
}
	
		
return 0;	
}
