// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sistema Cipoviário
// Nível: 6
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2127

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

int V, N, M, pset[1005];
vector <iii> edg;

int findset(int x)
{
	if(pset[x]!=x)
		pset[x]=findset(pset[x]);
	return pset[x];
}

void unionset(int x, int y)
{
	x=findset(x); y=findset(y);
	if(x==y) return;
	pset[x]=y;
}

bool sameset(int x, int y)
{
	return findset(x) == findset(y);
}

int main()
{
	int z=1, u, v, c;
	while(scanf("%d %d", &N, &M) !=EOF ){
		rep(i, 0, M){
			scanf("%d %d %d", &u, &v, &c);
			edg.pb( mp(c, mp(u,v) ) );
		}
		sort(edg.begin(), edg.end());
		
		rep(i, 0, N+1) pset[i]=i;
		
		ll mst=0;
		rep(i, 0, M){
			iii aux= edg[i];
			u=aux.S.F, v=aux.S.S, c=aux.F;
			
			if(!sameset(u, v)){
				unionset(u, v);
				mst+=c;
			}
		}
		
		printf("Instancia %d\n%lld\n\n", z++, mst);
		edg.clear();
		
	}
		
return 0;
}
