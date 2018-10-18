// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Laércio
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2812

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;



int main(){
	
	int t; cin >> t;
	while(t--){
		int n; vector <int> v; int aux;
		cin >> n;
		rep(i, 0, n){
			cin >> aux;
			if(aux&1) v.pb(aux);
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int qt = 0, i = 0, j = v.size()-1;
		while(qt<v.size()){
			if(i) cout << " ";
			if(qt%2==0) cout << v[i++], qt++;
			else cout << v[j--], qt++;
			if(qt==v.size()) break;
		}
		cout << '\n';
	}
	
	return 0;
}
