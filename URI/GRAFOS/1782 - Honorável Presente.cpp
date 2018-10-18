// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Honorável Presente
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1782

#include <bits/stdc++.h>
#define gc getchar
#define pc(x) putchar(x);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void scanint(int &x){
    register int ccc = gc(); x = 0; int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


vector <iii> edg;
vector <ii> query;
int pset[1000010], sz[1000010];
ll ans[1000010], resp[10010], M;

ll combina(ll t){ return t*(t-1)/2; }

int findset(int x){
	if(pset[x]!=x) pset[x]=findset(pset[x]);
	return pset[x];
}
void unionset(int x, int y, int i, int N){
	x=findset(x), y=findset(y); if(x==y) return;
	ans[i]-=(combina(sz[x])+combina(sz[y]));
	pset[x]=y, sz[y]+=sz[x];
	ans[i]+=combina(sz[y]);
}

int main()
{
	int T, z=1; scanint(T);
	
	while(T--){
		
		int N; scanint(N);
		
		rep(i, 0, N+2) pset[i]=i, sz[i]=1; M=N; edg.clear(), query.clear();
		
		int u, v, c;
		rep(i, 1, N){
			scanint(u), scanint(v), scanint(c);
			edg.pb(iii(c, ii(u, v)));
		}
		
		sort(edg.begin(), edg.end());
		
		int Q; cin >> Q;
		rep(i, 0, Q){
			scanint(u);
			query.pb(ii(u, i));
		}
		
		sort(query.begin(), query.end());
		
		int pointer=0;
		rep(i, 0, query.size()){
			int u=query[i].F, id=query[i].S;
			ans[u]=M;
			while(pointer<edg.size() && edg[pointer].F<=u){
				unionset(edg[pointer].S.F, edg[pointer].S.S, u, N);
				pointer++;
			}
			M=ans[u];
			resp[id]=ans[u];
		}
		
		printf("Caso #%d:", z++);
		rep(i, 0, Q) printf(" %lld", resp[i]);
		printf("\n");
		
	}

	return 0;
}

