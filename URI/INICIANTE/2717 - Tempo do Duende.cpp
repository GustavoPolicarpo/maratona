// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Tempo do Duende
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2717

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;



int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int a, b, c; cin >> a >> b >> c;
	if(b+c<=a) puts("Farei hoje!");
	else puts("Deixa para amanha!");
	
	return 0;
	
}
