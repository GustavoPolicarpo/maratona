// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Guildas
// Nível: 5
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1527

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

int N, M, pset[100002];
int g[100002];

int findset(int x){
    if(x!=pset[x])
        pset[x]=findset(pset[x]);
    return pset[x];
}
void unionset(int x, int y){
    x=findset(x), y=findset(y);
    if(x==y) return;
    pset[y]=x; g[x]+=g[y];
}
bool sameset(int x, int y){
    return findset(x)==findset(y);
}

void init(int n)
{
    rep(i, 0, n+1){
        pset[i]=i;
        g[i]=0;
    }
}

int main()
{
    while(scanf("%d %d", &N, &M)and N+M){
        init(N+1); int out=0;
       rep(i, 1, N+1) scanf("%d", &g[i]);
       int op, a, b;

       rep(i, 0, M){
           scanf("%d %d %d", &op, &a, &b);
           if(op==1){
                if(!sameset(a, b)){
                    unionset(a, b);
                }
           }
           else{
                int u=findset(a), v=findset(b), w=findset(1);
                //cout << u << " " << v << " " << w << endl;
                if(u!=w && v!=w) continue;
                if(u==w){
                    if(g[u]>g[v]) out++;
                }
                else{
                    if(g[v]>g[u]) out++;
                }
            }
       }
       cout << out << endl;

    }
return 0;
}

