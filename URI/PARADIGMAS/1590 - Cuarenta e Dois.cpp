// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cuarenta e Dois
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1590

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
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> ii;


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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, M, T, n[40], out;

void solve(int i, int k, int sum){
	if(k==0){
		out=max(out, sum);
		return;
	}
	if(i==N) return;
	solve(i+1, k, sum);
	solve(i+1, k-1, sum&n[i]);
}
int main ()
{
	cin >> T;
	while(T--){
		scanf("%d %d", &N, &M);
		rep(i, 0, N) scanf("%d", &n[i]);
		
		out=0;
		solve(0, M, (ll(1)<<31)-1);
		
		printf("%d\n", out);
	}
	
	
  
  return 0;
}

