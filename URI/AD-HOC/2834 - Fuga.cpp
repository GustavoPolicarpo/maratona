// Author: Gustavo Policarpo
// Name: Fuga
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2834

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
 

int n, m, ans;
ii ini, fim;
int vis[7][7];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

void solve(int x, int y, int c){
	if(ii(x, y)==fim){
		ans = max(ans, c);
		return;
	}
	rep(i, 0, 4){
		int ax = x+dx[i], ay = y+dy[i];
		if(ax>=0 && ay>=0 && ax<=n && ay<=m && !vis[ax][ay]){
			vis[ax][ay] = 1;
			solve(ax, ay, c+2);
			vis[ax][ay] = 0;
		}
	}
	return;
}

int main(){
	
	cin >> n >> m; n = (n-1)/2, m = (m-1)/2;
	cin >> ini.F >> ini.S >> fim.F >> fim.S;
	ini.F = (ini.F-1)/2, ini.S = (ini.S-1)/2;
	fim.F = (fim.F-1)/2, fim.S = (fim.S-1)/2;
	vis[ini.F][ini.S] = 1; solve(ini.F, ini.S, 0);
	
	cout << ans+1 << '\n';
	
	
	return 0;
}  
