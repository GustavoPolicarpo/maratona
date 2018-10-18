// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Mago é Implacável!
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2713

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
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;
 

int N, K, V, cmp;
double pd[1010][101];
int mark[1010][101], vida[1010], dano[1010];

double solve(int i, int m){
	if(i==N) return 0;
	if(mark[i][m]==cmp) return pd[i][m];
	mark[i][m] = cmp;
	double &ret = pd[i][m] = 1e32;
	if(m) ret = solve(i+1, m-1) + double(vida[i])/(V+dano[i]);
	ret = min(ret, solve(i+1, m) + double(vida[i])/V);
	return ret;
}

int main()
{
	
	while(scanf("%d %d %d", &N, &K, &V)!=EOF){
		cmp++;
		rep(i, 0, N) scanf("%d %d", &vida[i], &dano[i]);
		printf("%.4lf\n", solve(0, K));
	}
	
    return 0;
}
