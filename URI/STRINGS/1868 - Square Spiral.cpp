// Author: Gustavo Policarpo
// Name: Square Spiral
// Level: 2
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1868

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

bool direita=true,
	cima=true,
	esquerda=true,
	baixo=true;


int b, v;

int pos(int &i, int &j)
{
	if(direita==true)
	{
		j++;
		if(j==b+v)
		{
			direita=false;
			cima=true;
		}
		

	}
	else if(cima==true)
	{
		i--;
		if(i==b-v)
		{
			cima=false;
			esquerda=true;
		}
		
		
	}
	else if(esquerda==true)
	{
		j--;
		if(j==b-v)
		{
			esquerda=false;
			baixo=true;	
		}
		
	}
	else if(baixo==true)
	{
		i++;
		if(i==b+v)
		{
			baixo=false;
			direita=true;
			v++;
		}
			
	}
	
}
int main()
{
	int N;
	while(cin >> N)
	{
		if(N==0) break;
		direita=true;
		cima=true;
		esquerda=true;
		baixo=true;
		v=1;

		b=N/2; int bi=N/2, bj=N/2;
		for(int k=0; k<pow(N,2); k++)
		{
			for(int i=0; i<N; i++)
			{
				for(int j=0; j<N; j++)
				{
					if(i!=bi||j!=bj)
						cout << 'O';
					else
						cout << 'X';
				}
				cout << endl;
			}
			cout << '@' << endl;
			pos(bi, bj);
		}
		
	}
	
	
	return 0;
}
