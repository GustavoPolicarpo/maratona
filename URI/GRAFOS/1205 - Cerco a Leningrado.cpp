// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cerco a Leningrado
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1205

#include<bits/stdc++.h>
//#define gc getchar_unlocked


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
typedef pair < int, double > ii;
typedef pair < int, ii > iii;

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/

//
//

int N, M, K, A, O, D, a[1001];
double P, p[1001], aa[1001];
vector <int> adj[1001];

double bfs(){
	queue <iii> q;
	double aux=1.0; int bala=K;
	aux*=aa[O];
	q.push(mp(O, mp(bala, aux))); p[O]=aux;
	while(!q.empty()){
		int u=q.front().F, b=q.front().S.F; double c=q.front().S.S; q.pop();
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			aux=aa[v]; bala=b-a[v];
			if(p[v]>c*aux-error || bala<=0) continue;
			p[v]=c*aux;
			q.push(mp(v, mp(bala, p[v])));
		}
	}
	return p[D];
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(scanf("%d %d %d %lf", &N, &M, &K, &P) !=EOF){
		rep(i, 1, N+1){
			a[i]=0, aa[i]=1.0, p[i]=0.0, adj[i].clear();
		}
		int u, v;
		rep(i, 0, M){
			cin >> u >> v;
			adj[u].pb(v), adj[v].pb(u);
		}
		cin >> A;
		rep(i, 0, A){
			cin >> u;
			a[u]++;
		}
		rep(i, 1, N+1){
			rep(j, 0, a[i]){
				aa[i]*=P;	
			}
		}
		cin >> O >> D;
		double out=bfs();
		printf("%.3lf\n", out);
	}

return 0;
}



