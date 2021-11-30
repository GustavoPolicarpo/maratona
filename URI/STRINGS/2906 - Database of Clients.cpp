// Author: Gustavo Policarpo
// Name: Database of Clients
// Level: 3
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2906

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;


set <string> st;
string s;
int N;

int main(){
	
	cin >> N;
	while(N--){
		cin >> s; string t; int i = 0;
		for(; i<s.size(); i++){
			if(s[i]=='.') continue;
			if(s[i]=='+') while(s[i]!='@') i++;
			if(s[i]=='@'){
				break;
			}
			t.pb(s[i]);
		}
		for(; i<s.size(); i++) t.pb(s[i]);
		st.insert(t);
	}
	
	cout << st.size() << '\n';
	
	return 0;
}

