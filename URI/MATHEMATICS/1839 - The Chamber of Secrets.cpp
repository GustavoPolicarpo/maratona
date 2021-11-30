// Author: Gustavo Policarpo
// Name: The Chamber of Secrets
// Level: 7
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1839

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, M, mat[51][51], sum[51][51];
ll fat[2501];

void build_sum()
{
	sum[0][0]=mat[0][0];
	rep(i, 1, N) sum[i][0]=sum[i-1][0]+mat[i][0];
	rep(j, 1, M) sum[0][j]=sum[0][j-1]+mat[0][j];
	rep(i, 1, N)
	rep(j, 1, M)
		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mat[i][j];
}
ll fastExp(ll num, int base)
{
	ll ret;
	if(base==0) return 1;
	if(base==1) return num;
	
	if(base%2==0){
		ret=fastExp(num, base/2)%mod;
		return (ret*ret)%mod;
	}
	else{
		return (num*fastExp(num, base-1))%mod;
	}
}
ll combina(int n, int k)
{
	ll num, den, ret;
	num=fat[n];
	den=(fat[n-k]*fat[k])%mod;
	den=fastExp(den, mod-2);
	
	ret=(num*den)%mod;
	
	return ret;
}
int main()
{
	scanf("%d %d", &N, &M);
	fat[0]=1;
	rep(i, 1, N*M+1) fat[i]=(fat[i-1]*i)%mod;
	
	char in[M];
	rep(i, 0, N){
		scanf("%s", &in);
		rep(j, 0, M){
			if(in[j]=='#') mat[i][j]=1;
			else mat[i][j]=0;
		}
	}
	build_sum();
	
	int a, b, c, d;
	while(scanf("%d %d %d %d", &a, &b, &c, &d) !=EOF){
		int C=(c-a+1)*(d-b+1);
		int K=sum[c-1][d-1];
		if(a>1) K-=sum[a-2][d-1];
		if(b>1) K-=sum[c-1][b-2];
		if(a>1 && b>1) K+=sum[a-2][b-2];
		ll out=combina(C, K)-1;
		printf("%lld\n", out);
	}

return 0;
}
