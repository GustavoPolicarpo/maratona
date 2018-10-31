// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Velhas Balanças
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2895

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair < ll, ll >  ii;


int main(){
	
	int dp[2050]; memset(dp, 0x3f3f3f3f, sizeof dp);
	rep(i, 0, 12) dp[1<<i] = 1;
	
	rep(i, 1, 2049){
		if(dp[i]==0x3f3f3f3f) continue;
		rep(j, 1, 2049){
			if(j-i>=0 && dp[j-i]!=0x3f3f3f3f)
				dp[j] = min(dp[j], dp[j-i]+dp[i]);
		}
		for(int j=2048; j>0; j--){
			if(j+i<=2048 && dp[j+i]!=0x3f3f3f3f)
				dp[j] = min(dp[j], dp[j+i]+dp[i]);
		}
	}
	
	int T; cin >> T;
	while(T--){
		int N; cin >> N;
		cout << dp[N] << '\n';
	}
	
	
}
