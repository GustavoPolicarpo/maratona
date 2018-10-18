// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fuga de Ayutthaya
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1883

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F3F3F3F
#define MAXV 100001

#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


int N, M, vis[1001][1001], dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};
char mat[1001][1001];

bool dentro(ii p){
	return p.F>=0 && p.S>=0 && p.F<N && p.S<M && mat[p.F][p.S]!='#';
}
bool bfs(ii p, int t){
	queue <iii> q;
	q.push(mp(t, p)); vis[p.F][p.S]=1;
	while(!q.empty()){
		t=q.front().F, p=q.front().S; q.pop();
		if(mat[p.F][p.S]=='F') return false;
		else if(mat[p.F][p.S]=='S'){
			while(!q.empty() && q.front().F==t){
				if(mat[q.front().S.F][q.front().S.S]=='F') return false;
				q.pop();
			}
			return true;
		}
		rep(i, 0, 4){
			ii aux; aux.F=p.F+dx[i], aux.S=p.S+dy[i];
			if(!dentro(aux) || vis[aux.F][aux.S]) continue;
			vis[aux.F][aux.S]=1;
			q.push(mp(t+1, aux));
		}
	}
	return false;
}
int main()
{
	int T; cin >> T;
	while(T--){
		
		scanf("%d %d", &N, &M); ii ini;
		rep(i, 0, N)
		rep(j, 0, M){
			scanf(" %c", &mat[i][j]);
			if(mat[i][j]=='E'){
				ini.F=i, ini.S=j;
			}
			vis[i][j]=0;
		}
		if(bfs(ini, 0)) puts("Y");
		else puts("N");
	}
    
    
    
return 0;

}
