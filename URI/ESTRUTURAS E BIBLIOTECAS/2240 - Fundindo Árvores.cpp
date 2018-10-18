// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fundindo Árvores
// Nível: 5
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2240

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
#define mod 1000000007
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, M, esquerda, direita;
vector <int> ae[10010], ad[10010];

void dfs1(int u, int c){
	esquerda=max(esquerda, c);
	if(ae[u][0]!=0){
		dfs1(ae[u][0], 1);
	}
	if(ae[u][1]!=0){
		dfs1(ae[u][1], c+1);
	}
}

void dfs2(int u, int c){
	direita=max(direita, c);
	if(ad[u][0]!=0){
		dfs2(ad[u][0], c+1);
	}
	if(ad[u][1]!=0){
		dfs2(ad[u][1], 1);
	}
}

int main()
{
	int u, e, d, out=INF;
	
	scanf("%d", &N);
	rep(i, 0, N){
		scanf("%d %d %d", &u, &e, &d);
		ae[u].pb(e), ae[u].pb(d);
	}
	
	scanf("%d", &M);
	rep(i, 0, M){
		scanf("%d %d %d", &u, &e, &d);
		ad[u].pb(e), ad[u].pb(d);
	}
	
	esquerda=0;
	dfs1(1, 1);
	direita=1, u=1;
	while(ad[u][0]!=0){
		u=ad[u][0];
		direita++;
	}
	
	out=min(out, N+M-min(direita, esquerda));
	
	direita=0;
	dfs2(1, 1);
	esquerda=1, u=1;
	while(ae[u][1]!=0){
		u=ae[u][1];
		esquerda++;
	}
	
	out=min(out, N+M-min(direita, esquerda));
	
	printf("%d\n", out);
	
return 0;
}
