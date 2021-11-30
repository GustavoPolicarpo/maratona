// Author: Gustavo Policarpo
// Name: Enigma
// Level: 4
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2880

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
	
	
	string s, t; cin >> s >> t;
	
	int ans = 0;
	rep(i, 0, (int)s.size()-(int)t.size()+1){
		int yep = 1;
		rep(j, 0, t.size()){
			if(s[i+j]==t[j]){
				yep = 0;
				break;
			}
		}
		ans+=yep;
	}
	cout << ans << '\n';
	
	return 0;
} 
