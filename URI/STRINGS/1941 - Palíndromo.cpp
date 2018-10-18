// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Palíndromo
// Nível: 4
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1941

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
#define error 1e-12

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

string s;
int N, aux;
bool ideal[2001];
ii pd[2001][2001];

ii solve(int i, int j)
{
	if(i>j) return mp(0, 0);
	if(i==j) return mp(ideal[i], 1);
	
	if(pd[i][j]!=mp(-1, -1)) return pd[i][j];
	
	ii ret=mp(0, 0);
	
	if(s[i]==s[j]){
		ret=solve(i+1, j-1);
		ret.F+=ideal[i]+ideal[j];
		ret.S+=2;
	}
	ret=max(ret, max(solve(i+1, j), solve(i, j-1)));
	
	return pd[i][j]=ret;
}
int main()
{
	cin >> s;
	cin >> N;
	int tam=s.size();
	rep(i, 0, tam)
		rep(j, 0, tam)
			pd[i][j]=mp(-1, -1);
	
	memset(ideal, 0, sizeof ideal)		;
	rep(i, 0, N){
		scanf("%d", &aux);
		ideal[aux-1]=1;
	}
	
	ii out=solve(0, tam-1);
	cout << out.S << endl;
	
	
return 0;
}


