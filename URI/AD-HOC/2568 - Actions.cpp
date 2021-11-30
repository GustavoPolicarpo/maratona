// Author: Gustavo Policarpo
// Name: Actions
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2568

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

	int D, I, X, F; cin >> D >> I >> X >> F;
	
	if(D&1){
		if(F&1) cout << I+X << '\n';
		else cout << I << '\n';
	}else{
		if(F&1) cout << I-X << '\n';
		else cout << I << '\n';
	}
    
    return 0;
     
}
