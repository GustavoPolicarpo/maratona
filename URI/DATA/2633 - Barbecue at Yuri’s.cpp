// Author: Gustavo Policarpo
// Name: Barbecue at Yuri’s
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2633

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

const ll mod = 1e9+7;



int main(){
	
	int N;
	
	while(scanf("%d", &N) !=EOF){
		vector <pair<int, string> > v;
		string s; int i;
		
		while(N--){
			cin >> s >> i;
			v.pb(mp(i, s));
		}
		
		sort(v.begin(), v.end());
		
		rep(i, 0, v.size()){
			if(i) cout << " ";
			cout << v[i].S;
		}	cout << '\n';
		
	}
	
	return 0;
}
