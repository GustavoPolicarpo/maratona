// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ginástica
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2664

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const ll mod = 1e9+7;

int T, M, N; 
ll pd[55][100010];

int main(){
	
	cin >> T >> M >> N;
	
	rep(i, M, N+1) pd[T][i] = 1;
	for(int i=T-1; i>=1; i--){
		pd[i][M] = pd[i+1][M+1]%mod;
		pd[i][N] = pd[i+1][N-1]%mod;
		rep(j, M+1, N)
			pd[i][j] = (pd[i+1][j-1]+pd[i+1][j+1])%mod;
	}
	
	ll ans = 0;
	rep(i, M, N+1) ans = (ans+pd[1][i])%mod;
	
	cout << ans << '\n';
	
	return 0;
}
