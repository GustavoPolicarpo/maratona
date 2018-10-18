// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: CPF 1
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1769

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	string T;
	while(cin >> T)
	{
		bool c=true;
		long int S1=0;
		for(int i=1; i<=3; i++)
		{
			S1+=(T[i-1]-'0')*i;
		}
		for(int i=4; i<=6; i++)
		{
			S1+=(T[i]-'0')*i;
		}
		for(int i=7; i<=9; i++)
		{
			S1+=(T[i+1]-'0')*i;
		}
		int b1=S1%11;
		if(b1==10) b1=0;
		if(b1!=T[12]-'0') c=false;
		
		if(c==true)
		{
			long int S2=0;
			for(int i=1; i<=3; i++)
			{
				S2+=(T[i-1]-'0')*(10-i);
			}
			for(int i=4; i<=6; i++)
			{
				S2+=(T[i]-'0')*(10-i);
			}
			for(int i=7; i<=9; i++)
			{
				S2+=(T[i+1]-'0')*(10-i);
			}
			int b2=S2%11;
			if(b2==10) b2=0;
			if(b2!=T[13]-'0') c=false;	
		}
		if(c==true) cout << "CPF valido" << endl;
		else cout << "CPF invalido" << endl;
	}
return(0); 
}


