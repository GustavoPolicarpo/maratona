// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A Bruxa do 7 x 1
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2569

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

	string a, op, b, r;
	stringstream aa, bb, rr;
	
	cin >> a >> op >> b;
	
	rep(i, 0, a.size()) if(a[i]=='7') a[i]='0';
	rep(i, 0, b.size()) if(b[i]=='7') b[i]='0';
	
	aa << a, bb << b;
	
	int na, nb, nr;
	aa >> na;
	bb >> nb;
	
	if(op=="+") nr=na+nb;
	else nr=na*nb;
     
    rr << nr;
    rr >> r;
    
    rep(i, 0, r.size()) if(r[i]=='7') r[i]='0';
    
    rr.clear();
    rr << r;
    rr >> nr;
    
    cout << nr << '\n';
    
    return 0;
     
}
