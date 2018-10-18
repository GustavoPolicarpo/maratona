// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Jetiqui
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2587

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
	
	//freopen("in.txt", "r", stdin);
	
	int T; cin >> T;
	
	while(T--){
		
		string a, b, c;
		
		cin >> a >> b >> c;
		vector <int> v;
		
		bool yep=0;
		
		rep(i, 0, c.size()){
			if(c[i]!='_') continue;
			v.pb(i);
		}
		
		rep(i, 0, v.size()){
			char aa=a[v[i]], bb=b[v[i]];
			
			if(aa==bb) continue;
			rep(j, 0, v.size()){
				bb=b[v[j]];
				if(aa==bb){
					yep=true;
					break;
				}
			}
			
			if(yep) break;
		}
		
		yep?puts("Y"):puts("N");
		
	}
	
		
	return 0;
	
}
