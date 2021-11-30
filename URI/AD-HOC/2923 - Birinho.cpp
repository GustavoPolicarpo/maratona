// Author: Gustavo Policarpo
// Name: Birinho
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2923

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;


int main(){
	
	double T, A, W, C;
	while(cin >> T >> A >> W >> C){
		T = A/T*100;
		if(T>=C){
			puts("critical");
		}
		else if(T>=W){
			puts("warning");
		}
		else{
			puts("OK");
		}
	}	
}
