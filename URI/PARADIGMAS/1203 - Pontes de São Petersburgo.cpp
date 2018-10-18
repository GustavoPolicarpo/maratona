// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pontes de São Petersburgo
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1203

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
typedef pair < double, int > iii;

int R, K, g[200];
int pd[250][5001]; bool yep;

int solve(int i, int k)
{
    //cout << k << endl;
    if(k==K){
        yep=true;
        return 1;
    }
    if(i==R) return 0;

    if(pd[i][k]!=-1) return pd[i][k];
    int ret=solve(i+1, k);
    if(k+g[i]<=K){
        ret=max(ret, solve(i+1, k+g[i]));
    }

    return pd[i][k]=ret;
}

int main()
{
    while(scanf("%d %d", &R, &K) !=EOF){
        memset(pd, -1, sizeof pd);
        yep=false;
        memset(g, 0, sizeof g);
        int u, v;
        rep(i, 0, K){
            scanf("%d %d", &u, &v);
            g[u]++, g[v]++;
        }
        solve(0, 0);
        if(yep) printf("S\n");
        else printf("N\n");
    }

return 0;
}

