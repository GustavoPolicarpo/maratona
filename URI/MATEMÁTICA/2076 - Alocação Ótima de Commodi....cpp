// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Alocação Ótima de Commodi...
// Nível: 4
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2076

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef pair <int, int> ii;

const ll mod = 1300031;
ll I, F, N;
ll n[22], ans;

ll val(ll v){
	
	ll ini = (I/v)*v;
	if(ini<I) ini+=v;
	
	ll fim = (F/v)*v;
	
	ll qt = (fim-ini)/v + 1;
	
	ll ret = ((ini+fim)*qt)/2;
	return ret%mod;
}

ll sol(int i, int t, int q, ll v){
	if(q==t) return val(v);
	if(i==N || v>F) return 0;
	ll ret = sol(i+1, t, q, v);
	ll gc = __gcd(v, n[i]);
	ret = (ret + sol(i+1, t, q+1, v/gc*n[i]))%mod;
	return ret;
}

int main(){

	int T; cin >> T;
	while(T--){
		cin >> I >> F >> N;
		rep(i, 0, N) cin >> n[i];
		ans = 0;
		rep(i, 1, N+1){
			if(i&1) ans = (ans+sol(0, i, 0, 1))%mod;
			else ans = (ans-sol(0, i, 0, 1)+mod)%mod;
		}
		cout << ans << '\n';
	}
	
	return 0;
}
