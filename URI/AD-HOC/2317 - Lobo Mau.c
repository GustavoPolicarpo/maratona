// Author: Gustavo Policarpo
// Name: Lobo Mau
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2317

#include <stdio.h>
#define gc getchar
#define pc(x) putchar(x);

int scanint()
{
	int x=0;
    register int ccc = gc();
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    return x;
}

int r, c, vis[260][260], l=0, o=0;
int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};
char mat[260][260];

int dentro(int x, int y){
	return x>=0 && y>=0 && x<=r+1 && y<=c+1 && mat[x][y]!='#' && !vis[x][y];
}

void dfs(int x, int y){
	if(vis[x][y]) return;
	vis[x][y]=1;
	
	if(mat[x][y]=='v') l++;
	if(mat[x][y]=='k') o++;
	
	int i;
	for( i=0; i<4; i++ ){
		int ax=x+dx[i], ay=y+dy[i];
		if(!dentro(ax, ay)) continue;
		dfs(ax, ay);
	}
}
int main()
{
	scanf("%d %d", &r, &c);
	int i, j;
	for( i=1; i<=r; i++ ){
		for( j=1; j<=c; j++ ){
			scanf(" %c", &mat[i][j]);
		}
	}
	
	dfs(0, 0);
	
	int v=0, k=0;
	for( i=1; i<=r; i++ ){
		for( j=1; j<=c; j++ ){
			if(!vis[i][j] && mat[i][j]!='#'){
				l=0, o=0;
				dfs(i, j);
				if(l>=o) v+=l;
				else k+=o;
			}
		}
	}
	
	printf("%d %d\n", k, v);
	
	return 0;
		
}
