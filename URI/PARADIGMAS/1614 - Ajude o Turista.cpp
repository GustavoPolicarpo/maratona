// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ajude o Turista
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1614

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int main()
{
	int T; cin >> T;
	
	while(T--){
		int N, M, K;
		vector <int> dst;
		scanint(N), scanint(M), scanint(K);
		
		ii tur[N], est[M];
		
		rep(i, 0, N) scanint(tur[i].F), scanint(tur[i].S);
		rep(i, 0, M) scanint(est[i].F), scanint(est[i].S);
		
		rep(i, 0, N)
		rep(j, 0, M)
			dst.pb(abs(tur[i].F-est[j].F)+abs(tur[i].S-est[j].S));
		
		sort(dst.begin(), dst.end());
		
		int out=0;
		rep(i, 0, K) out+=dst[i];
		
		printf("%d\n", out);
		
	}

return 0;
}
