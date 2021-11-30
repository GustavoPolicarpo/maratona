// Author: Gustavo Policarpo
// Name: Words
// Level: 7
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1231

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef pair<string, int> ii;

int N[2];
set <string> st[2];
set <string> vis[2];

int yep;

ii valid(string s, string t, int current){
	rep(i, 0, min(s.size(), t.size())){
		if(s[i]!=t[i]){
			return ii("*", -1);
		}
	}
	if(t.size() > s.size()){
		return ii(t.substr(s.size(), t.size()), current);
	}
	else{
		return ii(s.substr(t.size(), s.size()), current^1);
	}
}

void solve(string s, int last){
	if(s=="" || yep){
		yep = 1;
		return;
	}
	if(vis[last].count(s)) return;
	vis[last].insert(s);

	set <string> :: iterator it;
	int current = last^1;
	for(it = st[current].begin(); it!=st[current].end(); it++){
		ii go = valid(s, *it, current);
		if(go.S==-1) continue;
		solve(go.F, go.S);
	}
}

int main(){
	
	while(cin >> N[0] >> N[1]){
		rep(z, 0, 2){
			st[z].clear();
			rep(i, 0, N[z]){
				string s; cin >> s;
				st[z].insert(s);
			}
			vis[z].clear();
		}
		
		yep = 0;
		
		set <string> :: iterator it;
		for(it = st[0].begin(); it!=st[0].end(); it++){
			solve(*it, 0);
		}
		
		if(yep){
			puts("S");
		}else{
			puts("N");
		}
		
	}
	
	return 0;
}
