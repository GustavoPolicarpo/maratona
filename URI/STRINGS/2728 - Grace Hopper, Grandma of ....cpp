// Author: Gustavo Policarpo
// Name: Grace Hopper, Grandma of ...
// Level: 6
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2728

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
	
	string s;
	while(getline(cin, s)){
		vector <string> vans; string t;
		rep(i, 0, s.size()){
			if(s[i]=='-'){
				vans.pb(t);
				t.clear();
			}else{
				t.pb(s[i]);
			}
		} vans.pb(t);
		int p = 1; t = "cobol";
		rep(i, 0, vans.size()){
			if(tolower(vans[i][0])==t[i] || tolower(vans[i][vans[i].size()-1])==t[i]) continue;
			p = 0;
			break;
		}
		if(p) puts("GRACE HOPPER");
		else puts("BUG");
	}
	
	
	return 0;
}
