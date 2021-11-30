// Author: Gustavo Policarpo
// Name: Bibika's Inventions
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2853

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;


int n, m;
char mat[1010][1010];
int vis[1010][1010][5];
queue <iii> q;
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

void solve(){
	
	memset(vis, 0x3f3f3f3f, sizeof vis);
	
	rep(i, 0, n) rep(j, 0, m){
		if(mat[i][j]=='@'){
			q.push(iii(ii(i, j), ii(0, 4)));
			vis[i][j][4] = 0;
		}
	}
	
	while(!q.empty()){
		int x = q.front().F.F, y = q.front().F.S, c = q.front().S.F, t = q.front().S.S; q.pop();
		if(t==4){
			rep(i, 0, 4){
				int ax = x+dx[i], ay = y+dy[i];
				if(ax>=0 && ax<n && ay>=0 && ay<m && vis[ax][ay][i]>c+1){
					vis[ax][ay][i] = c+1;
					q.push(iii(ii(ax, ay), ii(c+1, i)));
				}
			}
		}else{
			int ax = x+dx[t], ay = y+dy[t];
			if(ax>=0 && ax<n && ay>=0 && ay<m && vis[ax][ay][t]>c+1){
				vis[ax][ay][t] = c+1;
				q.push(iii(ii(ax, ay), ii(c+1, t)));
			}
		}
		
	}
	
	int ans = 0;
	rep(i, 0, n) rep(j, 0, m){
		int aux = 0x3f3f3f3f;
		rep(k, 0, 5) aux = min(aux, vis[i][j][k]);
		ans = max(ans, aux);
	}
	
	if(ans>=0x3f3f3f3f) ans = -1;
	cout << ans << '\n';
	
}
int main(){
    
    scanf("%d %d", &n, &m);
    rep(i, 0, n) scanf("%s", mat[i]);
    solve();
	
    return 0;
}  
