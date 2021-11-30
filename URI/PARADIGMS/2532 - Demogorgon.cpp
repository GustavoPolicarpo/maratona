// Author: Gustavo Policarpo
// Name: Demogorgon
// Level: 6
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2532

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

int N, P;
int d[1010], m[1010], pd[1010][2020];

int solve(int i, int l){
	if(l<=0) return 0;
	if(i==N) return INF;
	if(pd[i][l]!=-1) return pd[i][l];
	
	int ret=solve(i+1, l);
	ret=min(ret, solve(i+1, l-d[i])+m[i]);
	
	return pd[i][l]=ret;
}
int main(){
	
	while(scanf("%d %d", &N, &P) !=EOF){
		
		rep(i, 0, N){
			scanf("%d %d", &d[i], &m[i]);
			rep(j, 0, P+2) pd[i][j]=-1;
		}
		
		int ans=solve(0, P);
		if(ans>=INF) ans=-1;
		
		printf("%d\n", ans);
		
	}
	
	
	return 0;
	
}
