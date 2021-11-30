// Author: Gustavo Policarpo
// Name: Routers
// Level: 3
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1774

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

vector <iii> ligas;
int pset[61];

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
	int R, C;
	scanf("%d %d", &R, &C);
	rep(i, 1, R+1) pset[i]=i;
	int V, W, P;
	rep(i, 0, C){
		scanf("%d %d %d", &V, &W, &P);
		ligas.pb(mp(P, mp(V, W)));	
	}
	sort(ligas.begin(), ligas.end());
	
	int x, y, c, mst=0;
	rep(i, 0, ligas.size()){
		x=ligas[i].second.first;
		y=ligas[i].second.second;
		c=ligas[i].first;
		if(!sameset(x, y)){
			unionset(x, y);
			mst+=c;
		}
	}
	printf("%d\n", mst);

return (0);
}
