// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Converter para Hexadecimal
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1957

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

string HE;
long long int  u;
long long H, h;
char UU[32];
char hhh;
int i;


int main()
{
	cin >> u;
	
	h=u%16;
				switch(h)
				{
					case 0: hhh='0'; break; case 5: hhh='5'; break; case 10: hhh='A'; break; case 15: hhh='F'; break;
					case 1: hhh='1'; break; case 6: hhh='6'; break; case 11: hhh='B'; break;
					case 2: hhh='2'; break; case 7: hhh='7'; break; case 12: hhh='C'; break;
					case 3: hhh='3'; break; case 8: hhh='8'; break; case 13: hhh='D'; break;
					case 4: hhh='4'; break; case 9: hhh='9'; break; case 14: hhh='E'; break;
				}
				
			while(pow(16,(i))<=u) { i++;  }
			i--;
			
			while(i>0)
			{
				H=u/(pow(16,i));
				switch(H)
				{
					case 0: UU[i]='0'; break; case 5: UU[i]='5'; break; case 10: UU[i]='A'; break; case 15: UU[i]='F'; break;
					case 1: UU[i]='1'; break; case 6: UU[i]='6'; break; case 11: UU[i]='B'; break;
					case 2: UU[i]='2'; break; case 7: UU[i]='7'; break; case 12: UU[i]='C'; break;
					case 3: UU[i]='3'; break; case 8: UU[i]='8'; break; case 13: UU[i]='D'; break;
					case 4: UU[i]='4'; break; case 9: UU[i]='9'; break; case 14: UU[i]='E'; break;
				}
				u=u-H*pow(16,i);
				HE=HE+UU[i];
				i--;
			}
			cout << HE << hhh << endl;	
}
