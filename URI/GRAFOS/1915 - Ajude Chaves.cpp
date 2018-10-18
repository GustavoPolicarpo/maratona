// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ajude Chaves
// Nível: 7
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1915

#include<bits/stdc++.h>

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
#define error 1e-12

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

vector <int> adj[101];
int match[202];
int vis[101];

int aug(int v)
{
	if(vis[v]==1) return 0;
	vis[v]=1;
	rep(i, 0, adj[v].size()){
		int u=adj[v][i];
		if(match[u]==-1 || aug(match[u])){
			match[u]=v;
			return 1;
		}
	}
	return 0;
}

int N, M, pd[101][101], pessoa[101][101], tamp[101], brinquedo[101][101], tamb[101];
int pp, bb;
int solve(int i, int j)
{
	if(i==tamp[pp] || j==tamb[bb]) return 0;
	if(pd[i][j]!=-1) return pd[i][j];
	
	int ret=0;
	if(pessoa[pp][i]==brinquedo[bb][j]){
		ret=solve(i+1, j+1)+1;
	}
	else{
		ret=max(solve(i+1, j), solve(i, j+1));
	}
	
	return pd[i][j]=ret;
		
}
int main()
{
	while(scanf("%d %d", &N, &M) and N+M){
		char in[101];
		rep(i, 0, N){ adj[i].clear();
			int vet[30]; memset(vet, 0, sizeof vet);
			scanf("%s", &in); int tam=strlen(in); tamp[i]=tam;
			rep(j, 0, tam){
				int aux=in[j]-'A';
				pessoa[i][j]=aux+26*vet[aux]+1; vet[aux]++;
				//cout << pessoa[i][j] << endl;
			}
		}
		rep(i, 0, M){
			int vet[30]; memset(vet, 0, sizeof vet);
			scanf("%s", &in); int tam=strlen(in); tamb[i]=tam;
			rep(j, 0, tam){
				int aux=in[j]-'A';
				brinquedo[i][j]=aux+26*vet[aux]+1; vet[aux]++;
				//cout << brinquedo[i][j] << endl;
			}
		}
		rep(i, 0, N)
		rep(j, 0, M){
			memset(pd, -1, sizeof pd);
			pp=i, bb=j;
			int ans=solve(0, 0);
			int tira1=tamp[pp]-ans, tira2=tamb[bb]-ans;
			if((tira1+tira2)%5==0){
				adj[i].pb(N+j);
			}
		}
		memset(match, -1, sizeof match);
		int mcbm=0;
		rep(i, 0, N){
			rep(j, 0, N+1)
				vis[j]=0;
			mcbm+=aug(i);
		}
	//	cout << mcbm << endl;
		double maximun=mcbm*100;
		maximun/=double(N);
		printf("P = %.2lf\n", maximun);
	}
			
return 0;
}
