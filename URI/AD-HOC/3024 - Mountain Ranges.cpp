// Author: Gustavo Policarpo
// Name: Mountain Ranges
// Level: 1
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3024

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
typedef pair <int, int> ii;


int main(){
	int n, x, t[1005], r, resp=1;
	
	cin >> n >> x;
	r = 1;
	
	cin >> t[0];
	rep(i,1,n){
		cin >> t[i];
		
		if(t[i] - t[i-1] <= x){
			r++;
		}
		else
			r = 1;
		resp = max(resp,r);
		
	}
	cout << resp << endl;

	return 0;
}
