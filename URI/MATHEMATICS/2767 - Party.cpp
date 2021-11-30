// Author: Gustavo Policarpo
// Name: Party
// Level: 7
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2767

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )

using namespace std;

typedef long long int ll;

int main(){
	
	int N, M, K;
	while(cin >> N >> M >> K){
		int A[N], B[M], F[K]; ll ans = 0;
		memset(F, 0, sizeof F);
		rep(i, 0, N) cin >> A[i], F[A[i]%K]++;
		rep(i, 0, M) cin >> B[i], ans+=F[(K-B[i]%K)%K];
		cout << ans << '\n';
	}
	
	return 0;
}
