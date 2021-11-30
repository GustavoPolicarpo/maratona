// Author: Gustavo Policarpo
// Name: Promotion
// Level: 4
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1624

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int go(int W, int wt[], int b[], int n)
{		//peso max, peso ob, valor ob, tam
	int V[n+1][W+1];

	for(int w=0; w<=W; w++)
		V[0][w] = 0;
	for(int i=1; i<=n; i++)
		V[i][0] = 0;

	for(int i=1; i<=n; i++)
	{
		for(int w=1; w<=W; w++)
		{	
			if(wt[i-1] <= w)
			{
				if((b[i-1] + V[i-1][w-wt[i-1]]) > V[i-1][w])
					V[i][w] = b[i-1] + V[i-1][w-wt[i-1]];
				else
					V[i][w] = V[i-1][w];
			}
			else
				V[i][w] = V[i-1][w];
		}
	}
	
	/*for(int i=1; i<=n; i++)
	{
		for(int w=1; w<=W; w++)
		{
			cout << V[i][w] <<  " ";
		}
		cout << endl;	
	}*/

	return V[n][W];
}


int main()
{
	int N;
	while(cin >> N)
	{
		if(N==0) break;	// tamanho da lista
	
		int b[N],wt[N];
		for(int i=0; i<N; i++)
			cin >> b[i] >> wt[i]; //preco e peso dos itens
	
		int W;
		cin >> W;   //peso da mochila
		
		int max_valor = go(W, wt, b, N); //peso max, peso ob, valor ob, tam
	
		cout << max_valor << endl;
	}
	
return 0;
}
