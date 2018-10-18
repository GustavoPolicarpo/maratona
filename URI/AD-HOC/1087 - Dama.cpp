// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Dama
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1087

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int X1, X2, Y1, Y2;


int main()
{
	while(1)
	{
		int MOV=0;
		cin >> X1 >> Y1 >> X2 >> Y2;
		if(X1==0 && X2==0 && Y1==0 && Y2==0) break;
		if(X2==X1 && Y2==Y1) MOV=0;
		else if(abs(X2-X1)==abs(Y2-Y1) || Y2==Y1 || X2==X1) MOV=1;
		else MOV=2;
		cout << MOV << endl;
	}
	
	
			
				
			
	
return(0); 
}

