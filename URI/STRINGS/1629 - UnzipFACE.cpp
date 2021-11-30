// Author: Gustavo Policarpo
// Name: UnzipFACE
// Level: 3
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1629

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

int doIt(string &k){
	int qt0 = 0, qt1 = 0;
	rep(i, 0, k.size()){
		if(i&1) qt0 += k[i]-'0';
		else qt1 += k[i]-'0';
	}
	k = "";
	while(qt0) k.pb(qt0%10+'0'), qt0/=10;
	while(qt1) k.pb(qt1%10+'0'), qt1/=10;
	int ret = 0;
	rep(i, 0, k.size()) ret += (k[i]-'0');
	return ret;
}

int main(){
	
	int N;
	while(scanf("%d", &N) and N){
		string k;
		rep(z, 0, N){
			cin >> k; 
			printf("%d\n", doIt(k));
		}
	}
	return 0;
}
