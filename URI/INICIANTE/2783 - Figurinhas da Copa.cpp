// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Figurinhas da Copa
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2783

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main(){
	
	int n, c, m; cin >> n >> c >> m;
	int aux, ans = c; set <int> st;
	
	rep(i, 0, c){
		cin >> aux;
		st.insert(aux);
	}
	
	rep(i, 0, m){
		cin >> aux;
		if(st.count(aux)){
			st.erase(st.find(aux));
			ans--;
		}
	}
	
	cout << ans << "\n";
	
	
	return 0;
}
