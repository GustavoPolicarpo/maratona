// Author: Gustavo Policarpo
// Name: Land Division Tax
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1359

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

int N, mark[404][404], v[404], sum[404];
double F, pd[404][404];

double solve(int i, int j){
	if(i==j) return 0;
	if(mark[i][j]) return pd[i][j]; mark[i][j] = 1;
	double ret = 0x3f3f3f3f;
	rep(k, i, j) ret = min(ret, solve(i, k)+solve(k+1, j)+max(sum[k]-sum[i-1], sum[j]-sum[k])*F);
	return pd[i][j] = ret;
}

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while(scanf("%d %lf", &N, &F) and N){ N++;
	
		rep(i, 0, N+N+2) rep(j, 0, N+N+2) mark[i][j] = 0;
		rep(i, 1, N) scanf("%d", &v[i]), v[i+N-1] = v[i];
		rep(i, 1, N+N) sum[i] = sum[i-1]+v[i];
		
		double ans = 0x3f3f3f3f;
		rep(i, 1, N) ans = min(ans, solve(i, i+N-2));
		printf("%.2lf\n", ans);
		
	}
	
	return 0;
	
}
