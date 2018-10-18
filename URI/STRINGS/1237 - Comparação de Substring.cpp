// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Comparação de Substring
// Nível: 3
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1237

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

const ll NN = 505;
const ll mod = 1e9 + 7;
const ll x = 113;
ll H[NN][2], X[NN][2];

ll V(char c){ return c-'0'; }

ll my_hash(int i, int j, int op){
	ll ret = H[j][op];
	if(!i) return ret;
	return ((ret-(H[i-1][op]*X[j-i+1][op])%mod)+mod)%mod;
}

void precompute(string s, int op){
	X[0][op] = 1;
	rep(i, 1, NN)
		X[i][op] = (X[i-1][op]*x)%mod;
	H[0][op] = V(s[0]);
	rep(i, 1, s.size())
		H[i][op] = ((H[i-1][op]*x)%mod + V(s[i]))%mod;
}

string a, b;
bool check(int m){
	set <int> has;
	rep(i, 0, a.size()-m+1){
		has.insert(my_hash(i, i+m-1, 0));
	}
	rep(i, 0, b.size()-m+1){
		int h = my_hash(i, i+m-1, 1);
		if(has.count(h)) return true;
	}
	return false;
}
int main(){
	
	
	while(getline(cin, a)){
		getline(cin, b);
		if(a.size() > b.size()) swap(a, b);
		precompute(a, 0);
		precompute(b, 1);
		int ini = 1, fim = a.size(), mid, ans = 0;
		while(ini<=fim){
			mid = (ini+fim)/2;
			if(check(mid)){
				ans = mid;
				ini = mid+1;
			}else{
				fim = mid-1;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
} 
