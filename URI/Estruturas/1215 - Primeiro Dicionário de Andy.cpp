// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Primeiro Dicionário de Andy
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1215

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	string T;
	set <string> dic;
	set <string>:: iterator it;
	string temp="";
	while(getline(cin, T))
	{
		if(temp!=""&&!dic.count(temp))
					dic.insert(temp);
					
		temp="";
				
		//if(T=="pedefranga") break;
		for(int i=0; i<T.size(); i++)
		{		
			if(isalpha(T[i]))
				temp+=tolower(T[i]);
				
			else
			{
				if(temp!=""&&!dic.count(temp))
					dic.insert(temp);
					
				temp="";
			}
		}
	}
	vector <string> dicord;
	for(it=dic.begin(); it!=dic.end(); it++)
		dicord.push_back(*it);
		
	sort(dicord.begin(), dicord.end());
	
	for(int i=0; i<dicord.size(); i++)
		cout << dicord[i] << endl;
	
return 0;
}





