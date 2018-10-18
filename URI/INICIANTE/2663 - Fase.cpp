// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fase
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2663

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



int main(){
	
	int N, K; cin >> N >> K;
	int n[N]; rep(i, 0, N) cin >> n[i];
	
	sort(n, n+N), reverse(n, n+N);
	
	int qt = K, cmp = n[K-1];
	
	while(K<N && n[K]==cmp) qt++, K++;
	
	cout << qt << '\n';
	
	
	
	return 0;
}
