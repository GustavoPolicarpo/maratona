// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Trapézios de Natal
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1765

#include<bits/stdc++.h>

using namespace std;


using namespace std;


int main()
{
	int T;
	while(1)
	{
		cin >> T;
		if(T==0) break;
		for(int i=1; i<=T; i++)
		{
			int Q;
			double A, B, TT;
			cin >> Q >> A >> B;
			TT=Q*(A+B)*5/2;
			cout << fixed << setprecision(2)
				 << "Size #" << i << ":" << endl
				 << "Ice Cream Used: " << TT << " cm2" << endl;	
		}
		cout << endl;	
	}
return(0);	
}
