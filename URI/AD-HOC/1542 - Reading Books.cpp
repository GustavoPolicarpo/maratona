// Author: Gustavo Policarpo
// Name: Reading Books
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1542

#include<bits/stdc++.h>
//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


double Q, D, P, X, PAG;
int O;

int main () 
{
	while(1)
	{
		cin >> Q;
		if(Q==0) break;
		cin >> D >> P;
		X=P*D/(P-Q);
		PAG=X*Q;
		O=int(PAG);
		
		if(O!=1) cout << O << " paginas" << endl;
		else cout << O << " pagina" << endl;
	}
	
}
