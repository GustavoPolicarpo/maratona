// Author: Gustavo Policarpo
// Name: Child Play
// Level: 10
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1346

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < ll, ii > iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL<<58;

int N, pd[404][2020];
int ini=0, fim=2000, mid=1000, jump;
ii v[404];

int solve(int i, int k){
	if(i==N) return k==mid ? 0 : -INF;
	if(pd[i][k]!=-1) return pd[i][k];
	
	int ret=-INF;
	if(i==jump) ret=solve(i+1, k);
	int goa=k-v[i].F+v[i].S, gob=k+v[i].F-v[i].S, go=v[i].F+v[i].S;
	
	if(goa>=0&&goa<=fim) ret=max(ret, solve(i+1, goa)+go);
	if(gob>=0&&gob<=fim) ret=max(ret, solve(i+1, gob)+go);
	
	return pd[i][k]=ret;
}
int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while(scanf("%d", &N) and N){
		
		rep(i, 0, N){
			scanf("%d %d", &v[i].F, &v[i].S);
			rep(j, 0, fim+4) pd[i][j]=-1;
		}
		
		if(N==1 && v[0].F!=v[0].S){
			puts("impossible");
			continue;
		}
		
		sort(v, v+N); jump=-1;
		
		int ans=solve(0, mid);
		if(ans>=0){
			printf("%d discard none\n", ans/2);
		}else{
			int id;
			rep(i, 0, N){
				jump=i;
				rep(j, 0, N)
				rep(k, 0, fim+4)
					pd[j][k]=-1;
				int aux=solve(0, mid);
				if(aux>ans){
					ans=aux;
					id=i;
				}
			}
			if(ans>=0){
				printf("%d discard %d %d\n", ans/2, min(v[id].F, v[id].S), max(v[id].F, v[id].S));
			}else{
				puts("impossible");
			}
		}
	}
	
	
	return 0;
	
}
