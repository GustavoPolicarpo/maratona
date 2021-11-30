// Author: Gustavo Policarpo
// Name: Voice Dialing
// Level: 5
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2678

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;


int main(){
	
	string s;
	
	map<char, int> C;
	rep(i, 'A', 'C'+1) C[i]=2;
	rep(i, 'D', 'F'+1) C[i]=3;
	rep(i, 'G', 'I'+1) C[i]=4;
	rep(i, 'J', 'L'+1) C[i]=5;
	rep(i, 'M', 'O'+1) C[i]=6;
	rep(i, 'P', 'S'+1) C[i]=7;
	rep(i, 'T', 'V'+1) C[i]=8;
	rep(i, 'W', 'Z'+1) C[i]=9;
	
	while(getline(cin, s)){
		
		rep(i, 0, s.size()){
			if(s[i]=='-') continue;
			else if(isdigit(s[i]) || s[i]=='*' || s[i]=='#') cout << s[i];
			else if(isalpha(s[i])) cout << C[toupper(s[i])];
		}
		cout << '\n';
	}
	
	return 0;
	
}
