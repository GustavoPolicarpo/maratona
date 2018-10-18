// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Baile de Formatura
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1616

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

int N, M, pd[1001][1001];

ll solve(int i, int j){
	
	if(i==0){
		if(j>0) return 0;
		return 1;
	}
	int &p=pd[i][j];
	if(p!=-1) return p;
	
	ll ret=solve(i-1, j)*(M-j);
	if(j>0) ret+=solve(i-1, j-1)*j;
	
	return p=ret%mod;
}
int main()
{	

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(scanf("%d %d", &N, &M) and N+M){
		memset(pd, -1, sizeof pd);
		printf("%lld\n", solve(N, M));
	}
		
return 0;
}


