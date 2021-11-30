// Author: Gustavo Policarpo
// Name: Where is my Pen?
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2495

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

ll ver(ll a){
	if(a%4==0) return a;
	if((a+1)%4==0) return 0;
	if((a-1)%4==0) return 1;
	return a+1;
}

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N;
	while(scanf("%d", &N) !=EOF){
		
		ll ans=ver(N); int aux;
		rep(i, 0, N-1){
			scanf("%d", &aux);
			ans^=aux;
		}
		
		printf("%lld\n", ans);
		
	}

	return 0;
	
}
