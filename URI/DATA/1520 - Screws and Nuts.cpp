// Author: Gustavo Policarpo
// Name: Screws and Nuts
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1520

//#define gc getchar_unlocked
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
}*/

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main()
{
	int N, x, y, K, l, u;
	while(scanf("%d", &N) !=EOF){
		vector <int> n;
		rep(i, 0, N){
			scanf("%d %d", &x, &y);
			//scanint(x);	scanint(y);
			rep(j, x, y+1){
				n.pb(j);
			}
		}
		sort(n.begin(), n.end());
		scanf("%d", &K);
		//scanint(K);
		l=lower_bound(n.begin(), n.end(), K) -n.begin();
		if(l==n.size()){
			printf("%d not found\n", K);
			continue;
		}
		u=upper_bound(n.begin(), n.end(), K) -n.begin();
		if(u==l) printf("%d not found\n", K);
		else printf("%d found from %d to %d\n", K, l, u-1);
	}




return 0;
}



