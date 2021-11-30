// Author: Gustavo Policarpo
// Name: Height
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1566

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int main()
{
	int T; scanf("%d", &T);
	while(T--){
		int N, aux; scanf("%d", &N);
		vector <int> h;
		rep(i, 0, N){
			scanf("%d", &aux);
			h.pb(aux);
		}
		sort(h.begin(), h.end());
		rep(i, 0, N-1)
			printf("%d ", h[i]);
		printf("%d\n", h[N-1]);
	}

return 0;
}
