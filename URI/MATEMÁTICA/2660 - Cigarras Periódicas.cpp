// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cigarras Periódicas
// Nível: 4
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2660

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


ll lcm(ll a, ll b){
	return a/__gcd(a, b)*b;
}

int main(){
	
	int N, L; cin >> N >> L; int n[N]; cin >> n[0];
	ll lc = n[0];
	rep(i, 1, N){
		cin >> n[i];
		lc = lcm(lc, n[i]);
	}
	
	ll maior = lc, ans = 1;
	rep(i, 2, L+1){
		ll aux = lcm(lc, i);
		if(aux>maior && aux<=L){
			maior = aux;
			ans = i;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
