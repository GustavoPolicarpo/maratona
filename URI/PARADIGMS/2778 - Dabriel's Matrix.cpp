// Author: Gustavo Policarpo
// Name: Dabriel's Matrix
// Level: 10
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2778

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

	
int N, M, X, Y;
int mat[100][100], cnt = 1;
int mark[100][100][21][21][2];
int pd[100][100][21][21][2];

int dx[] = {0, 0},
	dy[] = {-1, 1};
	
inline int solve(int x, int y, int qx, int qy, int ld){
	if(qx<0 || qy<0) return 0x3f3f3f3f;
	if(x==0 && y==0) return 0;
	if(mark[x][y][qx][qy][ld]==cnt) return pd[x][y][qx][qy][ld];
	mark[x][y][qx][qy][ld] = cnt;
	
	int ret = 0x3f3f3f3f;
	if(x>0){
		ret = min(ret, solve(x-1, y, qx-(mat[x-1][y]==0), qy-(mat[x-1][y]<0), 0)+mat[x-1][y]);
		ret = min(ret, solve(x-1, y, qx-(mat[x-1][y]==0), qy-(mat[x-1][y]<0), 1)+mat[x-1][y]);
	}
	rep(k, 0, 2){
		if(k!=ld) continue;
		int ay = y+dy[k];
		if(ay<0 || ay>=M) continue;
			ret = min(ret, solve(x, ay, qx-(mat[x][ay]==0), qy-(mat[x][ay]<0), k)+mat[x][ay]);
	}
	
	return pd[x][y][qx][qy][ld] = ret;
}

int main(){
	
	while(scanf("%d %d %d %d", &N, &M, &X, &Y)!=EOF){
		rep(i, 0, N) rep(j, 0, M){
			scanf("%d", &mat[i][j]);
		}
		cnt++; int ans = solve(N-1, M-1, X-(mat[N-1][M-1]==0), Y-(mat[N-1][M-1]<0), 0)+mat[N-1][M-1];
		if(ans>=0x3f3f3f3f-100*100*100) puts("Impossivel");
		else printf("%d\n", ans);
	}
	
}
