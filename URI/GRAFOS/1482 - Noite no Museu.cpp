// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Noite no Museu
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1482

#include<bits/stdc++.h>
#define gc getchar_unlocked


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
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

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


int tt[21][21], t[21], pd[21][1<<21];
int N, fim=420;

int solve(int i, int mask, int tempo){
	int cont=__builtin_popcount(mask);
	if(cont==N) return 0;
	if(pd[i][mask]!=-1) return pd[i][mask];
	int ret=0;
	rep(j, 0, N){
		if(mask&(1<<j) || tempo+tt[i][j]+t[j]>fim) continue;
		ret=max(ret, solve(j, mask|(1<<j), tempo+tt[i][j]+t[j])+1);
	}
	return pd[i][mask]=ret;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(1){
		scanint(N);
		if(!N) break;
		rep(i, 0, N){
			scanint(t[i]);
			rep(j, 0, 1<<N+1) pd[i][j]=-1;
		}
		rep(i, 0, N)
		rep(j, 0, N)
			scanint(tt[i][j]);
		
		int out=0;
		rep(i, 0, N){
			if(t[i]>fim) continue;
			out=max(out, solve(i, 1<<i, t[i])+1);
		}
		printf("%d\n", out);
	}

return 0;
}

