// Author: Gustavo Policarpo
// Name: Chirrin Chirrion
// Level: 4
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2583

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

	int T; cin >> T;
	
	while(T--){
		
		int N; cin >> N; set <string> st; string a, b;
		
		while(N--){
			cin >> a >> b;
			if(b=="chirrin") st.insert(a);
			else if(b=="chirrion") st.erase(a);
		}
		
		puts("TOTAL");
		set <string> :: iterator it;
		for(it=st.begin(); it!=st.end(); it++){
			cout << *it << '\n';
		}
	
	}
	
	

	return 0;
	
}
