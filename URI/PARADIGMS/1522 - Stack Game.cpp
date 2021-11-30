// Author: Gustavo Policarpo
// Name: Stack Game
// Level: 8
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1522

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
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

int N, sum, n[105][3], pd[105][105][105];
bool yep;

int solve(int a, int b, int c)
{
	if(a==N && b==N && c==N){
		yep=true;
		return 1;
	}
	if(a>N || b>N || c>N) return 0;
	if(pd[a][b][c]!=-1) return pd[a][b][c];
	if(yep) return 1;

	if(n[a][0]%3==0)
		pd[a+1][b][c]=solve(a+1, b, c);
		
	if(n[b][1]%3==0)
		pd[a][b+1][c]=solve(a, b+1, c);
		
	if(n[c][2]%3==0)
		pd[a][b][c+1]=solve(a, b, c+1);
		
	if((n[a][0]+n[b][1])%3==0)
		pd[a+1][b+1][c]=solve(a+1, b+1, c);
		
	if((n[a][0]+n[c][2])%3==0)
		pd[a+1][b][c+1]=solve(a+1, b, c+1);
	
	if((n[b][1]+n[c][2])%3==0)
		pd[a][b+1][c+1]=solve(a, b+1, c+1);
		
	if((n[a][0]+n[b][1]+n[c][2])%3==0)
		pd[a+1][b+1][c+1]=solve(a+1, b+1, c+1);
	
	return 0;	
}

int main()
{	
	while(scanf("%d", &N) and N){ sum=0, yep=false, memset(pd, -1, sizeof pd);
		rep(i, 0, N)
			rep(j, 0, 3)
				scanf("%d", &n[i][j]), sum+=n[i][j];
		if(sum%3!=0){
			printf("0\n");
			continue;
		}
		solve(0,0,0);
		if(!yep) printf("0\n");
		else printf("1\n");
	}
return 0;
}
