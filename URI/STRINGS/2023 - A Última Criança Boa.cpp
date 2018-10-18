// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A Última Criança Boa
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2023

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	string T;
	vector <string> dic, ord, nord;
	while(getline(cin, T))
	{		
		dic.push_back(T);
		
		string temp="";
		for(int i=0; i<T.size(); i++)		
			temp+=tolower(T[i]);
		ord.push_back(temp);
		nord.push_back(temp);			
	}
	sort(ord.begin(), ord.end());
	int comp;
	int last=ord.size()-1;
	for(int i=0; i<=last; i++)
		if(ord[last]==nord[i])
			comp=i;
			
	cout << dic[comp] << endl;
				
return 0;
}





