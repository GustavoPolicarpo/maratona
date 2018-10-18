// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pedra, Papel, Ataque Aéreo
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2031

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int n;
string P1, P2;

int main()
{
	cin >> n;
	while(n--)
	{
		cin >> P1 >> P2;
		
			if(P1=="pedra")
			{
				if(P2=="pedra") cout << "Sem ganhador" << endl;
				else if(P2=="ataque") cout << "Jogador 2 venceu" << endl;
				else if(P2=="papel") cout << "Jogador 1 venceu" << endl;
			}	
			else if(P1=="ataque")
			{
				if(P2=="pedra") cout << "Jogador 1 venceu" << endl;
				else if(P2=="ataque") cout << "Aniquilacao mutua" << endl;
				else if(P2=="papel") cout << "Jogador 1 venceu" << endl;
			}
			else if(P1=="papel")
			{
				if(P2=="pedra") cout << "Jogador 2 venceu" << endl;
				else if(P2=="ataque") cout << "Jogador 2 venceu" << endl;
				else if(P2=="papel") cout << "Ambos venceram" << endl;
			}
		
		
	}
	
	
return(0); 
}

