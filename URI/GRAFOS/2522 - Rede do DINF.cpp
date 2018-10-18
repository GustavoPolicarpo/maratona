// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Rede do DINF
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2522

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> ii;
typedef pair <double, ii> iii;

double dst(ii a, ii b){
	return sqrt((a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S));
}

int pset[505];

int findset(int x){
	if(pset[x]!=x) pset[x]=findset(pset[x]);
	return pset[x];
}
void unionset(int x, int y){
	x=findset(x), y=findset(y);
	pset[x]=y;
}
bool sameset(int x, int y){
	return findset(x)==findset(y);
}


int main(){
	
	int n;
	
	while(scanf("%d", &n) !=EOF){
		
		vector <ii> v; ii aux;
		rep(i, 0, n){
			scanf("%d %d", &aux.F, &aux.S);
			pset[i]=i;
			v.pb(aux);
		}
		
		vector <iii> edg;
		rep(i, 0, n){
			rep(j, i+1, n){
				edg.pb(mp(dst(v[i], v[j]), mp(i, j)));
			}
		}
		
		sort(edg.begin(), edg.end());
		
		double ans=0;
		rep(i, 0, edg.size()){
			int u=edg[i].S.F,
				v=edg[i].S.S;
			double c=edg[i].F;
			if(!sameset(u, v)){
				unionset(u, v);
				ans+=c;
			}
		}
		
		printf("%.2lf\n", ans);
		
	}
	
	
	return 0;
	
}
