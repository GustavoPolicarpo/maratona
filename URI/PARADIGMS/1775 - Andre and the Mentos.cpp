// Author: Gustavo Policarpo
// Name: Andre and the Mentos
// Level: 6
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1775

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

int n[1000], pd[1000][1000];

int solve(int i, int k)
{
	if(i>k) return 0;
	if(pd[i][k]!=-1) return pd[i][k];
	int ret;
	if(n[i]==n[k])
		ret=solve(i+1, k-1)+1;
	else
		ret=min(solve(i+1, k), solve(i, k-1))+1;
	
	return pd[i][k]=ret;			
}
int main()
{
	int T, z=1; cin >> T;
	while(T--){
		int N; cin >> N; 
		memset(pd, -1, sizeof(pd));
		rep(i, 0, N)
			scanf("%d", &n[i]);
		int i=0, k=N-1, cont;
		
		cont=solve(i, k);
		printf("Caso #%d: %d\n", z++, cont);
	}
	
return 0;
}
