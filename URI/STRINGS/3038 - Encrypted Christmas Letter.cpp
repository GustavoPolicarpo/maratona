// Author: Gustavo Policarpo
// Name: Encrypted Christmas Letter
// Level: 4
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3038

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
	
	string f;
	while(getline(cin, f)){
		rep(i, 0, f.size()){
			if(f[i]=='@') f[i] = 'a';
			if(f[i]=='&') f[i] = 'e';
			if(f[i]=='!') f[i] = 'i';
			if(f[i]=='*') f[i] = 'o';
			if(f[i]=='#') f[i] = 'u';
		}
		cout << f << '\n';
	}
	
	
	return 0;
}
