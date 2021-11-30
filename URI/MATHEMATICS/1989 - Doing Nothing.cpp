// Author: Gustavo Policarpo
// Name: Doing Nothing
// Level: 4
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1989

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

int main()
{
	ull sum[100002], in, out, N, M;
	while(scanf("%lld %lld", &N, &M)!=EOF){
		if(N==-1 && M==-1) break;
		sum[0]=0, out=0;
		rep(i, 1, N+1){
			scanf("%lld", &in);
			sum[i]=sum[i-1]+in*M;	
			out+=sum[i];
		}
		printf("%lld\n", out);
	}
	
	
return 0;
}
