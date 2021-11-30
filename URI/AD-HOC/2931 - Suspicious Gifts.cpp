// Author: Gustavo Policarpo
// Name: Suspicious Gifts
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2931

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

int C, R;
map<string, set<string> > mapa;

int main(){
	
	while(cin >> C >> R){
		mapa.clear();
		string a, b, lx; getline(cin, lx);
		rep(i, 0, C){
			getline(cin, a); int S; cin >> S; getline(cin, lx);
			rep(j, 0, S){
				getline(cin, b);
				mapa[a].insert(b);
			}
		}
		rep(i, 0, R){
			getline(cin, lx); b.clear(); a.clear();
			int yep = 0, p = 0;
			while(42){
				if(lx[p]==';'){
					p++;
					break;
				}
				a.pb(lx[p++]);
			}
			while(p<lx.size()) b.pb(lx[p++]);
			//cout << a << " " << b << '\n';
			if(mapa[a].count(b)){
				puts("Y");
			}else{
				puts("N");
			}
		}
	}	
	
			
	return 0;
}
