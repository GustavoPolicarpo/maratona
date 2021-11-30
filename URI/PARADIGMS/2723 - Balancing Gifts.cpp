// Author: Gustavo Policarpo
// Name: Balancing Gifts
// Level: 7
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2723

#include<bits/stdc++.h>

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

int pd[10010][6], mark[10010][6], cnt = 1;
int n, v[10010], yep;

int solve(int i, int d){
	if(yep) return 2;
	if(d > 5) return 1;
	if(i==n) return yep = 2;
	
	if(mark[i][d]==cnt) return pd[i][d];
	mark[i][d] = cnt;
	int ret = max(solve(i+1, d+v[i]), solve(i+1, abs(d-v[i])));
	return pd[i][d] = ret;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int T; cin >> T;
	
	while(T--){
		scanf("%d", &n); cnt++; yep = 0;
		rep(i, 0, n) scanf("%d", &v[i]);
		
		solve(0, 0);
		
		yep == 2 ? puts("Feliz Natal!") : puts("Ho Ho Ho!");
	}

	
	return 0;
	
}
