// Author: Gustavo Policarpo
// Name: Help Vânia
// Level: 4
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2498

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

int pd[1010][55], p[1010], v[1010], n, m;


int solve(int i, int c){
	
	if(i==n) return 0;
	if(pd[i][c]!=-1) return pd[i][c];
	
	int ret=0;
	if(c-p[i]>=0) ret=solve(i+1, c-p[i])+v[i];
	
	ret=max(ret, solve(i+1, c));
	
	return pd[i][c]=ret;
	
}

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int z=1;
	while(scanf("%d %d", &n, &m) and n+m){
		
		rep(i, 0, n) scanf("%d %d", &p[i], &v[i]);
		memset(pd, -1, sizeof pd);
		
		int ans=solve(0, m); if(ans==INF) ans=0;
		printf("Caso %d: %d\n", z++,  ans);
		
	}


	return 0;
	
}
