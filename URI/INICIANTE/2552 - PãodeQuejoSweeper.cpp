// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: PãodeQuejoSweeper
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2552

# include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define repi(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define pb push_back
#define mp make_pair
#define INF 0x3F3F3F3F
#define pi 3.1415926535897932384626433832795028841971
#define F first
#define S second
#define MAXV 200010

typedef long long ll;
typedef pair < int, int>  ii;
typedef pair < int, pair<int,int> >  iii;

// freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};
int n, m, mat[111][111], ans[111][111];

bool dentro(int x, int y){
	return x>=0 && y>=0 && x<n && y<m && mat[x][y]==1;
}

int main(){
	
	while(scanf("%d %d", &n, &m) !=EOF){
		
		rep(i, 0, n) rep(j, 0, m) scanf("%d", &mat[i][j]);
		
		rep(i, 0, n){
			rep(j, 0, m){
				if(mat[i][j]==1){
					ans[i][j]=9;
					continue;
				}
				int cnt=0;
				rep(k, 0, 4){
					int ax=i+dx[k], ay=j+dy[k];
					if(dentro(ax, ay)) cnt++;
				}
				ans[i][j]=cnt;
			}
		}
		
		rep(i, 0, n){
			rep(j, 0, m)
				printf("%d", ans[i][j]);
			printf("\n");
		}
	}
	
	return 0;
}

