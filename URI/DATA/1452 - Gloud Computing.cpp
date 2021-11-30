// Author: Gustavo Policarpo
// Name: Gloud Computing
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1452

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

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
typedef pair < int, ii > iii;

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}



int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, M, Q, ans; string in;
	while(scanf("%d %d", &N, &M) and N){
		ans = 0;
		set <string> n[N];
		
		rep(i, 0, N){
			scanf("%d", &Q);
			while(Q--){
				cin >> in;
				n[i].insert(in);
			}
		}
		
		while(M--){
			set <int> vis;
			scanf("%d", &Q);
			while(Q--){
				cin >> in;
				rep(i, 0, N){
					if(n[i].count(in) && !vis.count(i))
						ans++, vis.insert(i);
				}
			}
		}
		
		printf("%d\n", ans);
		
	}
	
	return 0;
	
}
