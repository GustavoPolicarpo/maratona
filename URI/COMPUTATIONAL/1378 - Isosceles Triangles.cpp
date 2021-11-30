// Author: Gustavo Policarpo
// Name: Isosceles Triangles
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1378

#include<bits/stdc++.h>

#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> ii;



vector <ii> v, vin;
ii pivot;

ll distance(ii a, ii b){
	return (a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S);
}

bool cmp(ii a, ii b){
	ll da = distance(a, pivot);
	ll db = distance(b, pivot);
	return da < db;
}

int main(){

	int N;
	while(scanf("%d", &N) and N){
		v.clear(); vin.clear(); ii aux;
		rep(i, 0, N){
			scanf("%lld %lld", &aux.F, &aux.S);
			v.pb(aux);
			vin.pb(aux);
		}
		
		ll ans = 0;
		rep(i, 0, N){
			pivot = vin[i];
			sort(v.begin(), v.end(), cmp);
			ll ini = 0, fim = 0;
			while(fim<N){
				while(fim<N && distance(v[ini], pivot)==distance(v[fim], pivot)) fim++;
				ll qt = fim-ini;
				ll aux = (qt*(qt-1))/2;
				ans+=aux;
				ini = fim;
			}
		}
		
		printf("%lld\n", ans);
		
	}
}
