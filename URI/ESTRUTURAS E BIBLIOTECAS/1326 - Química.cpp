// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Química
// Nível: 8
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1326

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

map<string, vector < pair <string, string> > > mapa;
map<string, vector < pair <string, string> > > :: iterator it;
map<string, int> qt;

int solve(string at){
	if(!mapa[at].size()) return qt[at] = 0;
	if(qt.count(at)) return qt[at];
	qt[at] = 0x3f3f3f3f;
	rep(i, 0, mapa[at].size()){
		int a = solve(mapa[at][i].F);
		int b = solve(mapa[at][i].S);
		qt[at] = min(qt[at], max(max(a, b), min(a, b)+1));
	}
	return qt[at];
}

int main(){
	
	int N;
	while(scanf("%d", &N) and N){
		char a[6], b[6], c[6]; mapa.clear(), qt.clear();
		rep(i, 0, N){
			scanf(" %s + %s -> %s", a, b, c);
			mapa[c].pb(mp(a, b));
		}
		int ans = solve(c);
		printf("%s requires %d containers\n", c, ans);
	}
	
	return 0;
}
