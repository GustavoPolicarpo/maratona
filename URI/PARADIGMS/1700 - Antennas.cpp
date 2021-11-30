// Author: Gustavo Policarpo
// Name: Antennas
// Level: 10
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1700

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

int N, pd[2][100010];
int ini, mid, fim;
int v[1010], sum;

int solve(int i, int k){

	if(pd[i&1][k]!=-1) return pd[i&1][k];
	
	if(i>=N){
		return k==mid ? pd[i&1][k]=0 :
				 	    pd[i&1][k]=-INF;
	}
	
	int ret=solve(i+1, k);
	
	if(k-v[i]>=0) ret=max(ret, solve(i+1, k-v[i])+v[i]);
	if(k+v[i]<=fim) ret=max(ret, solve(i+1, k+v[i])+v[i]);
		
	return pd[i&1][k]=ret;
	
}
int main(){
	
	while(scanf("%d", &N) and N){
		
		sum=0;
		rep(i, 0, N) scanf("%d", &v[i]), sum+=v[i];
		
		ini=0, mid=sum/2, fim=sum;
		for(int i=N; i>=0; i--){
			rep(j, ini, fim+2) pd[i&1][j]=-1;
			for(int j=ini; j<=fim; j++){
				solve(i, j);
			}
		}
		
		int ans=pd[0&1][mid]; if(ans==-1) ans=0;
		printf("%d\n", ans/2);
	}
	
	return 0;
	
}
