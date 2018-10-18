// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Garoto Ixpertinho
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2490

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

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, ii > iii;

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

vector <iii> edg;
int pset[1010];

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
int main()
{
	
	int n, m; double t;
	while(scanf("%d %d %lf", &n, &m, &t)!=EOF and n+m){
		edg.clear();
		rep(i, 1, n+1) pset[i]=i;
		
		int u, v; double c;
		rep(i, 0, m){
			scanf("%d %d %lf", &u, &v, &c);
			edg.pb(mp(c, mp(u, v)));
		}
		
		sort(edg.begin(), edg.end());
		
		double ans=0.0; int cnt=0;
		
		rep(i, 0, m){
			u=edg[i].S.F,
			v=edg[i].S.S,
			c=edg[i].F;
 			if(!sameset(u, v)){
				unionset(u, v);
				ans+=c;
				if(c>t) ans+=2.0, cnt++;
			}
		}
		
		printf("%.2lf %d\n", ans, cnt);
		
	}
	

	return 0;
	
}
