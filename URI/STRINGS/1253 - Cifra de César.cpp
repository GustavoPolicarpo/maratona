// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cifra de César
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1253

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

string m, t;

int main(){
	
	//freopen("in.txt", "r", stdin);
	
	int T; cin >> T;
	
	while(T--){
		
		string s; cin >> s;
		int n; cin >> n;
		
		rep(i, 0, s.size()){
			int aux=s[i]-'A';
			aux=(aux-n+26)%26;
			s[i]=aux+'A';
		}
		
		cout << s << '\n';
		
	}
		
	return 0;
	
}
