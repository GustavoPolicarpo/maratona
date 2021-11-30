// Author: Gustavo Policarpo
// Name: Dating
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3072

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define REP(i,a,b) for( int i = (int) a; i <= (int) b; i++ )
#define PER(i,a,b) for( int i = (int) a; i >= (int) b; i-- )
#define F first
#define S second
#define mk make_pair
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> ii;
typedef pair <ii, ii> iii;

const int MAX = 2e3+3;
const int mod = 1e9+7;


int n, q;
int t[100010];
int f[100010];
int pai[100010][22];
int h[100010];
int in[100010], out[100010];
int pro[200020];
int cnt=0;
vector <int> adj[100010];
vector <iii> qr;
ll ans[100010];
unordered_map<int, int> freq[2];
int has[200020];
ll tans = 0;

void dfs(int u, int last){
	in[u] = cnt, pro[cnt++] = u;
	
	rep(i, 0, adj[u].size()){
		int v = adj[u][i];
		if(v==last) continue;
		
		pai[v][0] = u; h[v] = h[u]+1;
		rep(j, 1, 21) pai[v][j] = pai[pai[v][j-1]][j-1];
		
		dfs(v, u);
	}
	
	out[u] = cnt, pro[cnt++] = u;
}



int lca(int u, int v){
	if(h[u] < h[v]) swap(u, v);
	for(int i=20; i>=0; i--){
		if(h[pai[u][i]]>=h[v]){
			u = pai[u][i];
		}
	}
	if(u!=v){
		for(int i=20; i>=0; i--){
			if(pai[u][i]!=pai[v][i]){
				u = pai[u][i];
				v = pai[v][i];
			}
		}
		u = pai[u][0];
		v = pai[v][0];
	}
	assert(u==v);
	return u;
}

 
int bs;
bool cmp(iii a, iii b){
	ii pa = ( a.F.F==a.S.S ? (ii(in[a.F.F], in[a.F.S])) : (ii(out[a.F.F], in[a.F.S])) );
	ii pb = ( b.F.F==b.S.S ? (ii(in[b.F.F], in[b.F.S])) : (ii(out[b.F.F], in[b.F.S])) );
	int sa = pa.F/bs, sb = pb.F/bs;
	if(sa!=sb) return sa < sb;
	return pa.S < pb.S;
}

void doIt(int x){
	int p = pro[x], tp = t[p], fp = f[p], add = 1;
	has[p]^=1; if(!has[p]) add = -1;
	tans += (freq[tp^1][fp]*add);
	freq[tp][fp]+=add;
}

int main(){

	scanf("%d", &n); bs = sqrt(2*n);
	rep(i, 1, n+1) scanf("%d", &t[i]);
	rep(i, 1, n+1) scanf("%d", &f[i]);
	
	int u, v;
	rep(i, 1, n){
		scanf("%d %d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	h[1] = 1;
	rep(i, 0, 21) pai[1][i] = 0;	
	dfs(1, 1);
	
	scanf("%d", &q); iii aux;
	rep(i, 1, q+1){
		scanf("%d %d", &aux.F.F, &aux.F.S); aux.S.F = i;
		if(in[aux.F.F] > in[aux.F.S]) swap(aux.F.F, aux.F.S);
		aux.S.S = lca(aux.F.F, aux.F.S);
		qr.pb(aux);
	}
	
	sort(qr.begin(), qr.end(), cmp);
	
	int ini = 0, fim = 0;

	/*rep(i, 1, n+1){
		cout << i << ": ";
		debug2(in[i], out[i]);
	}
	rep(i, 0, 2*n){
		cout << pro[i].F << " ";
	}	cout << '\n';
	rep(i, 0, 2*n){
		cout << t[pro[i].F] << " ";
	}	cout << '\n';
	rep(i, 0, 2*n){
		cout << f[pro[i].F] << " ";
	}	cout << '\n';*/
	
	rep(i, 0, qr.size()){
		aux = qr[i];
		u = aux.F.F, v = aux.F.S;
		int uv = aux.S.S;
		
		//debug2(u, v);
		//debug(uv);
		
		int l, r;		
		if(uv==u) l=in[u], r=in[v];
		else l=out[u], r=in[v];
		
		assert(l<=r);
		
		//debug2(l, r);
		
		while(fim<=r) doIt(fim++);
		//debug(tans);
		while(fim>r+1) doIt(--fim);
		//debug(tans);		
		while(ini<l) doIt(ini++);
		//debug(tans);
		while(ini>l) doIt(--ini);
		//debug(tans);
		
		//debug2(ini, fim);
		//debug(tans);
		
		ans[aux.S.F] = tans;
		if(u!=uv){
			int p = uv, tp = t[p], fp = f[p];
			ans[aux.S.F] += freq[tp^1][fp];
		}
		
	}
	
	rep(i, 1, q+1) printf("%lld\n", ans[i]);
	
	
    return 0;
}
