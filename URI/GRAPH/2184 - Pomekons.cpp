// Author: Gustavo Policarpo
// Name: Pomekons
// Level: 9
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2184

#define gc getchar_unlocked
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
#define error 1e-4

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

const int MAX=1000010, LOGM=21;
int h[MAX], pai[MAX][LOGM], forca[MAX][LOGM];
int N, K, Q; vector <ii> adj[1000010];
int valor[5005], custo[5005], pd[5005][1001];

void dfs(int u, int last){
	rep(i, 0, adj[u].size()){
		int v=adj[u][i].F;
		if(v==last) continue; pai[v][0]=u, forca[v][0]=adj[u][i].S; h[v]=h[u]+1;
		rep(j, 1, LOGM){
			pai[v][j]=pai[pai[v][j-1]][j-1];
			forca[v][j]=max(forca[v][j-1], forca[pai[v][j-1]][j-1]);
		}
		dfs(v, u);
	}
	return;
}
ii LCA(int a, int b){
	if(h[a]<h[b]) swap(a, b);
	int ret=0;
	for(int i=LOGM-1; i>=0; i--){
		if(h[pai[a][i]]>=h[b]){
			ret=max(ret, forca[a][i]);
			a=pai[a][i];
		}
	}
	if(a==b) return mp(a, ret);
	for(int i=LOGM-1; i>=0; i--){
		if(pai[a][i]!=pai[b][i]){
			ret=max(ret, max(forca[a][i], forca[b][i]));
			a=pai[a][i], b=pai[b][i];
		}
	}
	ret=max(ret, max(forca[a][0], forca[b][0]));
	return mp(pai[a][0], ret);
}

int solve(int i, int c){
	if(i==Q) return 0;
	if(pd[i][c]!=-1) return pd[i][c];
	int ret=solve(i+1, c);
	if(c-custo[i]>=0){
		ret=max(ret, solve(i+1, c-custo[i])+valor[i]);
	}
	return pd[i][c]=ret;
}
int main()
{
	scanf("%d %d", &N, &K);
	int u, v, c;
	rep(i, 1, N){
		scanf("%d %d %d", &u, &v, &c);
		adj[u].pb(mp(v, c));
		adj[v].pb(mp(u, c));
	}
	
	rep(i, 0, LOGM) pai[1][i]=1, forca[1][i]=0, h[1]=0;;
	dfs(1, 1);
	scanf("%d", &Q);
	rep(i, 0, Q){
		scanf("%d %d", &u, &v);
		ii lca=LCA(u, v);
		//cout << lca.F << " " << lca.S << endl;
		int dist=h[u]+h[v]-2*h[lca.F]; //cout << dist << endl;
		custo[i]=dist+1, valor[i]=lca.S;
	}
	memset(pd, -1, sizeof pd);

	int out=solve(0, K);
	if(out==0) printf("-1\n");
	else printf("%d\n", out);
	

return 0;

}
