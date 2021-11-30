// Author: Gustavo Policarpo
// Name: Airport
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2227

#define gc getchar_unlocked
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
#define MAXN 100001
#define mod 1000000007
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}
*/

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);




int main()
{
	int A, V, z=1;
	while(scanf("%d %d", &A, &V) and A+V){
		int n[A+1], u, v, ans=-1; memset(n, 0, sizeof n);
		while(V--){
			scanf("%d %d", &u, &v);
			n[u]++, n[v]++;
			ans=max(ans, max(n[u], n[v]));
		}
		printf("Teste %d\n", z++); bool yep=false;
		rep(i, 1, A+1){
			if(n[i]==ans){
				printf("%d ", i);
			}
		}
		printf("\n\n");
	}
	
	return 0;	
}



