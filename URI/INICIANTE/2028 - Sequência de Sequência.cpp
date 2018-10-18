// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sequência de Sequência
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2028

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int N, i, cont, cont2;

int main()
{
	while(cin >> N)
	{
	
		i++;
		long int num=N*(N+1)/2+1;
		if(num>1) cout << "Caso " << i << ": " << num << " numeros" << endl;
		else cout << "Caso " << i << ": " << num << " numero" << endl;
		
		
		if(N==0) cout << 0 << endl;
		else
		{
			cout << 0 << " ";
			for(cont=1; cont<=N; cont++)
			{
				cont2=1;
				while(cont2<=cont)
				{
					cout <<  cont; 
					cont2++;
					if(cont2==cont+1 && cont==N) cout << endl;
					else cout << " ";
				}
					
			}
		}
		cout << endl;	
			
	}
return(0); 
}

