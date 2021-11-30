// Author: Gustavo Policarpo
// Name: Laundry
// Level: 1
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1794

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int P;
	int LA, LB, SA, SB;
	cin >> P;
	cin >> LA >> LB;
	cin >> SA >> SB;
	
	if(P>=LA && P <=LB && P>=SA && P<=SB) cout << "possivel" << endl;
	else cout << "impossivel" << endl;
}	
