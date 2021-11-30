// Author: Gustavo Policarpo
// Name: Tiro ao Alvo
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2432

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
typedef pair < int, int > ii;
typedef pair < int, ii > iii;
typedef pair < iii, ii > iiii;

const ll mod = 1e9;
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


int C, T;
vector <ll> r;

int main()
{	
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
	scanf("%d %d", &C, &T);
	int x, y, in;
	
	rep(i, 0, C){
		scanf("%d", &in);
		r.pb(ll(in)*in);
	}
	
	ll ans=0;
	while(T--){
		scanf("%d %d", &x, &y);
		ll aux=ll(x)*x + ll(y)*y;
		int p=lower_bound(r.begin(), r.end(), aux)-r.begin();
		ans+=C-p;
	}
	
	printf("%lld\n", ans);
	
	return 0;
	
}
