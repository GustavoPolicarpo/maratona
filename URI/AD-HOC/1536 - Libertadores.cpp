// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Libertadores
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1536

#include<bits/stdc++.h>
//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int N;
char L;
int M, V, PA, PB, GA;

int main () 
{
	cin >> N;
	while(N--)
	{
		PA=0; PB=0; GA=0;
		cin >> M >> L >> V;
		if(M>V) PA=3;
		else if(M==V) 
		{
			PA=1;
			PB=1;
		} 
		else PB=3;
		GA=V;
		cin >> V >> L >> M;
		if(M>V) PA=PA+3;
		else if(M==V) 
		{
			PA=PA+1;
			PB=PB+1;
		}
		else PB=PB+3;
		if(GA<M) GA=1;
		else if(GA>M) GA=2;
		else GA=0;
		
		if(PA>PB) cout << "Time 1" << endl;
		else if(PB>PA) cout << "Time 2" << endl;
		else
		{
			if(GA==0) cout << "Penaltis" << endl;
			else if(GA==1) cout << "Time 1" << endl;
			else if(GA==2) cout << "Time 2" << endl;
		}
	}
  
}
