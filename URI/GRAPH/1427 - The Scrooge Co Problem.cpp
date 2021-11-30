// Author: Gustavo Policarpo
// Name: The Scrooge Co Problem
// Level: 10
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1427

#include<bits/stdc++.h>
#define gc getchar_unlocked


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
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

/*
void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}
*/
vector <ii> adj[200];
int dist[200], pai[200];

int dijskatra(int O, int D){
	
	memset(dist, INF, sizeof dist);
	memset(pai, -1, sizeof pai);
	priority_queue <ii> pq; dist[O]=0;
	pq.push(mp(0, -O));
	
	while(!pq.empty()){
		
		int u=-pq.top().S, d=-pq.top().F; pq.pop();
		if(u==D) return d;
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F;
			int c=adj[u][i].S;
			if(dist[v]<=dist[u]+c) continue;
			dist[v]=dist[u]+c;
			pai[v]=u;
			pq.push(mp(-dist[v], -v));
		}
	}
	
	return dist[D];
}

int mat[100][100], dad[100][100];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T, N, R, aux; cin >> T;
	while(T--){
		string a, b, c; map<string, int> mapa;
						map<int, string> rec;
						
		scanf("%d", &N);
		
		rep(i, 0, N){
			cin >> a;
			rec[i]=a;
			//adj[i].clear();
			mapa[a]=i;
		}
		
		rep(i, 0, N){
			rep(j, 0, N){
				scanf("%d", &aux);
				if(aux==-1){
					mat[i][j]=INF;
				}
				else if(aux==0){
					mat[i][j]=0;
				}
				else mat[i][j]=aux;
				dad[i][j]=j;
				//adj[i].pb(mp(j, aux));
				//adj[j].pb(mp(i, aux));
			}
		}
		rep(k, 0, N)
		rep(i, 0, N)
		rep(j, 0, N){
			if(mat[i][j]>mat[i][k]+mat[k][j]){
				mat[i][j]=mat[i][k]+mat[k][j];
				dad[i][j]=dad[i][k];
			}
		}
			
		scanf("%d", &R);
		while(R--){
			cin >> c >> a >> b;
			int u=mapa[a], v=mapa[b];
			//int out=dijskatra(mapa[a], mapa[b]);
			if(mat[u][v]==INF){
				cout << "Sorry Mr " << c << " you can not go from "<< a << " to " << b << endl;
			}
			else{
				cout << "Mr " << c << " to go from " << a << " to " << b << 
				", you will receive " << mat[u][v] << " euros\n";
				
				//vector <string> goin;
				//int r=mapa[b];
				cout << "Path:" << a;
				if(u==v) cout << " " << a;
				while(u!=v){
					u=dad[u][v];
					cout << " " << rec[u];
					//goin.pb(rec[r]);
					//r=pai[r];
				}
				//reverse(goin.begin(), goin.end());
				
				//cout << "Path:";
				/*rep(i, 0, goin.size()){
					if(i>0) cout << " ";
					cout << goin[i];
				}
				if(goin.size()==1) cout << " " << goin[0];*/
				cout << endl;
			}
		}
	}

return 0;
}
