// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Esquerda, Volver!
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1437

#include<bits/stdc++.h>
//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int N; 
char C[1001];
int P=4;
char O;

int main () 
{
	while(cin >> N)
	{
		if(N==0) break;
		P=4;
		cin >> C;
	
		for(int i=0; i<N; i++)
		{
			if (C[i]=='D') 
			{
				P++;
				if(P==8) P=4;
			}
			else if (C[i]=='E') 
			{
				P--;
				if(P==0) P=4;	
			}
				
		}
		switch(P)
		{
			case 1: O='L'; break;
			case 2: O='S'; break;
			case 3: O='O'; break;
			case 4: O='N'; break;
			case 5: O='L'; break;
			case 6: O='S'; break;
			case 7: O='O'; break;
		}
			
		
		cout << O << endl;
	}
  
}
