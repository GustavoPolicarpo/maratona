// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Economia Brasileira
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1796

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int T;
	cin >> T;
	long int VF=0, VC=0, V;
	while(T--)
	{
		cin >> V;
		if(V==1) VC++;
		else if(V==0) VF++;
	}
	if(VF>VC) cout << "Y" << endl;
	else cout << "N" << endl;
}	
