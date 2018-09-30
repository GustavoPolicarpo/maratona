#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

ll n, k, mod = 1e9+7;

ll fastExp(ll b, ll e){
	ll r = 1; b = b%mod;
	while(e){
		if(e&1) r = (r*b)%mod;
		b = (b*b)%mod, e = e/2;
	}
	return r;
}

ll invMod(ll b){
	return fastExp(b, mod-2)%mod;
}

ll PA(ll ini, ll fim){
	fim = (fim+mod)%mod;
	ll r = (((ini+fim)%mod*(fim-ini+1))%mod*invMod(2));
	return r%mod;
}

int main(){
	
	cin >> n >> k;
	if(n==0){
		cout << 0 << '\n';
		return 0;
	}
	ll ans = ((2LL*((n%mod*fastExp(2, 2LL*k))%mod - PA(0, (fastExp(2, k)-1+mod)%mod) + mod))%mod * invMod(fastExp(2, k)))%mod;
	cout << ans << '\n';
	
	/*
	2* (n)												1
	2* (n*2-1 + n*2) 									2
	2* (n*4-3 + n*4-2 + n*4-1 + n*4)					4
	........................................................
	2* (n*2^k*2^k - PA(0, 2^k-1)						2^k
		n*2^(2k)
	*/
		
	
	return 0;
} 
