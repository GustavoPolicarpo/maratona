// Author: Gustavo Policarpo
// Name: Less Coin Tosses
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2972

#include <bits/stdc++.h>

// boca-submit-run teammgmu19 GGZBKdXEx PP C++14 FF

#define rep(i, a, b) for(int i = a; i < b; i++)
#define REP(i, a, b) rep(i, a, b+1)
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a, b) cout << #a << " = "  << a << " ---- " << #b << " = " << b << endl;
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


int main(){

	ll N; cin >> N;
	ll ans = 0;
	while(N){
		ans+=(N&1);
		N/=2;
	}
	printf("%lld\n", (1LL<<ans));
	
	return 0;
}
