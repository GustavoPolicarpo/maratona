// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pentágono
// Nível: 3
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2584

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

#define INF 0x3f3f3f3f
const int mod=1e9+7;

string m, t;

int main(){
	
	//freopen("in.txt", "r", stdin);
	
	int T; cin >> T;
	
	while(T--){
		
		int N; cin >> N;
		printf("%.3lf\n", 5.0*N*(N/2.0)/tan(36.0*M_PI/180.0)/2.0);
		
	}
		
	return 0;
	
}
