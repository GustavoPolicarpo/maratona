// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Diego e o Jogo do Martelo
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1922

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


int main(){
	
	int N, M; cin >> N >> M;
	
	vector <ii> v; ii aux;
	rep(i, 0, N){
		scanf("%d %d", &aux.F, &aux.S);
		v.pb(aux);
	}
	
	set <int> adj[1001];
	rep(i, 0, N){
		int ini=v[i].F, fim=v[i].S, p=ini;
		while(p<=fim){
			adj[p].insert(i);
			p+=ini;
		}
	}
	
	int ans=0;
	rep(z, 0, M){
		
		int maior=0, id=0;
		rep(i, 0, 1001){
			if(adj[i].size()>maior){
				maior=adj[i].size();
				id=i;
			}
		}
		
		ans+=maior;
		
		set<int> :: iterator it;
		for(it=adj[id].begin(); it!=adj[id].end(); it++){
			int x=*it;
			int ini=v[x].F, fim=v[x].S, p=ini;
			while(p<=fim){
				if(p!=id) adj[p].erase(adj[p].find(x));
				p+=ini;
			}
		}
		adj[id].clear();
		
	}
	
	cout << ans << '\n';
	
	return 0;
}

