// Author: Gustavo Policarpo
// Name: The Infinity Gems
// Level: 7
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2838

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )

using namespace std;

struct use{
	int x, y, k, j, t;
};

int N, M, ix=-1, iy=-1;
char mat[55][55];
int vis[52][52][1<<5+2][1<<6+2];
int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};

bool cango(use u){
	return u.x>=0 && u.y>=0 && u.x<N && u.y<M && mat[u.x][u.y]!='#';
}

int pval(char c){
	if(c>='A' && c<='D') return c-'A';
	return -1;
}

int kval(char c){
	if(c>='a' && c<='d') return c-'a';
	return -1;
}

int jval(char c){
	if(c=='p') return 0;
	else if(c=='t') return 1;
	else if(c=='m') return 2;
	else if(c=='e') return 3;
	else if(c=='r') return 4;
	return -1;
}

void solve(){
	
	queue <use> q;
	q.push(use{ix, iy, 0, 0, 0});
	vis[ix][iy][0][0] = 1;
	
	while(!q.empty()){
		
		use u = q.front(); q.pop();
		
		if(__builtin_popcount(u.j)==5){
			cout << u.t << '\n';
			return;
		}
		
		rep(i, 0, 4){
			use go = u; go.t++;
			go.x += dx[i], go.y += dy[i];
			if(!cango(go)) continue;
			
			int valp = pval(mat[go.x][go.y]);
			if(valp!=-1 && !(go.k&(1<<valp))) continue;
			
			int valk = kval(mat[go.x][go.y]);
			if(valk!=-1) go.k|=(1<<valk);
			
			int valj = jval(mat[go.x][go.y]);
			if(valj!=-1) go.j|=(1<<valj);
			
			if(!vis[go.x][go.y][go.k][go.j]){
				vis[go.x][go.y][go.k][go.j] = 1;
				q.push(go);
			}
		}
	}
	
	puts("Gamora");
	return;
}

int main(){
	
	scanf("%d %d", &N, &M);
	rep(i, 0, N){
		scanf("%s", mat[i]);
		rep(j, 0, M) if(mat[i][j]=='T'){
			ix = i, iy = j;
		}
	}
		
	solve();
	
	return 0;
}
