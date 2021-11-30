// Author: Gustavo Policarpo
// Name: Rogerio's House
// Level: 10
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2002

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < ll, ii > iii;

const ll LINF = 1LL<<62;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int n, m, dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};
ll mat[101][101], dist[101][101];

bool dentro(int x, int y){
	return x>=0 && y>=0 && x<n && y<m;
}
ll ver(ll a){
	if(a%4==0) return a;
	if((a+1)%4==0) return 0;
	if((a-1)%4==0) return 1;
	return a+1;
}
ll go(ll a, ll b){
	if(a>b) swap(a, b);
	ll ret=ver(a-1)^ver(b);
	return ret;
}

ll solve(){
	
	int x=0, y=0, ax, ay; ll c=0;
	priority_queue <iii> pq;
	pq.push(mp(c, mp(x, y))); dist[x][y]=0;
	
	while(!pq.empty()){
		x=pq.top().S.F, y=pq.top().S.S, c=-pq.top().F; pq.pop();
		
		if(x==n-1 && y==m-1) return c;
		
		rep(i, 0, 4){
			ax=x+dx[i], ay=y+dy[i];
			if(!dentro(ax, ay)) continue;
			ll custo=go(mat[x][y], mat[ax][ay]);
			if(dist[ax][ay]<=c+custo) continue;
			
			dist[ax][ay]=c+custo;
			pq.push(mp(-dist[ax][ay], mp(ax, ay)));
		}
	}
	
}

int main()
{
	while(scanf("%d %d", &n, &m) !=EOF){
		rep(i, 0, n) rep(j, 0, m) dist[i][j]=LINF, scanf("%lld", &mat[i][j]);
		
		printf("%lld\n", solve());
	}
	
	return 0;
}
