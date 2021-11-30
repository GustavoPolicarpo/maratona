// Author: Gustavo Policarpo
// Name: Escala Musical
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2662

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

int go[]={2, 2, 1, 2, 2, 2, 1};
set <int> has[12];
string ans[12];

int main(){
	
	ans[0]="do", ans[1]="do#", ans[2]="re", ans[3]="re#", 
	ans[4]="mi", ans[5]="fa", ans[6]="fa#", ans[7]="sol", 
	ans[8]="sol#", ans[9]="la", ans[10]="la#", ans[11]="si";
	
	rep(i, 0, 12){
		int aux = i; has[i].insert(aux); 
		rep(j, 0, 7)
			aux+=go[j], aux%=12, has[i].insert(aux);
	}
	
	
	int N; cin >> N; int n[N]; rep(i, 0, N) cin >> n[i], n[i]--, n[i]%=12;
	
	rep(i, 0, 12){
		bool yep = true;
		rep(j, 0, N) if(!has[i].count(n[j])) yep = false;
		if(yep){
			cout << ans[i] << '\n';
			return 0;
		}
	}
	
	puts("desafinado");
	
	return 0;
}
