// Author: Gustavo Policarpo
// Name: Dabriel's Graph
// Level: 7
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2768

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<ii,ii> iii;


int N, M, Q;
int mat[101][101];

int main(){
	
	while(cin >> N >> M){
		
		rep(i, 1, N+1) rep(j, 1, N+1) mat[i][j] = (i==j?0:0x3f3f3f3f);
		
		int u, v, c;
		rep(i, 0, M){
			scanf("%d %d %d", &u, &v, &c);
			mat[u][v] = mat[v][u] = min(mat[u][v], c);
		}
		
		cin >> Q; vector <iii> query; int ans[Q];
		rep(i, 0, Q){
			scanf("%d %d %d", &u, &v, &c);
			query.pb(iii(ii(c, i), ii(u, v)));
		}
		
		sort(query.begin(), query.end());
		
		int at = 1;
		rep(i, 0, Q){
			int go = query[i].F.F, id = query[i].F.S, u = query[i].S.F, v = query[i].S.S;
			rep(k, at, go+1)
			rep(i, 1, N+1)
			rep(j, 1, N+1)
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			at = go+1;
			ans[id] = mat[u][v];
		}
		
		rep(i, 0, Q) printf("%d\n", (ans[i]>=0x3f3f3f3f ? -1 : ans[i]) );
		
	}
	
	return 0;
}
