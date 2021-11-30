// Author: Gustavo Policarpo
// Name: My Temporary Password
// Level: 2
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2714

#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;
 



int main()
{
	
	int T; cin >> T;
	string s; getline(cin, s)	;
	
	while(T--){
		getline(cin, s);
		if(s.size()!=20 || s.substr(0, 2)!="RA"){
			puts("INVALID DATA");
		}else{
			bool yep = false;
			rep(i, 2, s.size()){
				if(s[i]!='0') yep = true;
				if(yep) cout << s[i];
			}	cout << '\n';
		}
	}
	
	
    return 0;
}
