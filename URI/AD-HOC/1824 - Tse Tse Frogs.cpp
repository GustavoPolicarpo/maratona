// Author: Gustavo Policarpo
// Name: Tse Tse Frogs
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1824

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define F first
#define S second
#define pb push_back

typedef long long int ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const int MAX=1000010;



int n, m, mat[1010][1010], vis[1010][1010];
int dx[]={0, -1, -1, 0, 1, 1, 1, 0, -1}, 
	dy[]={0, 0, 1, 1, 1, 0, -1, -1, -1};

bool go(int x, int y){
	return x>=0 && y>=0 && x<n && y<m && !vis[x][y];
}

bool solve(){
	int x=0, y=0, cnt=n*m-1; vis[0][0]=1;
	if(cnt<0) return true;
	
	while(cnt--){
		int ax=x+dx[mat[x][y]], ay=y+dy[mat[x][y]];
		if(!go(ax, ay)) return false;
		x=ax, y=ay, vis[x][y]=1;
		//cout << x << " " << y << '\n';
	}
	
	return true;
	
}
int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int z=1;
	while(scanf("%d %d", &n, &m) and n+m){
		
		rep(i, 0, n) rep(j, 0, m) scanf("%d", &mat[i][j]), vis[i][j]=0;
		
		printf("Instancia %d\n", z++);
		solve() ? puts("sim") : puts("nao");
		printf("\n");
		
	}
	
	return 0;
	
}
