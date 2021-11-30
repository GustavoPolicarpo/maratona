// Author: Gustavo Policarpo
// Name: Lazy Jumping Frog
// Level: 7
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1384

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
 
#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;
 
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
 
int dx[]={-2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}, 
	dy[]={-2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2},
	ct[]={7, 6, 5, 6, 7, 6, 3, 2, 3, 6, 5, 2, 2, 5, 6, 3, 2, 3, 6, 7, 6, 5, 6, 7};

int mat[1010][1010], dist[1010][1010], N, M, W;
ii ini, fim;

bool go(int x, int y){
	return x>0 && y>0 && x<N && y<M && mat[x][y];
}
int solve(){
	
	priority_queue <iii> pq;
	pq.push(mp(0, ini)); dist[ini.F][ini.S]=0;
	
	while(!pq.empty()){
		ii u=pq.top().S; int c=-pq.top().F; pq.pop();
		
		if(u==fim) return c;
		
		rep(i, 0, 24){
			int ax=u.F+dx[i], ay=u.S+dy[i];
			if(!go(ax, ay)) continue;
			if(dist[ax][ay] <= c+ct[i]) continue;
			dist[ax][ay] = c+ct[i];
			pq.push(mp(-dist[ax][ay], mp(ax, ay)));
		}
	}
	
	return -1;
	
}
int main()
{
	while(scanf("%d %d", &N, &M) and N){
		N++, M++;
		rep(i, 1, N) rep(j, 1, M) mat[i][j]=1, dist[i][j]=INF;
		scanf("%d %d %d %d %d", &ini.F, &ini.S, &fim.F, &fim.S, &W);
		
		ii a, b;
		while(W--){
			scanf("%d %d %d %d", &a.F, &a.S, &b.F, &b.S);
			rep(i, a.F, b.F+1) rep(j, a.S, b.S+1) mat[i][j]=0;
		}
		
		/*mat[ini.F][ini.S]=2, mat[fim.F][fim.S]=3;
		rep(i, 1, N){
			rep(j, 1, M)
				cout << mat[i][j];
			cout << '\n';
		}*/
		int aux=solve();
		
		printf( aux == -1 ? "impossible\n" : "%d\n", aux);
	}
	
	return 0;
	
}
