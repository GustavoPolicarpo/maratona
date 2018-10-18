// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Penalização
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2225

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F

typedef pair < int, int > ii;
typedef long long int ll;

int mat[16][16];
int pd[16][(1<<15) + 1][6], N, M, K;

int solve(int u, int mask, int k){

	if( mask == ( 1 << N ) -1 ) return 0;
	int &p=pd[u][mask][k]; if(p!=-1) return p;
	rep(i, k+1, K) if(pd[u][mask][i] < p) return INF;
	
	int ret=INF;
	
	rep(i, 0, N){
		if(mask&(1<<i)) continue;
		if(k) ret=min(ret, solve(i, mask|(1<<i), k-1));
		if(mat[u][i]<INF) ret=min(ret, solve(i, mask|(1<<i), k)+mat[u][i]);	
	}
		
	return p=ret;	
}	


int main (){
	int T; cin >> T;
	while(T--){
		
		scanf("%d %d %d", &N, &M, &K);

		rep(i, 0, N)
		rep(j, 0, (1<<N) + 1) 
		rep(k, 0, K + 1) 
			pd[i][j][k]=-1;
			
		memset(mat, INF, sizeof mat);
		
		int u, v, c;
		while(M--){
			scanf("%d %d %d", &u, &v, &c);
			u--, v--;
			mat[u][v]=min(mat[u][v], c);
			mat[v][u]=min(mat[v][u], c);
		}
		
		rep(k, 0, N)
		rep(i, 0, N)
		rep(j, 0, N)
			mat[i][j]=min(mat[i][j], mat[i][k]+mat[k][j]);
		
		int out=solve(0, 1, K);
		
		if(out>=INF) printf("-1\n");
		else printf("%d\n", out);	
	}
			
return 0;
}
