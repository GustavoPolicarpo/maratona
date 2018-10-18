// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Luzes de Natal
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2718

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;



int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t; cin >> t;
	while(t--){
		
		ll n; cin >> n; string s;
		while(n){
			s.pb(n&1);
			n/=2;
		}
		
		int ans = 0, aux = 0;
		rep(i, 0, s.size()){
			if(s[i]==1) aux++;
			else ans = max(ans, aux), aux = 0;
		}	ans = max(ans, aux);
		
		cout << ans << '\n';
		
	}
	
	return 0;
	
}
