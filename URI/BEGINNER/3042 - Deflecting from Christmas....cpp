// Author: Gustavo Policarpo
// Name: Deflecting from Christmas...
// Level: 7
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3042

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
	
	
	int m;
	while(cin >> m){
		if(!m) break;
		int p = 1, ans = 0;
		int a, b, c;
		while(m--){
			cin >> a >> b >> c;
			if(a==1 && b==1){
				ans += 2-p;
				p = 2;
			}
			if(a==1 && c==1){
				ans += abs(1-p);
				p = 1;
			}
			if(b==1 && c==1){
				ans += abs(0-p);
				p = 0;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
