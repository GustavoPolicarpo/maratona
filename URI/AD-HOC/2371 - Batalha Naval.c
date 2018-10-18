// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Batalha Naval
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2371

#include <stdio.h>

int n, m, vis[111][111], yep;
char mat[111][111];

int dx[]={-1, 0, 0, 1},
	dy[]={0, -1, 1, 0};
int dentro(int x, int y){
	return x>=0 && y>=0 && x<n && y<m;
}

void dfs(int x, int y){
	int i;
	for( i=0; i<4; i++ ){
		int ax=x+dx[i], ay=y+dy[i];
		if(!dentro(ax, ay)) continue;
		if(mat[ax][ay]=='.') continue;
		if(vis[ax][ay]==2) continue;
		if(vis[ax][ay]==0){
			yep=0;
			return;
		}
		vis[ax][ay]=2;
		dfs(ax, ay);
	}
	return;
}

int main()
{
	
	scanf("%d %d ", &n, &m);
	int u, v, i, j, qt;
	
	for( i=0; i<n; i++ ) scanf("%s", mat[i]);
	
	scanf("%d", &qt);
	
	while(qt--){
		scanf("%d %d", &u, &v);
		u=u-1, v=v-1;
		vis[u][v]=1;
	}
	
	int ans=0;
	for( i=0; i<n; i++ ){
		for( j=0; j<m; j++ ){
			if(mat[i][j]=='#' && vis[i][j]==1){
				yep=1;
				dfs(i, j);
				ans+=yep;
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
		
}
