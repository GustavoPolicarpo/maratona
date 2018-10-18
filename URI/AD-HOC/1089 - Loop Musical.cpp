// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Loop Musical
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1089

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

long int N, i, P;
int subiu=1;

int main()
{
while(1)
{	
	cin >> N; if(N==0) break;
	long int aux=N-1;
	long int H[N];
	i=0;
	P=0;
	subiu=1;
	while(N--)
	{
		cin >> H[i];
		i++;
	}
	if(H[i-1]>H[0])
	{
	//	P++;
		subiu=0;
	}
	else if(H[i-1]<H[0])
	{
	//	P++;
		subiu=1;
	}
	i=0;
	
	while(aux--)
	{
		i++;
		
		if(H[i]>H[i-1]&&subiu==0)
		{
			P++; subiu=1;
		}
		else if(H[i]<H[i-1]&&subiu==1)
		{
			P++; subiu=0;
		}
	}
	if(H[i-1]>H[0]&&subiu==1)
	{
		P++;	
	}
	else if(H[i-1]<H[0]&&subiu==0)
	{
		P++;
	}
	if(P%2==1) P++;
	
	cout << P << endl;
	
	
}

	


return(0);	
}	 
		
	



