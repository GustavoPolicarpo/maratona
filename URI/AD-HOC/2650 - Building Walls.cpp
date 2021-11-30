// Author: Gustavo Policarpo
// Name: Building Walls
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2650

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
	
	int N, W; cin >> N >> W; cin.ignore();
	
	string s; int n;
	rep(i, 0, N){
		getline(cin, s); string ss;
		rep(i, 0, s.size()){
			if(s[i]==' ' && isdigit(s[i+1])){
				n = 0; i++;
				while(i<s.size()){
					n*=10;
					n+=s[i]-'0';
					i++;
				}
				break;
			}
			ss.pb(s[i]);
		}
		if(n>W) cout << ss << '\n';
	}
	
	return 0;
}
