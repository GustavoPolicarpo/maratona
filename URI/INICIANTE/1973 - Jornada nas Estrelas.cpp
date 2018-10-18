// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Jornada nas Estrelas
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1973

#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<cctype>
#include <cmath>


//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

unsigned  long long int N, aux, S;
unsigned  long long int  A;

int main()
{
	cin >> N;
	aux=N;
	unsigned  long long int X[N];
	long long int i=0;
	while(N--)
	{
		cin >> X[i];
		i++;	
	}
	i=0;
	
	while(1)
	{
		
		if(X[i]>0)
		{
				
		
			X[i]=X[i]-1;
			
			if((X[i]+1)%2==0)
			{
				i--;
				A++;
				
					while(i>=0)
					{
						if(X[i]>0) X[i]=X[i]-1;
						i--;
					}
					
				
				
				break;
			} 
			else 
			{
				i++;
				A++;	
			}
			if(i>=aux)	 break;	
		}
		else
		{
			i--;
			A++;
			
				while(i>=0)
				{
					if(X[i]>0) X[i]=X[i]-1;
				
					i--;
				}	
				break;
		}
		
	
	}
	i=0;
	while(aux--)
	{
		S=S+X[i];
		i++;		
	}
	
	cout << A << " " << S << endl;
	
	
	
return(0); 
}

