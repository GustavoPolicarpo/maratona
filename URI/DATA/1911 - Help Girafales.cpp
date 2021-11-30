// Author: Gustavo Policarpo
// Name: Help Girafales
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1911

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

 
int main()
{
	int N;
	while(cin >> N)
	{
		if(N==0) break;
		map <string, string> nome;
		while(N--)
		{
			string no, ass;
			cin >> no >> ass;
			nome[no]=ass;
		}
		int n;
		cin >> n;
		int assfalsas=0;
		while(n--)
		{
			string no, ass;
			cin >> no >> ass;
			string comp=nome[no];
			int dif=0;
			for(int i=0; i<comp.size(); i++)
				if(comp[i]!=ass[i])
					dif++;
			if(dif>1)
				assfalsas++;
		}
		nome.clear();
		cout << assfalsas << endl;	 		
	 		
	}
return 0;
}







