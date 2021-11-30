// Author: Gustavo Policarpo
// Name: Disjoint Water Supply
// Level: 7
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1493

#include <stdio.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

int adj[1010][1010];
int pd[1010][1010], pointer[1010];

int solve(int x, int y){
	if(x==y) return 0;
	else if(x==1) return 1;
	
	if(pd[x][y]!=-1) return pd[x][y];
	
	int ret=0, i;
	for( i=0; i<pointer[y]; i++ ){
		int u=x, v=adj[y][i];
		if(u<v) u=u+v, v=u-v, u=u-v;
		ret=solve(v, u);
		if(ret) break;
	}
	
	return pd[x][y]=ret;
	
}

int main()
{
	
	int u, v, i, j, n, m;
	
	while(scanf("%d %d", &n, &m) !=EOF){
		
		for( i=1; i<=n; i++ ){
			pointer[i]=0;
			for( j=1; j<=n; j++ ){
				adj[i][j]=0;
				pd[i][j]=-1;
			}
		}
		
		while(m--){
			scanf("%d %d", &u, &v);
			if(u<v) u=u+v, v=u-v, u=u-v;
			adj[u][pointer[u]++]=v;
		}
		
		int ans=n-1;
		
		for( i=2; i<=n; i++ )
		for( j=i+1; j<=n; j++ )
			ans+=solve(i, j);
			
		printf("%d\n", ans);
		
	}
	
	return 0;
	
}
