// Author: Gustavo Policarpo
// Name: Strawberry Candies
// Level: 7
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2524

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

int N, M, b[1010], pd[1010][1010];

int solve(int i, int mod){
	if(i==M){
		if(mod==0) return 0;
		return -INF;
	}
	if(pd[i][mod]!=-1) return pd[i][mod];
	
	pd[i][mod]=solve(i+1, mod);
	
	pd[i][mod]=max(pd[i][mod], solve(i+1, (mod+b[i])%N)+1);
	
	return pd[i][mod];
}
int main(){
	
	while(scanf("%d %d", &N, &M)!=EOF){
		rep(i, 0, M){
			scanf("%d", &b[i]);
			rep(j, 0, N){
				pd[i][j]=-1;
			}
		}
		printf("%d\n", solve(0, 0));
	}
	
	return 0;
	
}
