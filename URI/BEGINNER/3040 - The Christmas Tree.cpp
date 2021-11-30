// Author: Gustavo Policarpo
// Name: The Christmas Tree
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3040

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
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
typedef pair<int,int> ii;
	

bool isPrime(int n){
	if(n<=1) return false;
	if(n==2) return true;
	int f = sqrt(n);
	rep(i, 2, f+1) if(n%i==0) return false;
	return true;
}

int main(){
	
	int t; cin >> t;
	while(t--){
		int h, d, g;
		cin >> h >> d >> g;
		if(h>=200 && h<=300 && d>=50 && g>=150){
			puts("Sim");
		}else{
			puts("Nao");
		}
	}
	
	
	return 0;
}
