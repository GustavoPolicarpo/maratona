// Author: Gustavo Policarpo
// Name: Building Houses
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1541

#include <iostream>
#include <cmath>

using namespace std;

int A, B, C;
double AREA, T, t;

int main()
{
	while(1)
	{
		cin >> A; if(A==0) break; cin >> B >> C;
		AREA=A*B;
		T=AREA*100/C;
		t=trunc(sqrt(T));
		cout << t << endl;	
	}
	
return(0);
}

