// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Cubo
// Nível: 6
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2056

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;

#define INF 0x3f3f3f3f
const int mod=1e9+7;

int R, C, vis[22][22][22][22];
char mat[22][22]; ii B, S, T;

struct use{
	ii b, s;
	int t, tb;
	bool operator() (use aa, use bb){
		if(aa.tb>bb.tb) return true;
		if(aa.tb<bb.tb) return false;
		if(aa.t>bb.t)	return true;
		return false;
	}	
};

int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};

bool dentro(ii go){
	return go.F>=0 && go.S>=0 && go.F<R && go.S<C && mat[go.F][go.S]!='#';
}

ii solve(){
	
	memset(vis, INF, sizeof vis); use u, aux;
	u.b=B, u.s=S, u.t=0, u.tb=0; vis[S.F][S.S][B.F][B.S]=0;
	priority_queue <use, vector <use>, use > q; q.push(u);
	
	while(!q.empty()){
		
		u=q.top(); q.pop();
		
		if(u.b==T) return ii(u.t, u.tb);
		
		rep(i, 0, 4){
			ii go=ii(u.s.F+dx[i], u.s.S+dy[i]);
			if(!dentro(go)) continue;
			
			if(go==u.b){
				ii gob=ii(u.b.F+dx[i], u.b.S+dy[i]);
				if(!dentro(gob)) continue;
				if(vis[go.F][go.S][gob.F][gob.S]==INF){
					vis[go.F][go.S][gob.F][gob.S]=1;
					aux.s=go, aux.b=gob, aux.t=u.t+1, aux.tb=u.tb+1;
					q.push(aux);
				}
			}else{
				if(vis[go.F][go.S][u.b.F][u.b.S]==INF){
					vis[go.F][go.S][u.b.F][u.b.S]=1;
					aux.s=go, aux.b=u.b, aux.t=u.t+1, aux.tb=u.tb;
					q.push(aux);
				}
			}
		}
		
	}
	
	return ii(INF, INF);
	
}

int main(){
	
	int teste=1;
	while(scanf("%d %d", &R, &C) and R){
		
		rep(i, 0, R){
			rep(j, 0, C){
				scanf(" %c", &mat[i][j]);
				if(mat[i][j]=='B') B=ii(i, j);
				else if(mat[i][j]=='T') T=ii(i, j);
				else if(mat[i][j]=='S') S=ii(i, j);
			}
		}
		
		if(teste-1) puts("");
		printf("Instancia %d\n", teste++);
		ii ans=solve();
		ans.F>=INF?puts("Impossivel"):printf("%d %d\n", ans.F, ans.S);
		
	}
	
	return 0;
	
}
