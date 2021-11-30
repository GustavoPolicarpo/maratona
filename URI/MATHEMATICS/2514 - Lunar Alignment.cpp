// Author: Gustavo Policarpo
// Name: Lunar Alignment
// Level: 5
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2514

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;

ll mmmc(ll a, ll b){
	if(a>b) swap(a, b); ll aux=b;
	while(1){
		if(b%a==0) return b;
		b+=aux;
	}
}
int main(){
	
	ll m, a, b, c;
	while(cin >> m >> a >> b >> c){
		ll ans=mmmc(a, b);
		ans=mmmc(ans, c);
		ans-=m;
		cout << ans << '\n';
	}
	
	return 0;
	
}

