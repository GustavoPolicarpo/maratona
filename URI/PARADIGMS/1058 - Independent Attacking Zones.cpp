// Author: Gustavo Policarpo
// Name: Independent Attacking Zones
// Level: 8
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1058

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;


int T, N;
string p;
ll pd[44][44];

ll solve(int i, int j){
	if(i>j) return 1;
	if(j-i<2) return 0;
	if(pd[i][j]!=-1) return pd[i][j];
	ll ret = 0;
	rep(k, i+1, j+1){
		rep(l, k+1, j+1){
			int cnt = (p[i]=='R') + (p[k]=='R') + (p[l]=='R');
			if(cnt>1) continue;
			ll aux = solve(l+1, j)*solve(i+1, k-1)*solve(k+1, l-1);
			ret += aux;
		}
	}
	return pd[i][j] = ret;
}

int main(){
	
	cin >> T;
	rep(z, 1, T+1){
		printf("Case %d: ", z);
		cin >> N >> p;
		memset(pd, -1, sizeof pd);
		ll ans = 0;
		ans = solve(0, N-1);
		cout << ans << '\n';
	}
	
	return 0;
}
