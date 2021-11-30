// Author: Gustavo Policarpo
// Name: Shopping List
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2729

#pragma comment(linker, "/stack:200000000")                                     
#pragma GCC optimize("Ofast")                                                   
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")   
#define _CRT_SECURE_NO_WARNINGS          
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef pair <int, int> ii;





int main(){
	
	int N; cin >> N;
	string s; getline(cin, s);
	while(N--){
		getline(cin, s);
		stringstream ss;
		ss << s;
		set <string> st;
		vector <string> vans;
		while(ss>>s){
			if(st.count(s)) continue;
			st.insert(s);
			vans.pb(s);
		}
		
		sort(vans.begin(), vans.end());
		rep(i, 0, vans.size()){
			if(i) cout << " ";
			cout << vans[i];
		}	cout << "\n";
	}
	
	
	return 0;
}
