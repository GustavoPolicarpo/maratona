// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Detector de Falhas
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2682

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
typedef pair<int, ii> iii;


const ll mod = 1000000007;



int main(){
	
	int last = -1, n;
	
	while(cin >> n){
		if(n<=last){
			cout << last+1 << '\n';
			return 0;
		}
		last = n;
	}
	
	cout << last + 1 << '\n';
	
	
	return 0;
}
