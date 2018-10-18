// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: TDA Racional
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1022

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int MDC(int a, int b)
{
	int r;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}


int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		int N1, D1, N2, D2;
		char a, b, c;
		cin >> N1 >> a >> D1 >> b >> N2 >> c >> D2;

		int num1, dem1;
		if(b=='+')
		{
			num1=N1*D2+N2*D1;
			dem1=D1*D2;	
		}
		else if(b=='-')
		{
			num1=N1*D2-N2*D1;
			dem1=D1*D2;	
		}
		else if(b=='*')
		{
			num1=N1*N2;
			dem1=D1*D2;	
		}
		else if(b=='/')
		{
			num1=N1*D2;
			dem1=N2*D1;	
		}
		
		int mdc = MDC(num1, dem1);
		int num2=num1/abs(mdc);
		int dem2=dem1/abs(mdc);
		
		cout<<num1<<'/'<<dem1<<" = "<<num2<<'/'<<dem2<<endl;		
	}	
return (0);	
}
