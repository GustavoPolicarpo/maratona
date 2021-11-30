// Author: Gustavo Policarpo
// Name: Evergreen Trick
// Level: 3
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2722

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
	
	int T; cin >> T; string s; getline(cin, s);
	while(T--){
		string a, b;
		getline(cin, a);
		getline(cin, b);
		s.clear();
		int i = 0, j = 0;
		while(i<a.size()){
			if(i!=a.size()) s.pb(a[i++]);
			if(i!=a.size()) s.pb(a[i++]);
			if(j!=b.size()) s.pb(b[j++]);
			if(j!=b.size()) s.pb(b[j++]);
		}	//s.pb(0);
		
		cout << s << '\n';
	}
	
	return 0;
	
}
