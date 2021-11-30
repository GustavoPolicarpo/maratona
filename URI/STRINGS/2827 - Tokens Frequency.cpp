// Author: Gustavo Policarpo
// Name: Tokens Frequency
// Level: 8
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2827

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
	
	string s; getline(cin, s);
	map<string, int> mapa; int maior = 0; string t;
	
	rep(i, 0, s.size()-1){
		t = ""; t.pb(tolower(s[i])); t.pb(tolower(s[i+1]));
		mapa[t]++;
		maior = max(maior, mapa[t]);
	}
	
	map<string, int> :: iterator it;
	for(it=mapa.begin(); it!=mapa.end(); it++){
		if(it->second == maior){
			cout << it->first << ":" << maior << '\n';
			return 0;
		}
	}

	
	
	return 0;
} 
