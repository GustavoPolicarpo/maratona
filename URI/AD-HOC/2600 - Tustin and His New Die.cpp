// Author: Gustavo Policarpo
// Name: Tustin and His New Die
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2600

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

#define INF 0x3f3f3f3f


int main(){
	
	
	int T; cin >> T;
	
	while(T--){
		
		int dado[6]; map<int, int> C;
		
		rep(i, 0, 6) cin >> dado[i], C[dado[i]]++;
		
		bool yep=true;
		rep(i, 1, 7) if(C[i]!=1) yep=false;
		if(dado[0]+dado[5]!=7) yep=false;
		if(dado[1]+dado[3]!=7) yep=false;
		if(dado[2]+dado[4]!=7) yep=false;
		yep?puts("SIM"):puts("NAO");
		
	}
	
	return 0;
}
