// Author: Gustavo Policarpo
// Name: Bacterial Domination
// Level: 7
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2687

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define pb push_back
#define F first
#define S second

using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;


int mat[1010][1010];
int N, vis[1010][1010];
int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};

bool dentro(int x, int y){
	return x>=0 && x<=N+1 && y>=0 && y<=N+1 && !vis[x][y] && mat[x][y]==0;
}
void dfs(int x, int y){
	if(vis[x][y]) return; vis[x][y] = 1;
	rep(i, 0, 4){
		int ax=x+dx[i], ay=y+dy[i];
		if(!dentro(ax, ay)) continue;
		dfs(ax, ay);
	}
	return;
}

int main(){
	
	int T; cin >> T;
	
	while(T--){
		cin >> N;
		rep(i, 1, N+1) rep(j, 1, N+1) cin >> mat[i][j];
		memset(vis, 0, sizeof vis); dfs(0, 0);
		double a = 0, b = 0;
		rep(i, 1, N+1){
			rep(j, 1, N+1){
				if(mat[i][j]==1) a++;
				else if(!vis[i][j]) b++;
			}
		}
		printf("%.2lf\n", (a+b)/2.0);
	}	
	
	return 0;
}
