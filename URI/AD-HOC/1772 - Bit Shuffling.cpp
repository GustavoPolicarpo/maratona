// Author: Gustavo Policarpo
// Name: Bit Shuffling
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1772

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
typedef pair < ii, int > iii;


int main()
{

	ll N, M;
	
	while(scanf("%lld %lld", &N, &M) and N+M){
		
		ll maior=N, menor=N, A, B, a, b;
		while(M--){
			scanf("%lld %lld", &A, &B);
			
			a=N&(1LL<<A); a/=(1LL<<A);
			b=N&(1LL<<B); b/=(1LL<<B);
			
			if(a==b) continue;
			
			N^=(1LL<<A);
			N^=(1LL<<B);
			
			maior=max(N, maior);
			menor=min(N, menor);
		}
		
		printf("%lld %lld %lld\n", N, maior, menor);
		
	}
	
	return 0;
	
}
