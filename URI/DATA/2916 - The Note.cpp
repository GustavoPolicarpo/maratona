// Author: Gustavo Policarpo
// Name: The Note
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2916

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


int N, K, aux;
int arr[1000010];
const ll m2 = 1LL << 60;
const int m1 = 1e9+7;

int main(){
	
	while(scanf("%d %d", &N, &K)!=EOF){
		rep(i, 0, N) scanf("%d", &arr[i]);
		sort(arr, arr+N);
		ll ans = 0;
		for(int i=N-1; i>N-1-K; i--){
			ans = (ans + arr[i]);
			if(ans > m2) ans %= m1;
		}
		printf("%lld\n", ans%m1);
	}	
	
	

	return 0;
} 
