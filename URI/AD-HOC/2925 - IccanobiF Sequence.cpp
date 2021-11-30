// Author: Gustavo Policarpo
// Name: IccanobiF Sequence
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2925

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

typedef long long int ll;
typedef pair<int, int> ii;

int main(){
	
	ll fib[66], ans[66];
	fib[0] = 0; fib[1] = 1; fib[2] = 2;
	ans[0] = 0, ans[1] = 1, ans[2] = 2;
	for(int i=3; i<=60; i++){
		fib[i] = fib[i-1]+fib[i-2];
		ans[i] = fib[i];
		if(fib[i]>=10){
			ll o = 0;
			while(fib[i]){
				o*=10;
				o+=fib[i]%10;
				fib[i]/=10;
			}
			fib[i] = o;
		}
	}
	
	int x;
	while(cin >> x){
		cout << ans[x] << '\n';
	}
}
