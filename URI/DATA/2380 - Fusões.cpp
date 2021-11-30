// Author: Gustavo Policarpo
// Name: Fusões
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2380

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F

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


int N, K, pset[100010];

int findset(int x){
	if(x!=pset[x]) pset[x]=findset(pset[x]);
	return pset[x];
}
void unionset(int x, int y){
	x=findset(x), y=findset(y);
	if(x==y) return;
	pset[x]=y;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d %d", &N, &K);
	rep(i, 1, N+1) pset[i]=i;
	
	char op; int u, v;
	while(K--){
		scanf(" %c %d %d", &op, &u, &v);
		if(op=='F') unionset(u, v);
		else{
			findset(u)==findset(v) ?
			puts("S") :
			puts("N");
		}
	}
	
	return 0;
	
}
