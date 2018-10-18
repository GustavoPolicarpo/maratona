// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Viagens no Tempo
// Nível: 7
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2082

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

#define mod 1000000007
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

const int INF = 0x3f3f3f3f;
const int MAXV = 110;
int g[MAXV][MAXV], v[MAXV], w[MAXV], n, m;
bool a[MAXV];

int stoer_wagner(){
	
	rep(i, 0, n) v[i]=i;
	
	int best=INF;
	
	while(n>1){
		a[v[0]] = true;
		rep(i, 1, n){
			a[v[i]]=false;
			w[i]=g[v[0]][v[i]];
		}
		
		int prev = v[0];
		rep(i, 1, n){
			int zj=-1;
			rep(j, 1, n)
				if(!a[v[j]] && (zj<0 || w[j] > w[zj]))
					zj=j;
			
			a[v[zj]] = true;
			
			if(i==n-1){
				best=min(best, w[zj]);
				
				rep(j, 0, n)
					g[v[j]][prev]=g[prev][v[j]]+=g[v[zj]][v[j]];
				v[zj]=v[--n];
				break;
			}
			prev = v[zj];
			
			rep(j, 1, n)
				if(!a[v[j]])
					w[j]+=g[v[zj]][v[j]];
		}
	}
	
	return best;
	
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int T; cin >> T;
	
	while(T--){
		scanf("%d %d", &n, &m);

		int u, v, c, menor_aresta=INF;
		rep(i, 0, n + 1)
		rep(j, 0, n + 1)
			g[i][j]=0;
		
		rep(i, 0, m){
			scanf("%d %d %d", &u, &v, &c);
			u--, v--;
			g[u][v]=g[v][u]=c;
			if(c<menor_aresta) menor_aresta=c;
		}
		if(n-1 == m) printf("%d\n", menor_aresta);
		else printf("%d\n", stoer_wagner());
	}
	
	return 0;
	
}
