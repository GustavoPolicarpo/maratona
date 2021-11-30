// Author: Gustavo Policarpo
// Name: Six Flags
// Level: 4
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1487

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

int N, T;
int tempo[101], nota[101], pd[101][601] ;

int solve(int i, int c)
{
	if(i==N) return 0;
	if(pd[i][c]!=-1) return pd[i][c];
	int ret = solve(i+1, c);
	if(c-tempo[i]>=0) 
		ret = max(ret, solve(i, c-tempo[i])+nota[i]);
	return pd[i][c]=ret;			
}

int main()
{
	//freopen("out.txt", "w", stdout);
	int z=1;
	while(scanf("%d %d", &N, &T) && N+T){
		int t, n;
		memset(pd, -1, sizeof pd);
		rep(i, 0, N){
			scanf("%d %d", &t, &n);
			tempo[i]=t, nota[i]=n;
		}
		int ans=solve(0, T);
		printf("Instancia %d\n%d\n\n", z, ans);
		z++;
	}
	

return 0;
}

