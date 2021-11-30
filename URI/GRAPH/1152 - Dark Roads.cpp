// Author: Gustavo Policarpo
// Name: Dark Roads
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1152

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

vector <iii> edg;
int N, M, pset[200001];

int findset(int x){
    if(x!=pset[x])
        pset[x]=findset(pset[x]);
    return pset[x];
}
void unionset(int x, int y){
    x=findset(x), y=findset(y);
    if(x==y) return;
    pset[y]=x;
}
bool sameset(int x, int y){
    return findset(x)==findset(y);
}

int main()
{
    while(scanf("%d %d", &N, &M)and N+M){
        ll mst=0, total=0;
        int a, b, c;
        rep(i, 0, M){
            scanf("%d %d %d", &a, &b, &c);
            edg.pb(mp(c, mp(a, b)));
            total+=c;
            //edg.pb(mp(c, mp(b, a)));
        }
        sort(edg.begin(), edg.end());

        rep(i, 0, N+1) pset[i]=i;

        rep(i, 0, M){
            int d=edg[i].F;
            int u=edg[i].S.F;
            int v=edg[i].S.S;

            if(!sameset(u, v)){
                unionset(u, v);
                mst+=d;
            }
        }
        printf("%lld\n", total-mst);
        edg.clear();
    }
return 0;
}

