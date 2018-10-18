// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Apresse-se!
// Nível: 7
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1413

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

#define MAXV 100001
#define mod 1000000007
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;


const int MAX = 220;
const double INF = 1LL << 40;

int source, sink, N, M, A, K, pai[MAX]; 
double edg[MAX][MAX], dist[MAX], ans;

double dijsktra(){
	
	rep(i, 0, N + M*2 +2) dist[i]=INF; dist[source]=0;
	priority_queue <iii> pq; pq.push(mp(0, source));
	
	while(!pq.empty()){
		int u=pq.top().S; double c=-pq.top().F; pq.pop();
		
		//cout << u << " " << c << "\n";
		
		if(u==sink) return c;
		
		rep(v, 0, N + M*2 + 2 ){
			if(edg[u][v] >= INF - error) continue;
			if(dist[v] > dist[u] + edg[u][v] + error){
				dist[v] = dist[u] + edg[u][v];
				pai[v]=u;
				pq.push(mp(-dist[v], v));
			}
		}
	}
	
	return INF;
	
}

double bellman(){
	
	rep( i, 1, N + M*2 + 2 ) dist[i]=INF; dist[source]=0.0;
	
	rep(i, 0, N + M * 2 + 2)
	rep(u, 0, N + M * 2 + 2)
	rep(v, 0, N + M * 2 + 2){
		if(edg[u][v]==INF-error) continue;
		if(dist[v] > dist[u] + edg[u][v]){
			dist[v] = dist[u] + edg[u][v];
			pai[v]=u;
		}
	}
	
	return dist[sink];
	
}

void rec_path(){
	
	int u=sink;
	while(u!=source){
		edg[u][pai[u]] = -edg[pai[u]][u];
		edg[pai[u]][u]=INF;
		u=pai[u];
	}
	
	return;
	
}

struct nim{
	int x, y; double v;
	nim() {}
	
	nim(int x, int y, int v) : x(x), y(y), v(v) {}
	nim read(){
		scanf("%d %d %lf", &x, &y, &v);
		return nim(x, y, v);
	}
};

double dst(nim a, ll x, ll y){
	double ds=sqrt( (a.x-x)*(a.x-x) + (a.y-y)*(a.y-y) );
	return ds/a.v;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	while(scanf("%d %d", &N, &M) and N+M){
		
		rep(i, 0, N + M*2 + 3) rep(j, 0, N + M*2 + 3) edg[i][j]=INF;
		
		vector <nim> in; nim aux;
		rep(i, 0, N) in.pb(aux.read());
		
		rep(i, 0, M){
			int x, y, c;
			scanf("%d %d", &x, &y);
			while(scanf("%d", &c) and c){
				edg[c][N+i*2+1] = dst(in[c-1], x, y); // edg[N+i*2+1][c] = dst(in[c-1], x, y);
				edg[0][c] = 0; //edg[c][0] = 0;
				edg[N+i*2+1][N+i*2+2] = 0; // edg[N+i*2+2][N+i*2+1] = 0;
				edg[N+i*2+2][N+M*2+1] = 0; //edg[N+M*2+1][N+i*2+2] = 0;
			}
		}
		
		source=0, sink=N+M*2+1, ans=0.0;
		
		rep(i, 0, N){
			double custo=dijsktra();
			ans+=custo;
			rec_path();
		}
		
		printf("%.1lf\n", ans);
		
	}
	
	return 0;
	
}
