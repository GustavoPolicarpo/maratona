// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Diga-me a Frequência
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1251

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define error 1e-8

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

bool comp(ii a, ii b)
{
	if(a.S<b.S) return true;
	if(a.S>b.S) return false;
	
	return a.F>b.F;
}
int main()
{
	string T; bool mark=false;
	while(getline(cin, T)){
		if(mark) cout << "\n";
		else mark=true;
		map <int, int> tab;
		map <int, int> :: iterator it;
		vector <ii> out;
		rep(i, 0, T.size())
			tab[T[i]]++;
		for(it=tab.begin(); it!=tab.end(); it++)
			out.pb(mp(it->first, it->second));
		sort(out.begin(), out.end(), comp);
		rep(i, 0, out.size())
			printf("%d %d\n", out[i].F, out[i].S);	
	}
	
return 0;
}

