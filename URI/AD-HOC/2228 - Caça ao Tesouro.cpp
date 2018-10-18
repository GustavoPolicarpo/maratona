// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Caça ao Tesouro
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2228

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
#define MAXN 100001
#define mod 1000000007
#define error 1e-7

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
}
*/

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int pd[101][10505], n[101];
int X, Y, N, z=1; bool fim;
int solve(int i, int x, int y){
	if(fim) return 1;
	if(i==N){
		if(x==y){
			fim=true;
			return 1;	
		}
		return 0;
	}
	int &p=pd[i][x];
	if(p!=-1) return p;
	int ret=0;
	ret=max(ret, max(solve(i+1, x+n[i], y), solve(i+1, x, y+n[i])));
	return p=ret;
}
int main()
{
	while(scanf("%d %d %d", &X, &Y, &N) and X+Y+N){
		printf("Teste %d\n", z++);
		memset(pd, -1, sizeof pd); fim=false;
		rep(i, 0, N) scanf("%d", &n[i]);
		int yep=0;
		yep=solve(0, X, Y);
		if(yep) puts("S");
		else puts("N");
		printf("\n")	;
	}
	
	return 0;	
}
