#include <bits/stdc++.h>
#define gc getchar
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace __gnu_pbds;
using namespace std;

typedef tree<
int,
null_type,
greater<int>,
rb_tree_tag,
tree_order_statistics_node_update> 
ordered_set;

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;

int pset[100001], ans[500005], sz[100001];
vector <iii> edg;
vector <iiii> query;

ordered_set T[100001];
vector <int> compo[100001];

bool mycmp1(iii a, iii b){
	return a.F<b.F;
}

bool mycmp2(iiii a, iiii b){
	return a.F.S<b.F.S;
}

int findset(register int x){
	if(x!=pset[x]) pset[x]=findset(pset[x]);
	return pset[x];
}

void unionset(register int x, register int y){
	x=findset(x), y=findset(y); if(x==y) return;
	if(sz[x]>sz[y]) swap(x, y);
	pset[x]=y, sz[y]+=sz[x];
	register int i=0, tam=compo[x].size();
	for(; i<tam; i++) T[y].insert(compo[x][i]), compo[y].pb(compo[x][i]);
	ordered_set emp; swap(T[x], emp);
	vector <int> pme; swap(compo[x], pme);
}

void scanint(register int &x){
	register int ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

vector <ii> in;
map<int, int> mapa;

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	register int n, m, q, beauty;
	register int u, v, c, i, z, pe, px, x, k, id, cnt=0;
	
	scanint(n), scanint(m), scanint(q);
	edg.resize(m), query.resize(q), in.resize(n);
	
	for(i=1; i<=n; i++){
		scanint(beauty);
		pset[i]=i, sz[i]=1;
		in[i-1]=ii(beauty, i);
	}
	
	sort(in.begin(), in.end());
	rep(i, 0, n){
		mapa[cnt]=in[i].F;
		compo[in[i].S].pb(cnt);
		T[in[i].S].insert(cnt);
		cnt++;
	}
	
	in.clear(), in.resize(0), cnt=0;
	
	for(i=0; i<m; i++){
		scanint(u), scanint(v), scanint(c);
		if( u == v ) continue;
		edg[cnt++]=(iii(c, ii(u, v)));
	}
	
	for(i=0; i<q; i++){
		scanint(u), scanint(v), scanint(c);
		query[i]=(iiii(ii(u, v), ii(c, i)));
	}
	
	
	sort(edg.begin(), edg.begin()+cnt, mycmp1);
	sort(query.begin(), query.end(), mycmp2);
	
	pe=0, px=cnt;
	for(z=0; z<q; z++ ){
		
		iiii qa=query[z]; 
		while(pe<px && edg[pe].F<=qa.F.S){
			u=edg[pe].S.F, v=edg[pe].S.S;
			unionset(u, v), pe++;
		}
		
		x=qa.F.F, k=qa.S.F, id=qa.S.S; x=findset(x);
		
		if(T[x].size()<k) ans[id]=-1;
		else ans[id]=mapa[*T[x].find_by_order(k-1)];
		
	}
	
	rep(i, 0, q) printf("%d\n", ans[i]);

	return 0;
	
}
