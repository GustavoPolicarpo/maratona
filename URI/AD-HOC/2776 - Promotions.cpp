// Author: Gustavo Policarpo
// Name: Promotions
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2776

#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = int(a); i < int(b); i++)

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

int dp[2001];
int N;

int main(){
    int M;
    while(scanf("%d%d", &N, &M) != EOF){
    	rep(j, 0, M+1) dp[j] = -1; dp[0] = 0;
        rep(i, 0, N){
        	int peso, ganho;
        	scanf("%d %d", &peso, &ganho);
			rep(j, peso, M+1){
	        	if(dp[j-peso]==-1) continue;
	        	dp[j] = max(dp[j], dp[j-peso]+ganho);
			}
		}
        cout << dp[M] << "\n";
    }
    return 0;
}
