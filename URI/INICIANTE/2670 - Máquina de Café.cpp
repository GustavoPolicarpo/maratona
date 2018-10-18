// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Máquina de Café
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2670

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
	
	int v[3]; cin >> v[0] >> v[1] >> v[2];
	int ans = 0x3f3f3f3f;
	
	rep(i, 0, 3){
		int aux = 0;
		rep(j, 0, 3){
			aux+=abs(i-j)*2*v[j];
		}
		ans = min(ans, aux);
	}
	
	cout << ans << '\n';
	
	
	return 0;
}
