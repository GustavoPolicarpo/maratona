// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Quiz Universitário
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2555

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

int N, K, val[1010], pro[1010];
double pd[1010][1010];

double solve(int i, int k){
	if(i==N) return 0;
	if(pd[i][k]>=0) return pd[i][k];
	
	double ret=0;
	if(k) ret=solve(i+1, k-1)+val[i];
	if(N-i>=k) ret=max(ret, (solve(i+1, k)+val[i])*double(pro[i])/100.0);
	
	return pd[i][k]=ret;
}
int main(){
	
	while(scanf("%d %d", &N, &K)!=EOF){
		
		rep(i, 0, N) scanf("%d", &val[i]);
		rep(i, 0, N) scanf("%d", &pro[i]);
		rep(i, 0, N+2)rep(j, 0, N+2)pd[i][j]=-10.0;
		
		printf("%.2lf\n", solve(0, K));
		
	}
	
	return 0;
	
}
