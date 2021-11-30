// Author: Gustavo Policarpo
// Name: Bacteria I
// Level: 3
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2356

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)


//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int main()
{
	string d, s;
	while(cin >> d){
		cin >> s;
		int p = d.find(s);
		p == -1 ? puts("Nao resistente") : puts("Resistente");
	}
	
	return 0;
	
}
