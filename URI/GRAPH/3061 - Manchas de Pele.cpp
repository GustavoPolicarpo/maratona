// Author: Gustavo Policarpo
// Name: Manchas de Pele
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3061

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
typedef pair <int, int> ii;

const int MAX = 2e3+3;
const int mod = 1e9+7;

int n, m;
int mat[1010][1010];
int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};
int vis[1010][1010];

void dfs(int x, int y, int c){
	if(x<0 || y<0 || x>=n || y>=m || !mat[x][y]) return;
	if(vis[x][y]) return; vis[x][y] = c;
	rep(i, 0, 4) dfs(x+dx[i], y+dy[i], c);
}

int main(){
	
	scanf("%d %d", &n, &m);
	rep(i, 0, n) rep(j, 0, m) scanf("%d", &mat[i][j]);
	int ans = 0;
	rep(i, 0, n) rep(j, 0, m){
		if(mat[i][j] && !vis[i][j]){
			dfs(i, j, ++ans);
		}
	}
	printf("%d\n", ans);
	
    return 0;
}
