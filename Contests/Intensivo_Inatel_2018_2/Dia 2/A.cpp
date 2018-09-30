#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int n, v[10010];
ll pd[10010][2];

//y = 0, nao peguei o ultimo, portanto posso pegar o atual
//y = 1, peguei o ultimo, portanto NAO posso pegar o atual

ll solve(int i, int y){
	if(i==n) return 0;
	if(pd[i][y]!=-1) return pd[i][y];
	ll ret = solve(i+1, 0);
	if(!y) ret = max(ret, solve(i+1, 1)+v[i]);
	return pd[i][y] = ret;
}

int main(){

	int T; cin >> T;
	rep(z, 1, T+1){
		scanf("%d", &n);
		rep(i, 0, n) scanf("%d", &v[i]);
		memset(pd, -1, sizeof pd);
		printf("Case %d: %lld\n", z, solve(0, 0));
	}
	
	return 0;
} 
