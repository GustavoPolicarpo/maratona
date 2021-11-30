// Author: Gustavo Policarpo
// Name: Alice's Kingdom
// Level: 6
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2732

#pragma comment(linker, "/stack:200000000")                                     
#pragma GCC optimize("Ofast")                                                   
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")   
#define _CRT_SECURE_NO_WARNINGS          
#include <bits/stdc++.h>

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

typedef long long int ll;
typedef pair <int, int> ii;


int H, L;
char mat[404][404];
int vis[404][404], ans, qt;
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

void dfs(int x, int y){
	if(vis[x][y]) return; vis[x][y] = 1;
	qt++;
	rep(i, 0, 4){
		int ax = x+dx[i], ay = y+dy[i];
		if(ax>=0 && ay>=0 && ax<H && ay<L && mat[ax][ay]=='C')
			dfs(ax, ay);
	}
	return;
}

int main(){
	
	while(scanf("%d %d", &H, &L)!=EOF){
		rep(i, 0, H) rep(j, 0, L) cin >> mat[i][j];
		ans = 0;
		
		rep(i, 0, H){
			rep(j, 0, L){
				if(!vis[i][j]&&mat[i][j]=='C'){
					qt = 0;
					dfs(i, j);
					ans = max(ans, qt);
				}
			}
		}
		
		cout << ans << '\n';
	}
	
	
	
	return 0;
}
