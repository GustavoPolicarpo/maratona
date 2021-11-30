// Author: Gustavo Policarpo
// Name: Assembling
// Level: 6
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2106

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

int N, mat[25][25], pd[700000], aux;

int solve(int k)
{
	if(pd[k]!=-1) return pd[k];
	
	int cont=0, aux=k;
	while(aux>0){
		cont+=(aux&1);
		aux=aux>>1;
	}
	if(cont==N) return 0;
	
	int ans=INF;
	rep(i, 0, N){
		if(!((1<<i+1)&k))
			ans=min(ans, solve(k|(1<<i+1))+mat[i][cont]);
	}
	return pd[k]=ans;
	
}
int main()
{
	while(scanf("%d", &N) and N){

		memset(pd, -1, sizeof pd);
				
		rep(i, 0, N)
			rep(j, 0, N)
				scanf("%d", &mat[i][j]);		
		
		int out=solve(0);
		//rep(i, 0, N)
		//	out=min(out, solve(i, 1<<i+1)+mat[i][0]);
						
		printf("%d\n", out);			 		
	}
	
return 0;	
}
