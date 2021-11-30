// Author: Gustavo Policarpo
// Name: Uppercase, Why?
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2829

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int N;
vector <string> v;

bool cmp(string a, string b){
	rep(i, 0, min(a.size(), b.size())){
		if(tolower(a[i]) < tolower(b[i])) return true;
		if(tolower(b[i]) < tolower(a[i])) return false;
	}
	if(a.size() != b.size()) return a.size() < b.size();
	rep(i, 0, min(a.size(), b.size())){
		if(a[i] < b[i]) return true;
		if(b[i] < a[i]) return false;
	}
}

int main(){
	
	cin >> N; string s;
	rep(i, 0, N){
		cin >> s;
		v.pb(s);
	}
	
	sort(v.begin(), v.end(), cmp);
	rep(i, 0, v.size()) cout << v[i] << '\n';

	
	
	return 0;
} 
