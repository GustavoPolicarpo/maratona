// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Brincadeira de Criança
// Nível: 6
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1346

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef pair < int, int > ii;
typedef pair < ii, int > iii;

const int INF = 0x3f3f3f3f;

int N, pd[2][200*1000+2];
int ini, fim, mid, yep;
ii v[401];

int solve(int i, int k){
	if(i==N) return pd[i&1][k] = k==mid ? 0 : -INF;
	if(pd[i&1][k]!=-INF) return pd[i&1][k];
	
	int ret=-INF;
	int dif=abs(v[i].F-v[i].S), go=v[i].F+v[i].S;
	
	if(k-dif>=ini) ret=max(ret, solve(i+1, k-dif)+go);
	if(k+dif<=fim) ret=max(ret, solve(i+1, k+dif)+go);
	
	return pd[i&1][k]=ret;
}

ii dp[2][200*1000+2];
ii solve2(int i, int k){
	
	if(i==N-1) return dp[i&1][k] = ii(pd[(i+1)&1][k], i);
	if(dp[i&1][k].F!=-INF) return dp[i&1][k];
	
	ii ret=ii(pd[(i+1)&1][k], i);
	
	int dif=abs(v[i].F-v[i].S), go=v[i].F+v[i].S;
	ii g1=ii(-INF, N), g2=ii(-INF, N);
	
	if(k-dif>=ini) g1=solve2(i+1, k-dif), g1.F+=go;
	if(k+dif<=fim) g2=solve2(i+1, k+dif), g2.F+=go;
	
	if(g1.F > ret.F) ret=g1;
	else if(ret.F==g1.F && v[ret.S].S>v[g1.S].S) ret=g1;
	
	if(g2.F > ret.F) ret=g2;
	else if(ret.F==g2.F && v[ret.S].S>v[g2.S].S) ret=g2;
	
	return dp[i&1][k]=ret;
}


int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while(scanf("%d", &N) !=EOF and N){
		yep=0;
		int sum=0;
		rep(i, 0, N){
			scanf("%d %d", &v[i].F, &v[i].S);
			sum+=abs(v[i].F-v[i].S);
		}	v[N]=ii(-INF, N);
		
		if(N==1 && v[0].F!=v[0].S){
			puts("impossible");
			continue;
		}
		
		ini=0, fim=sum, mid=(ini+fim)/2;
		
		rep(j, ini, fim+2) pd[N&1][j]=-INF;
		for(int j=ini; j<=fim; j++) solve(N, j);
		
		for(int i=N-1; i>=0; i--){
			
			rep(j, ini, fim+2) dp[i&1][j]=ii(-INF, N), pd[i&1][j]=-INF;
			
			for(int j=ini; j<=fim; j++) solve2(i, j);
			for(int j=ini; j<=fim; j++) solve(i, j);
		}
		
		if(pd[0&1][mid]>=0){
			printf("%d discard none\n", pd[0&1][mid]/2);
		}else{
			ii aux=dp[0&1][mid];
			int ans=aux.F, id=aux.S;
			
			if(ans>=0){
				printf("%d discard %d %d\n", ans/2, min(v[id].F, v[id].S), max(v[id].F, v[id].S));
			}else{
				puts("impossible");
			}
		}
		
	}
	
	return 0;
	
}
