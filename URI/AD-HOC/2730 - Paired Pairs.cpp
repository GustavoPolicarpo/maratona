// Author: Gustavo Policarpo
// Name: Paired Pairs
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2730

#pragma comment(linker, "/stack:200000000")                                     
#pragma GCC optimize("Ofast")                                                   
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")   
#define _CRT_SECURE_NO_WARNINGS          
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

typedef long long int ll;
typedef pair <int, int> ii;




int main(){
	
	int N;
	while(scanf("%d", &N) !=EOF){
		if(!N) break;
		ll A[N], B[N];
		rep(i, 0, N) scanf("%lld", &A[i]);
		rep(i, 0, N) scanf("%lld", &B[i]);
		set <ii> st; int ans = 0;
		rep(i, 0, N){
			rep(j, 0, N){
				ll gc = __gcd(A[i], B[j]);
				if(gc==1 && !st.count(ii(A[i], B[j]))){
					st.insert(ii(A[i], B[j]));
					ans++;
					if(A[i]!=B[j]){
						if(!st.count(ii(B[j], A[i]))){
							ans++;
							st.insert(ii(B[j], A[i]));
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
	
	
	return 0;
}
