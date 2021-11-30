// Author: Gustavo Policarpo
// Name: Colision
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1618

#include<bits/stdc++.h>
//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int N;
int AX, AY, BX, BY, CX, CY, DX, DY, RX, RY;

int main () 
{
	cin >> N;
	while(N--)
	{
		cin >> AX >> AY >> BX >> BY >> CX >> CY >> DX >> DY >> RX >> RY;
		if(RX>=AX && RX<=BX && RY>=AY && RY<=DY) cout << 1 << endl;
		else cout << 0 << endl;
	}
	
	
	
}
