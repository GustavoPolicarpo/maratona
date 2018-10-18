// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Flores Florescem da França
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1140

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	string T;
	while(getline(cin,T))
	{
		if(T[0]=='*') break;
		char c1=T[0]; char c2; bool verify=false; bool f=true;
		if(isupper(c1)) c2=c1+32;
		else c2=c1-32;
		for(int i=1; i<T.size(); i++)
		{
			//	cout << T[i];
			if(verify==true)
			{
				if(T[i]!=c1 && T[i]!=c2)
				{
					f=false;
					break;
				}
				verify=false;
			}
			if(T[i]==' ') verify=true;
		}
		if(f==true) cout << 'Y' << endl;
		else cout << 'N' << endl;	
	}
return(0); 
}


