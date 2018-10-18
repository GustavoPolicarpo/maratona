// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sort! Sort!! e Sort!!!
// Nível: 4
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1252

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
	if(a.F<b.F) return true;
	if(a.F>b.F) return false;
	
	if(a.S%2!=0 && b.S%2==0) return true;
	if(a.S%2==0 && b.S%2!=0) return false;
	
	if(a.S%2!=0 && b.S%2!=0){
		if(a.S>b.S) return true;
		if(a.S<b.S) return false;
	}
	
	if(a.S%2==0 && b.S%2==0){
		if(a.S<b.S) return true;
		if(a.S>b.S) return false;
	}
}

int main()
{
	//freopen("out.txt", "w", stdout);
	int N, M, aux;
	while(scanf("%d %d", &N, &M) and N+M){
		vector <ii> in;
		rep(i, 0, N){
			scanf("%d", &aux);
			in.pb(mp(aux%M, aux));
		}
		sort(in.begin(), in.end(), comp);
		printf("%d %d\n", N, M);
		rep(i, 0, N)
			printf("%d\n", in[i].S);
	}
	printf("%d %d\n", 0, 0);
	
	
return 0;
}
