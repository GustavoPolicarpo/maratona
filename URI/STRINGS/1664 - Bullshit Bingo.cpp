// Author: Gustavo Policarpo
// Name: Bullshit Bingo
// Level: 7
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1664

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

#define INF 0x3f3f3f3f
const int mod=1e9+7;




int main(){
	
	string s, ss;
	set <string> st;
	
	int tt=0, t=0, aux=0;
	
	while(getline(cin, s)){
		
		//if(s=="*") break;
		
		s.pb('#');
		
		rep(i, 0, s.size()){
			
			if(!isalpha(s[i]) && ss.size()){
				if(ss.size() && !st.count(ss)){
					if(ss=="bullshit"){
						tt++;
						t+=aux;
						aux=0;
						st.clear();
					}else{
						st.insert(ss);
						aux++;
					}
				}
				ss.clear();
			}else{
				if(isalpha(s[i]))
					ss.pb(tolower(s[i]));
			}
		}
		
	}
	
	aux=__gcd(t, tt);
	printf("%d / %d\n", t/aux, tt/aux);
	
	return 0;
	
}
