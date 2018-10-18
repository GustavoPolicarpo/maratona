// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Novo Campus
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2550

# include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define repi(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define pb push_back
#define mp make_pair
#define INF 0x3F3F3F3F
#define pi 3.1415926535897932384626433832795028841971
#define F first
#define S second
#define MAXV 200010

typedef long long ll;
typedef pair < int, int>  ii;
typedef pair < int, ii >  iii;

// freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


vector <iii> edg;
int pset[1010];

int findset(int x){
	if(x!=pset[x]) pset[x]=findset(pset[x]);
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
	
	int n, m;
	while(scanf("%d %d", &n, &m)!=EOF){
		
		rep(i, 0, n+2) pset[i]=i; edg.clear();
		int u, v, c;
		
		rep(i, 0, m){
			scanf("%d %d %d", &u, &v, &c);
			edg.pb(iii(c, ii(u, v)));
		}
		
		sort(edg.begin(), edg.end());
		
		int ans=0;
		rep(i, 0, edg.size()){
			u=edg[i].S.F,
			v=edg[i].S.S,
			c=edg[i].F;
			if(!sameset(u, v)){
				unionset(u, v);
				ans+=c;
			}
		}
		
		int group=findset(1);
		rep(i, 1, n+1){
			if(findset(i)!=group){
				ans=-1;
				break;
			}
		}
		
		if(ans==-1) puts("impossivel");
		else printf("%d\n", ans);
		
	}
	
	return 0;
}

