// Author: Gustavo Policarpo
// Name: Cheddar
// Level: 10
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2527

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < ll, ii > iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL<<58;

typedef pair <long double, long double> pld;

int N, V;

long double dp[1010][6060];
long double solve2(int i, int sum){
	
	if(i==N){
		if(sum>=V) return 1.0;
		return 0.0;
	}
	
	if(dp[i][sum]>=0.0) return dp[i][sum];
	
	dp[i][sum]=0.0;
	rep(k, 1, 7){
		dp[i][sum]+=solve2(i+1, sum+k)*1.0/6.0;
	}
	
	return dp[i][sum];
}

int main(){
	
	while(scanf("%d %d", &N, &V)!=EOF){
		
		if(N>=V){
			printf("%.4lf\n", 1.0000);
			continue;
		}else if(N*6<V){
			printf("%.4lf\n", 0.0000);
			continue;
		}
		
		rep(i, 0, N+2) rep(j, 0, N*6+10) dp[i][j]=-10.0;
		
		long double ans=solve2(0, 0);
		//cout << ans.F << " " << ans.S << '\n';
		printf("%.4LF\n", ans);
		
	}
	
	return 0;
	
}
