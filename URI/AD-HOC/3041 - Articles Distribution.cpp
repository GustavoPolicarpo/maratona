// Author: Gustavo Policarpo
// Name: Articles Distribution
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3041

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
	
	
	int n;
	while(cin >> n){
		if(!n) break;
		
		ii a[n]; int ans[n];
		rep(i, 0, n) cin >> a[i].F, a[i].S = i, ans[i] = 0;
		sort(a, a+n);
		reverse(a, a+n);
		
		int p; cin >> p;
		int m = 0;
		while(p){
			int yep = 0;
			rep(i, 0, n){
				if(a[i].F){
					a[i].F--;
					p--;
					ans[a[i].S]++;
					yep = 1;
					if(!p) break;
				}
			}
			if(!yep){
				p = -1;
				break;
			}
			if(!p) break;
		}
		
		if(p==-1) puts("Impossible");
		else{
			sort(ans, ans+n);
			reverse(ans, ans+n);
			rep(i, 0, n) cout << ans[i] << '\n';
		}
	
	}
	
	
	return 0;
}
