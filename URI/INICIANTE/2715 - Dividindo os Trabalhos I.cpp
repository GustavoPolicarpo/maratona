// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Dividindo os Trabalhos I
// Nível: 2
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2715

#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

ll n, v[1000010], sa[1000010];

int main()
{

	while(scanf("%lld", &n)!=EOF){
		rep(i, 0, n){
			scanf("%lld", &v[i]);
			sa[i] = v[i];
			if(i) sa[i] += sa[i-1];
		}
		
		ll ans = 10000000100010LL;
		rep(i, 0, n){
			ll e = sa[i];
			ll d = sa[n-1] - sa[i];
			ans = min( ans, abs(d-e) );
		}
		
		cout << ans << '\n';
	}
	
    return 0;
}
