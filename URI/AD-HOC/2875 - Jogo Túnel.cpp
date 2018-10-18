// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Jogo Túnel
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2875

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int vis[101][101];
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
int N, M;
char mat[101][101];

void bfs(int x, int y){
	memset(vis, 0, sizeof vis);
	vector <ii> pos;
	queue <ii> q; q.push(ii(x, y)); vis[x][y] = 1;
	while(!q.empty()){
		x = q.front().F, y = q.front().S; q.pop();
		pos.pb(ii(x, y));
		rep(i, 0, 4){
			int ax = x+dx[i], ay = y+dy[i];
			if(ax>=0 && ay>=0 && ax<N && ay<M && mat[ax][ay]=='0' && !vis[ax][ay]){
				vis[ax][ay] = 1;
				q.push(ii(ax, ay));
			}
		}
	}
	int d = 1, p = 0; x = pos[0].F, y = pos[0].S;
	while(p<pos.size()-1){
		if(pos[p].F+dx[d]==pos[p+1].F && pos[p].S+dy[d]==pos[p+1].S){
			cout << "F ";
			p++;
			continue;
		}
		int d1 = (d+1)%4;
		if(pos[p].F+dx[d1]==pos[p+1].F && pos[p].S+dy[d1]==pos[p+1].S){;
			cout << "L ";
			d = d1;
			continue;
		}
		int d2 = (d-1+4)%4;
		if(pos[p].F+dx[d2]==pos[p+1].F && pos[p].S+dy[d2]==pos[p+1].S){;
			cout << "R ";
			d = d2;
			continue;
		}
	}
	
	cout << "E\n";
}

int main(){
	
	
	while(cin >> N >> M){
		rep(i, 0, N) rep(j, 0, M) cin >> mat[i][j];
		rep(i, 0, N) rep(j, 0, M){
			if(mat[i][j]=='X'){
				bfs(i, j);
			}
		}
	}
	
	return 0;
} 
