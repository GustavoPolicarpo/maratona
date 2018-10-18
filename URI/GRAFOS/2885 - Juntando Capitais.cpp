// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Juntando Capitais
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2885

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;


double dist[101][101];
int n, k;
ii pos[101];
double dp[101][1026];

double solve(){
	double ret = 1e32;
	for(int i=0; i<n; i++) for(int j=0; j<(1<<k); j++) dp[i][j] = 1e32;
	for(int i=0; i<k; i++) dp[i][(1<<i)] = 0;
	for(int mask=0; mask<(1<<k); mask++){
		for(int i=0; i<n; i++){
			for(int s1=mask; s1>0; s1=(s1-1)&mask){
				int s2=mask-s1;
				dp[i][mask] = min(dp[i][mask], dp[i][s1]+dp[i][s2]);
			}
			if(dp[i][mask]<1e30){
				for(int j=k; j<n; j++){
					dp[j][mask] = min(dp[j][mask], dp[i][mask]+dist[i][j]);
				}
			}
		}
	}
	for(int i=0; i<n; i++) ret = min(ret, dp[i][(1<<k)-1]);//, cout << dp[i][(1<<k)-1] << '\n';
	return ret;
}

int main(){
	
	scanf("%d %d", &n, &k);
	rep(i, 0, n) scanf("%d %d", &pos[i].F, &pos[i].S);
	
	rep(i, 0, n) rep(j, 0, n){
		dist[i][j] = sqrt((pos[i].F-pos[j].F)*(pos[i].F-pos[j].F) + (pos[i].S-pos[j].S)*(pos[i].S-pos[j].S));
	}
	rep(k, 0, n) rep(i, 0, n) rep(j, 0, n){
		dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
	}
	
	printf("%.5lf\n", solve());
	
	return 0;
}  
