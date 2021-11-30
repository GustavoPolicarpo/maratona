// Author: Gustavo Policarpo
// Name: Hotel Booking
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1640

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3f3f3f3f

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < ii, int > iii;

int n, h, m, cnt;
int hotel[10010], dst[105][105], dist[105][606], daux[10010];
vector <int> hh;
vector <ii> adj[10010], newadj[105];

void init(){
	rep(i, 1, n+1){
		hotel[i]=0;
		adj[i].clear();
	}
	rep(i, 0, h+4){
		rep(j, 0, h+4) dst[i][j]=INF;
		rep(j, 0, 604) dist[i][j]=INF;
		newadj[i].clear();
	}
	
	hh.clear();
}

void build_dst(int ini){
	
	rep(i, 1, n+1) daux[i]=INF;
	priority_queue <ii> pq;
	pq.push(mp(0, ini));
	daux[ini]=0;
	
	while(!pq.empty()){
		int u=pq.top().S, c=-pq.top().F; pq.pop();
		
		if(c>600) break;
		
		if(daux[u] < c) continue;
		
		if(hotel[u]) dst[hotel[ini]][hotel[u]]=c, newadj[hotel[ini]].pb(mp(hotel[u], c));
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F,
				cc=adj[u][i].S;
			if(daux[v]<=c+cc) continue;
			daux[v]=c+cc;
			pq.push(mp(-daux[v], v));
		}
		
	}
}

int dijsktra(){
	priority_queue <iii> pq;
	pq.push(mp(mp(0, 0), 0)); dist[0][0]=0;
	
	while(!pq.empty()){
		
		int u=pq.top().S, c=-pq.top().F.F, t=-pq.top().F.S; pq.pop();
		
		if(u==cnt) return c;
		
		rep(i, 0, newadj[u].size()){
			int v=newadj[u][i].F,
				cc=newadj[u][i].S;
			
			if(t+cc>600) continue;
			
			if(dist[v][t+cc]>c){
				dist[v][t+cc]=c;
				pq.push(mp(mp(-c, -(t+cc)), v));
			}
			
			if(dist[v][0]>c+1){
				dist[v][0]=c+1;
				pq.push(mp(mp(-(c+1), 0), v));
			}
			
		}
	}
	
	return -1;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int a, b, t;
	while(scanf("%d", &n) and n){
		
		scanf("%d", &h); init();
		
		hh.pb(1); hotel[1]=cnt=0; cnt++;
		rep(i, 0, h){
			scanf("%d", &a);
			hh.pb(a);
			if(hotel[a] || a==1) continue;
			hotel[a]=cnt++;
		}
		
		hotel[n]=cnt;
		
		scanf("%d", &m);
		rep(i, 0, m){
			scanf("%d %d %d", &a, &b, &t);
			adj[a].pb(mp(b, t));
			adj[b].pb(mp(a, t));
		}
		
		rep(i, 0, cnt) build_dst(hh[i]);
		
		/*rep(i, 0, cnt){
			//if(!newadj[i].size()) continue;
			cout << i << " : ";
			rep(j, 0, newadj[i].size())
				cout << newadj[i][j].F << " ";
			cout << '\n';
		}*/
		
		printf("%d\n", dijsktra());
		
	}
    
    return 0;
    
}
