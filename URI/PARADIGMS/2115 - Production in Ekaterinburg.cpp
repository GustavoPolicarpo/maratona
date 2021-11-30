// Author: Gustavo Policarpo
// Name: Production in Ekaterinburg
// Level: 6
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2115

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
typedef pair < ll, int > ii;
typedef pair < double, int > iii;

int main()
{
	int N; 
	while(scanf("%d", &N) !=EOF){ ii n[N];
		
		rep(i, 0, N)
			scanf("%d %d", &n[i].F, &n[i].S);
		
		sort(n, n+N);
		
		ll tempo=n[0].F+n[0].S;
		rep(i, 1, N)
			tempo=max(tempo,n[i].F)+n[i].S;
		
		printf("%lld\n", tempo);			
	}

return 0;
}
