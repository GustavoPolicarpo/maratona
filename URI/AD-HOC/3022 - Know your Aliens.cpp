// Author: Gustavo Policarpo
// Name: Know your Aliens
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3022

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define REP(i,a,b) for( int i = (int) a; i <= (int) b; i++ )
#define PER(i,a,b) for( int i = (int) a; i >= (int) b; i-- )
#define F first
#define S second
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }
 
using namespace std;
 
typedef long long int ll;
typedef pair <int, int> ii;
const int MAX = 2e3+3;
const int mod = 1e9+7;

string S;
vector <ll> v;

int main(){
	
	cin >> S;
	
	rep(i, 1, S.size()){
		if(S[i] != S[i-1]){
			v.pb((ll)-((i+1)*2-1));
		}
	}
	
	vector <ll> e; e.pb(1LL);
	rep(i, 0, v.size()){
		vector <ll> ne;
		ne.pb(1LL);
		rep(j, 1, e.size()){
			ne.pb(e[j-1]*v[i]+e[j]);
		}
		ne.pb(e[e.size()-1]*v[i]);
		swap(e, ne);
	}
	
	ll val = 0, g = e.size()-1, ex = 1;
	rep(i, 0, g) ex*=2;
	rep(i, 0, e.size()){
		val = val + ex*e[i];
		ex/=2;
	}
	
	
	ll lav = (S[0]=='A'?-1:1);
	val = val / abs(val);
	
	if(lav!=val){
		rep(i, 0, e.size()){
			e[i] = e[i]*-1;
		}
	}
	
	printf("%lld\n", g);
	rep(i, 0, e.size()){
		if(i) printf(" ");
		printf("%lld", e[i]);
	}	printf("\n");

	
	return 0;
}
