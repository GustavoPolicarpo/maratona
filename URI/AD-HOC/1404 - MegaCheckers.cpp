// Author: Gustavo Policarpo
// Name: MegaCheckers
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1404

#include <bits/stdc++.h>

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
typedef pair<int,int> ii;


int mat[22][22], N, M;
int dx[]={-1, -1, 1, 1}, dy[]={-1, 1, -1, 1};

bool go1(int x, int y){
	return x>=1 && y>=1 && x<=N && y<=M && mat[x][y]==2;
}
bool go2(int x, int y){
	return x>=1 && y>=1 && x<=N && y<=M && mat[x][y]==0;
}

int solve(int x, int y){
	int ret=0;
	rep(i, 0, 4){
		int ax=x+dx[i], ay=y+dy[i];
		if(go1(ax, ay) && go2(ax+dx[i], ay+dy[i])){
			mat[ax][ay]=0;
			ret=max(ret, solve(ax+dx[i], ay+dy[i])+1);
			mat[ax][ay]=2;
		}
	}
	return ret;
}

int main(){

	while(scanf("%d %d",&N, &M) !=EOF){
		if(!N && !M) break;
		
		memset(mat, 0, sizeof mat); int aux, c=0;
		
		for(int i=N; i>=1; i--){
			for(int j=1+c; j<=M; j+=2){
				scanf("%d", &mat[i][j]);
			}	c=1-c;
		}
		
		/*rep(i, 1, N+1){
			rep(j, 1, M+1)
				cout << mat[i][j];
			cout << '\n';
		}*/
		
		int ans=0;
		rep(i, 1, N+1) rep(j, 1, M+1) if(mat[i][j]==1){
			mat[i][j]=0;
			ans=max(ans, solve(i, j));
			mat[i][j]=1;
		}
		
		cout << ans << '\n';
		
	}

	return 0;
}	
