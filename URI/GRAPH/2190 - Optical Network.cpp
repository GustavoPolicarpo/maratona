// Author: Gustavo Policarpo
// Name: Optical Network
// Level: 7
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2190

#define gc getchar_unlocked
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
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
vector <iii> edg;
vector <ii> out;
int N, M, pset[101];

int findset(int x){
	if(pset[x]!=x)
		pset[x]=findset(pset[x]);
	return pset[x];
}
void unionset(int x, int y){
	x=findset(x), y=findset(y);
	if(x==y) return;
	pset[x]=y;
}
bool sameset(int x, int y){
	return findset(x)==findset(y);
}
int main()
{
//	freopen("out.txt", "w", stdout);
	int z=1;
	while(scanf("%d %d", &N, &M) and N){
		edg.clear(), out.clear();
		rep(i, 1, N+1) pset[i]=i;
		int u, v, c;
		rep(i, 0, M){
			scanf("%d %d %d", &u, &v, &c);
			edg.pb(mp(c, mp(u, v)));
			//edg.pb(mp(c, mp(v, u)));
		}
		sort(edg.begin(), edg.end());
		printf("Teste %d\n", z++);
		rep(i, 0, edg.size()){
			u=edg[i].S.F, 
			v=edg[i].S.S; 
		//	c=edg[i].F;
			if(!sameset(u, v)){
				unionset(u, v);
				printf("%d %d\n", min(u, v), max(u, v));
			}
		}
		printf("\n");
	}
	
return 0;
}
