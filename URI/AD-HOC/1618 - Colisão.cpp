// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Colisão
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1618

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
