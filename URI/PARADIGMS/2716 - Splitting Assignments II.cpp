// Author: Gustavo Policarpo
// Name: Splitting Assignments II
// Level: 9
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2716

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

ll n, v[1000010], sum;
ll dp[155*2002];
vector <ll> cango;

int main()
{

	while(scanf("%lld", &n)!=EOF){
		
		rep(i, 0, sum+2) dp[i] = 0;	sum = 0;
		
		rep(i, 0, n){
			scanf("%lld", &v[i]);
			sum+=v[i];
		}
		
		dp[0] = 1;
		rep(i, 0, n){
			rep(j, 0, sum+1) if(dp[j] && !dp[j+v[i]]) cango.pb(j+v[i]);
			rep(j, 0, cango.size()) dp[cango[j]] = 1;
			cango.clear();
		}
		
		ll ans = 1000000100000LL;
		rep(i, 0, sum+1){
			if(!dp[i]) continue;
			ll e = i;
			ll d = sum-i;
			ans = min(ans, abs(e-d));
		}
		
		cout << ans << '\n';
		
	}
	
    return 0;
}
