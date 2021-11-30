// Author: Gustavo Policarpo
// Name: Casinos and Travel
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3075

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
typedef pair <double, ii> iii;

const int MAX = 2e3+3;
const int mod = 1e9+7;


ll fastExp(ll b, ll e){
	ll ret = 1;
	while(e){
		if(e&1) ret = (ret*b)%mod;
		b = (b*b)%mod, e = e/2;
	}
	return ret;
}

vector <int> adj[200020];

int main(){

	int n; scanf("%d", &n);
	
	if(n==1){
		cout << 1 << '\n';
		return 0;
	}
	
	int u, v;
	rep(i, 1, n){
		scanf("%d %d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	ll qtl = 0;
	rep(i, 1, n+1) qtl += (adj[i].size()<=1);
	
	ll ans = 0;
	rep(i, 1, n+1) ans = (ans + fastExp(2, n-qtl+(adj[i].size()==1)))%mod;
	
	printf("%lld\n", ans);
 
    return 0;
}
