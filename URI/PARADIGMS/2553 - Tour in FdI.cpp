// Author: Gustavo Policarpo
// Name: Tour in FdI
// Level: 7
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2553

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;


int N, v[44], a[44], pd[44][822][822];


int solve(int i, int V, int A){
	
	if(i==N) return 0;
	if(pd[i][V][A]!=-1) return pd[i][V][A];
	
	int ret=0;
	if(V+v[i]>=0 && A+a[i]>=0){
		ret=max(ret, solve(i+1, V+v[i], A+a[i])+1);
	}
	
	ret=max(ret, solve(i+1, V, A));
	
	return pd[i][V][A]=ret;
	
}

int main()
{
	
	while(scanf("%d", &N)!=EOF){
		
		
		int ver=0, ama=0, V, A;
		scanf("%d %d", &V, &A);
		
		rep(i, 0, N){
			scanf("%d %d", &v[i], &a[i]);
			if(v[i]>0) ver+=v[i];
			if(a[i]>0) ama+=a[i];
		}
		
		//rep(i, 0, N+2) rep(j, 0, ver+2) rep(k, 0, ama+2) pd[i][j][k]=-1;
		memset(pd, -1, sizeof pd);
		
		printf("%d\n", solve(0, V, A));
		
	}


	return 0;
	
}
