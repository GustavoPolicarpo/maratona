// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Desempilhando Caixas
// Nível: 4
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1438

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

typedef long long int ll;
typedef pair <int, int> ii;

int main(){

	int n, m;
	while(cin >> n >> m and n+m){
		vector <int> v[m+2]; int aux, qt;
		rep(i, 0, m+2) v[i].clear();
		int l = -1, p = -1;
		rep(i, 1, m+1){
			v[i].clear();
			cin >> qt;
			rep(z, 0, qt){
				cin >> aux;
				if(aux==1) l=i, p = z;
				v[i].pb(aux);
			}
		}
		int ans = 0x3f3f3f3f; aux = 0;
		rep(i, l+1, m+2){
			if(v[i].size()<=p) break;
			aux+=v[i].size()-p;
		}
		ans = aux; aux = 0;
		for(int i=l-1; i>0; i--){
			if(v[i].size()<=p) break;
			aux+=v[i].size()-p;
		}
		ans = min(ans, aux);
		ans = ans+v[l].size()-p-1;
		cout << ans << '\n';
	}
	
	return 0;
}
