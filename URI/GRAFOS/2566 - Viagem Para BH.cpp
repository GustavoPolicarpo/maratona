// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Viagem Para BH
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2566

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;


int main(){
	
	int n, m;
	
	while(scanf("%d %d", &n, &m)!=EOF){
		
		int bus[n][n], air[n][n];
		rep(i, 0, n){
			rep(j, 0, n)
				bus[i][j]=air[i][j]=INF;
			bus[i][i]=air[i][i]=0;
		}
		
		int u, v, t, c;
		rep(i, 0, m){
			scanf("%d %d %d %d", &u, &v, &t, &c); u--, v--;
			if(t==0) bus[u][v]=min(bus[u][v], c);
			if(t==1) air[u][v]=min(air[u][v], c);
		}
		
		rep(k, 0, n)
		rep(i, 0, n)
		rep(j, 0, n){
			bus[i][j]=min(bus[i][j], bus[i][k]+bus[k][j]);
		}
		rep(k, 0, n)
		rep(i, 0, n)
		rep(j, 0, n){
			air[i][j]=min(air[i][j], air[i][k]+air[k][j]);
		}
		
		printf("%d\n", min(bus[0][n-1], air[0][n-1]));
		
	}
	
	return 0;
	
}
