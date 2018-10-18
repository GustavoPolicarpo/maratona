// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: HTML
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1667

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
	//freopen("out.txt", "w", stdout);

	string s; int ta=0;
	
	while(cin >> s){
		
		if(s=="<br>"){
			cout << '\n';
			ta=0;
		}
		else if(s=="<hr>"){
			if(ta!=0) cout << '\n';
			rep(i, 0, 80) cout << '-';
			cout << '\n';
			ta=0;
		}
		else if(ta+s.size()+1<=80){
			if(ta) cout << " " << s;
			else cout << s;
			ta+=s.size()+1;
		}else{
			ta=0;
			cout << '\n';
			cout << s;
			ta+=s.size()+1;
		}
		
	}
	
	cout << '\n';
	
	return 0;
	
}
