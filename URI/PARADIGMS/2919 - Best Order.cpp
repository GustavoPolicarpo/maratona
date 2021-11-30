// Author: Gustavo Policarpo
// Name: Best Order
// Level: 7
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2919

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;	
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << m[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;

using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;

int N;
ll dp[500050];
ll bit[500050];
ll n[500050], o[500050];
map<ll, int> C;

void update(ll x, ll v){
	x++;
	for(; x>0; x-=(x&-x)) bit[x] = max(bit[x], v);
}

ll query(ll x){
	ll ret = 0; x++;
	for(; x<=N+2; x+=(x&-x)) ret = max(ret, bit[x]);
	return ret;
}

int main(){

	
	while(scanf("%d", &N)!=EOF){
		C.clear();
		rep(i, 0, N+4) bit[i] = 0;
		rep(i, 0, N) scanf("%lld", &n[i]), o[i] = n[i];
		sort(o, o+N); int cnt = 1;
		rep(i, 0, N){
			C[o[i]] = cnt++;
		}
		rep(i, 0, N) n[i] = C[n[i]];
		
		ll ans = 0;
		for(int i=N-1; i>=0; i--){
			dp[i] = 1 + query(n[i]+1);
			ans = max(ans, dp[i]);
			update(n[i], dp[i]);
		}
		printf("%lld\n", ans);
	}
	
	
	
	return 0;
}
