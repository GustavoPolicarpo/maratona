// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sapo Saltador
// Nível: 5
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2704

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
 


vector <int> dv;
string s;
int n;

void build(int n){
	rep(i, 2, n) if(n%i==0) dv.pb(i);
	return;
}

int can[100010], ini, resp[100010], used[100010];
vector <int> pass;

int dfs(int u, int k, int saltei){
	if(can[u]) return can[u];
	if(s[u]=='P') return 1;
	if(u==ini && saltei) return 2;
	pass.pb(u);
	int v = (u+k)%n;
	return can[u] = dfs(v, k, 1);
}

int main()
{
	
	cin >> s; n = s.size();
	
	bool yep = true;
	rep(i, 0, n){
		if(s[i]=='P'){
			yep = false;
			break;
		}
	}
	if(yep){
		cout << n-1 << '\n';
		return 0;
	}
	
	build(n);
	int ans = 0;
	rep(i, 0, n) used[i] = 1;
	
	rep(i, 0, dv.size()){
		int k = dv[i];
		rep(j, 0, n){
			ini = j;
			int xua = dfs(j, k, 0);
			if(xua==2){
				int aux = k;
				while(aux<n){
					ans+=used[aux];
					used[aux] = 0;
					aux+=k;
				}
				break;
			}
		}
		rep(j, 0, pass.size()) can[pass[j]] = 0;
		pass.clear();
	}
	
	
	cout << ans << '\n';
	
    return 0;
}
