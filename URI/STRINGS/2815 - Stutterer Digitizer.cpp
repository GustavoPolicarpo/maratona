// Author: Gustavo Policarpo
// Name: Stutterer Digitizer
// Level: 2
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2815

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
	stringstream ss; ss << s;
	int first = 0;
	while(ss >> s){
		if(first) cout << " ";
		first = 1;
		if(s.size()>=4){
			string a, b;
			a.pb(s[0]), a.pb(s[1]);
			b.pb(s[2]), b.pb(s[3]);
			if(a==b) s.erase(s.begin(), s.begin()+2);
		}
		cout << s;
	}	cout << '\n';
			
	return 0;
}
