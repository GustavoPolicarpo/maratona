// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Zero vale Zero
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1871

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


char aux[]={"0123456789"};
int main()
{
	long int M, N;
	while(cin >> M >> N)
	{
		string out;
		if(M==0 && N==0) break;
		long long int C=M+N;
		while( C != 0 )
		{
			int temp=C%10;
			if(temp!=0) out+=aux[temp];
		
			C/=10; // divisão de inteiros, e quase como se você retirasse o algarismo mais a direita do numero
		}
		reverse( out.begin(), out.end() );
		
		cout << out << endl;
		
	}
	
	
return(0); 
}


