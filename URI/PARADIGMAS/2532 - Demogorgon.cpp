// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Demogorgon
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2532

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)

using namespace std;
typedef long long int ll;


int N, P, D, M, dp[4008], ans;

int main(){
	while(scanf("%d %d", &N, &P)!=EOF){
		rep(i, 0, 4008) dp[i] = 0x3f3f3f3f; dp[0] = 0; ans = 0x3f3f3f3f;
		rep(i, 0, N){
			scanf("%d %d", &D, &M);
			for(int j=4004; j>=D; j--){
				if(dp[j-D]==0x3f3f3f3f) continue;
				dp[j] = min(dp[j], dp[j-D]+M);
				if(j>=P) ans = min(ans, dp[j]);
			}
		}
		if(ans>=0x3f3f3f3f) puts("-1");
		else printf("%d\n", ans);
	}
	
	return 0;
}

