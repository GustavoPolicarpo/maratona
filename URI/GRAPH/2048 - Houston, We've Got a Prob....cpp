// Author: Gustavo Policarpo
// Name: Houston, We've Got a Prob...
// Level: 6
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2048

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < double, ii > iii;



//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int pset[101];
vector <iii> edg;

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
int main()
{
	int n, m, z=1;
	while(scanf("%d %d", &n, &m) and n){
		
		rep(i, 1, n+1) pset[i]=i; edg.clear();
		
		int u, v; double p;
		rep(i, 0, m){
			scanf("%d %d %lf", &u, &v, &p);
			edg.pb(mp(p, mp(u, v)));
		}
		
		sort(edg.begin(), edg.end());
		
		double ans=1.0;
		rep(i, 0, m){
			u=edg[i].S.F,
			v=edg[i].S.S,
			p=edg[i].F;
			if(!sameset(u, v)){
				unionset(u, v);
				ans*=(1.0-p);
			}
		}
		
		if(z-1) printf("\n");
		printf("Instancia %d\n", z++);
		printf("%.5lf\n", 1.0-ans);
		
	}

	return 0;
}
