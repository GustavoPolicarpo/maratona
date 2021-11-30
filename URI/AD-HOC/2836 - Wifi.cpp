// Author: Gustavo Policarpo
// Name: Wifi
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2836

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

int N;
struct rect{
	int x1, x2, y1, y2, id;
};

struct seg{
	int x, y1, y2, id;
	bool operator <(seg b) const {
		if(x!=b.x) return x < b.x;
		if(y1!=b.y1) return y1 < b.y1;
		return y2 < b.y2;
	}
};

struct lines{
	int y1, y2, id;
	bool operator ==(lines b) const {
		if(y1!=b.y1) return false;
		if(y2!=b.y2) return false;
		return id==b.id;
	}
	bool operator <(lines b) const {
		if(y1!=b.y1) return y1 < b.y1;
		if(y2!=b.y2) return y2 < b.y2;
		return id < b.id;
	}
};

rect in[100010];
seg segs[200020];

set <lines> st;
set <lines> :: iterator it;

vector <int> adj[100010];
int vis[100010];

void dfs(int u){
	if(vis[u]) return;
	lines aux = lines{in[u].y2, in[u].y1, in[u].id};
	if(st.count(aux)){
		st.erase(st.find(aux));
	}	vis[u] = 1;
	
	rep(i, 0, adj[u].size()){
		int v = adj[u][i];
		dfs(v);
	}
}

int main(){
	
	scanf("%d", &N);
	rep(i, 0, N){
		scanf("%d %d %d %d", &in[i].x1, &in[i].y1, &in[i].x2, &in[i].y2);
		in[i].id = i;
		segs[i*2] = seg{in[i].x1, in[i].y2, in[i].y1, in[i].id};
		segs[i*2+1] = seg{in[i].x2, in[i].y2, in[i].y1, in[i].id};
	}
		
		
	sort(segs, segs+2*N);
	
	int ans = 0, cnt = 0;
	rep(i, 0, 2*N){
		if(vis[segs[i].id]) continue; // it has already been covered

		lines aux = lines{segs[i].y1, segs[i].y2, segs[i].id};
		
		it = st.lower_bound(aux);
		
		if(it!=st.end()){
			lines cmp = *it;
			if(cmp.id == segs[i].id){ // closing
				dfs(segs[i].id);
				ans++;
				continue;
			}
		}
		if(it!=st.begin()){
			it--;
			lines cmp = *it;
			if(cmp.y2 > segs[i].y2){ // i is inside of cmp
				adj[segs[i].id].pb(cmp.id);
			}
		}
		
		st.insert(aux);
	}
	
	printf("%d\n", ans);


 
    return 0;
}
