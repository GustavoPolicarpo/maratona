// Author: Gustavo Policarpo
// Name: Counting Self-Rotating Su...
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2347

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, ll > ii;
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


ii mid(ii a, ii b){
	return mp((a.F+b.F)/2, (a.S+b.S)/2);
}

const int mod=1e9 + 7;
ll C[1010][1010];
void pascal(int n){
	rep(i, 0, n){
		C[i][0]=C[i][i]=1;
		rep(j, 1, i)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
}

int main()
{
	int N; cin >> N; pascal(N+1);
	
	ll x, y; ii n[N];
	map <ii, int> mapa;
	map <ii, int> :: iterator it;
	set <ii> has;
	
	rep(i, 0, N){
		scanf("%lld %lld", &x, &y);
		x*=2, y*=2;
		n[i]=mp(x, y);
		has.insert(n[i]);
	}
	
	rep(i, 0, N)	
	rep(j, i+1, N)
	mapa[ mid(n[i], n[j]) ]++;
	
	ll ans[N+1]; memset(ans, 0, sizeof ans);
	
	for(it=mapa.begin(); it!=mapa.end(); it++){
		ii aux=it->first;
		int qt=it->second;
		
		bool yep=false;
		if(has.count(aux)) yep=true;
		
		rep(i, 1, qt+1){
			ans[i*2]=(ans[i*2]+C[qt][i])%mod;
			if(yep) ans[i*2+1]=(ans[i*2+1]+C[qt][i])%mod;
		}
	}
	
	printf("%d", N);
	rep(i, 2, N+1) printf(" %lld", ans[i]);
	printf("\n");
	
	return 0;
	
}
