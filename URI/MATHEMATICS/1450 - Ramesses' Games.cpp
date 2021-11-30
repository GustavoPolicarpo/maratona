// Author: Gustavo Policarpo
// Name: Ramesses' Games
// Level: 9
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1450

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
typedef pair < double, int > iii;
 
int N, pd[20][3][1<<16];
struct bloco{
	int l[3	];
};
bloco n[20];

int solve(int i, int lado, int k)
{
	int m=__builtin_popcount(k);
	if(m==N) return 0;
	int &p = pd[i][lado][k];
	if(p!=-1) return p;
	int ret=0;
	
	if(lado==0){
		rep(j, 0, N){
			if(k&(1<<j)) continue;
			if(n[j].l[0]<=n[i].l[1] && n[j].l[1]<=n[i].l[2])
				ret=max(ret, solve(j, 2, k|(1<<j))+n[j].l[2]);
			if(n[j].l[1]<=n[i].l[1] && n[j].l[2]<=n[i].l[2])
				ret=max(ret, solve(j, 0, k|(1<<j))+n[j].l[0]);
			if(n[j].l[0]<=n[i].l[1] && n[j].l[2]<=n[i].l[2])
				ret=max(ret, solve(j, 1, k|(1<<j))+n[j].l[1]);
		}
	}
	else if(lado==1){
		rep(j, 0, N){
			if(k&(1<<j)) continue;
			if(n[j].l[0]<=n[i].l[0] && n[j].l[1]<=n[i].l[2])
				ret=max(ret, solve(j, 2, k|(1<<j))+n[j].l[2]);
			if(n[j].l[1]<=n[i].l[0] && n[j].l[2]<=n[i].l[2])
				ret=max(ret, solve(j, 0, k|(1<<j))+n[j].l[0]);
			if(n[j].l[0]<=n[i].l[0] && n[j].l[2]<=n[i].l[2])
				ret=max(ret, solve(j, 1, k|(1<<j))+n[j].l[1]);
		}
	}
	else if(lado==2){
		rep(j, 0, N){
			if(k&(1<<j)) continue;
			if(n[j].l[0]<=n[i].l[0] && n[j].l[1]<=n[i].l[1])
				ret=max(ret, solve(j, 2, k|(1<<j))+n[j].l[2]);
			if(n[j].l[1]<=n[i].l[0] && n[j].l[2]<=n[i].l[1])
				ret=max(ret, solve(j, 0, k|(1<<j))+n[j].l[0]);
			if(n[j].l[0]<=n[i].l[0] && n[j].l[2]<=n[i].l[1])
				ret=max(ret, solve(j, 1, k|(1<<j))+n[j].l[1]);
		}
	}
	return p=ret;
	
}

int main()
{
	int T; cin >> T; //n[0].l[0]=INF, n[0].l[1]=INF, n[0].l[2]=INF;
	while(T--){
		scanf("%d", &N); 
		rep(i, 0, N){
			scanf("%d %d %d", &n[i].l[0], &n[i].l[1], &n[i].l[2]);		
			sort(n[i].l, n[i].l+3);
		}
		memset(pd, -1, sizeof pd);
		int out=0;
		rep(i, 0, N){
			out=max(out, solve(i, 0, 1<<i)+n[i].l[0]);
			out=max(out, solve(i, 1, 1<<i)+n[i].l[1]);
			out=max(out, solve(i, 2, 1<<i)+n[i].l[2]);
		}
		printf("%d\n", out);
	}
		
return 0;
} 
