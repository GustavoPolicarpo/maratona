// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Back to the Future
// Nível: 6
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1447

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < ll, int > iii;

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

const int MAX = 110;
const int INF = 0x3f3f3f3f;

int edg[MAX][MAX], source, sink, N, M, A, K, pai[MAX], dist[MAX];

int bellman(){
	
	rep(i, 1, N+1) dist[i]=INF; dist[source]=0;
	
	rep(i, 1, N)
	rep(u, 1, N+1)
	rep(v, 1, N+1){
		if(edg[u][v]==INF) continue;
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
		edg[pai[u]][u]=INF;
		edg[u][pai[u]] = -edg[u][pai[u]];
		u=pai[u];
	}
	
	return;
	
}

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int z=1, out;
	while(scanf("%d %d", &N, &M) !=EOF){
		
		rep(i, 1, N+1){
			rep(j, 1, N+1)
				edg[i][j]=INF;
		}
			
		int u, v; ll c;
		rep(i, 0, M){
			scanf("%d %d %d", &u, &v, &c);
			edg[u][v]=edg[v][u]=c;
		}
		
		scanf("%d %d", &A, &K);
		
		source=1; sink=N, out=0;
		
		while(A>0){
			int custo=bellman();
			if(custo >= INF){
				out=-1;
				break;
			}
			rec_path();
			out = out + min(A, K)*custo;
			A-=K;
		}
		
		printf("Instancia %d\n", z++);
		if(out==-1) puts("impossivel");
		else printf("%d\n", out);
		printf("\n");
		
	}
	
	return 0;
	
}
