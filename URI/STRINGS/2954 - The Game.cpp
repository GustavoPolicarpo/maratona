// Author: Gustavo Policarpo
// Name: The Game
// Level: 6
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2954

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define per(i,a,b) for( int i = (int) a; i > (int) b; i-- )
#define F first
#define S second
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }
#define all(s) s.begin(), s.end()
#define mst(v, a) memset(v, a, sizeof(v))

using namespace std;
 
typedef long long int ll;
typedef pair <int, char> ii;
 
const int MAX = 2e3+3;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;



int main(){
	
	//std::ios::sync_with_stdio(false);
	
	//freopen ("in.txt","r",stdin);
	//freopen ("out.txt","+w",stdout);
	
	int T; cin >> T; cin.ignore();
	rep(test, 1, T+1){
		string s; getline(cin, s);
		string t;
		rep(i, 0, s.size()){
			if(s[i]=='.' || s[i]==',') continue;
			t.pb(tolower(s[i]));
		}
		
		stringstream ss; ss << t;
		int ans = 0, aux = 0;
		while(ss>>s){
			aux+=s.size();
			ans = max(ans, aux);
			if(s=="jogo" || s=="perdi"){
				aux = 0;
			}
		}
		
		cout << ans << '\n';
		
	}

	
    return 0;
}
