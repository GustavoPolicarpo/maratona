// Author: Gustavo Policarpo
// Name: Maria's Cakes
// Level: 1
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1608

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
	int T; cin >> T;
	while(T--){
		int D, I, B; cin >> D >> I >> B;
		int i[I], b[B], cb[B];
		memset(b, 0, sizeof b);
		rep(j, 0, I)
			scanf("%d", &i[j]);
		int Q, q, n, mq=0;
		rep(j, 0, B){
			scanf("%d", &Q);
			rep(k, 0, Q){
				scanf("%d %d", &n, &q);
				b[j]+=i[n]*q;
			}
			cb[j]=D/b[j];
			if(cb[j]>mq)
				mq=cb[j];
		}
		printf("%d\n", mq);		
	}

return 0;
}

