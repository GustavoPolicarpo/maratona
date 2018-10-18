// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Empilhamento de Bolas
// Nível: 6
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1312

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


int N, mat[1001][1001]; 
ll sum[1001][1001], pd[1001][1001];

ll solve(int i, int j)
{
	if(j>i||i>=N || i<0) return 0;
	if(pd[i][j]!=-1) return pd[i][j];
	
	ll ret=solve(i-1, j);
	ret=max(ret, max(solve(i+1, j+1)+sum[i][j], solve(i, j+1)+sum[i][j]));
	
	return pd[i][j]=ret;
}
int main()
{
	while(1){
		scanint(N);
		if(!N) break;
		
		rep(i, 0, N)
			rep(j, 0, i+1)
				scanint(mat[i][j]), pd[i][j]=-1;
				
		rep(i, 0, N)
			sum[i][i]=mat[i][i];
		
		rep(i, 0, N)
			rep(j, i+1, N)
				sum[j][i]=sum[j-1][i]+mat[j][i];
			
		ll comp=0;
		ll out=max(comp, solve(N-1, 0));
		printf("%lld\n", out);
	}
		
return 0;	
}
