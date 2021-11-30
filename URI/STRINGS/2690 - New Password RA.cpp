// Author: Gustavo Policarpo
// Name: New Password RA
// Level: 5
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2690

#include<bits/stdc++.h>

// LIFE IS A NOT PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = a; i < b; i++ )
#define pb push_back
#define F first
#define S second

using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;


char let[266];

int main(){
	
	let['G'] = let['Q'] = let['a'] = let['k'] = let['u'] = '0';
	let['I'] = let['S'] = let['b'] = let['l'] = let['v'] = '1';
	let['E'] = let['O'] = let['Y'] = let['c'] = let['m'] = let['w'] = '2';
	let['F'] = let['P'] = let['Z'] = let['d'] = let['n'] = let['x'] = '3';
	let['J'] = let['T'] = let['e'] = let['o'] = let['y'] = '4';
	let['D'] = let['N'] = let['X'] = let['f'] = let['p'] = let['z'] = '5';
	let['A'] = let['K'] = let['U'] = let['g'] = let['q'] ='6';
	let['C'] = let['M'] = let['W'] = let['h'] = let['r'] = '7';
	let['B'] = let['L'] = let['V'] = let['i'] = let['s'] = '8';
	let['H'] = let['R'] = let['j'] = let['t'] = '9';
	
	string s; getline(cin, s);
	int T = 0;
	rep(i, 0, s.size()){
		if(!isdigit(s[i])) break;
		T*=10;
		T+=s[i]-'0';
	}
	while(T--){
		getline(cin, s); int cnt = 0;
		rep(i, 0, s.size()){
			if(s[i]==' ') continue;
			cout << let[s[i]];
			cnt++;
			if(cnt==12) break;
		}	cout << '\n';
	}
	
	return 0;
}
