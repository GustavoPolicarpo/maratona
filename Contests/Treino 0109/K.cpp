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
	
	string s; cin >> s;
	rep(i, 0, s.size()){
		int cnt = 1;
		while(i+cnt<s.size() && s[i+cnt]==s[i]) cnt++;
		cout << s[i] << cnt;
		i+=cnt-1;
	}	cout << '\n';

	return 0;
} 
