// Author: Gustavo Policarpo
// Name: Dengue 2.0
// Level: 9
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2810

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int N, M;
double pd1[1<<10+2][5], pd2[1<<10+2][5][12];
ii posM[5];
ii posN[10];

double distan(ii a, ii b){
	return sqrt((double)(a.F-b.F)*(a.F-b.F) + (double)(a.S-b.S)*(a.S-b.S));
}

double solve2(int mask, int i, int c){
	if(mask==0) return ( c==N ? distan(posM[i], posM[i]) : distan(posN[c], posM[i]) );
	if(pd2[mask][i][c]>-0.5) return pd2[mask][i][c];
	double ret = 1LL << 42;
	for(int j=0; j<N; j++){
		if(mask&(1<<j)){
			double custo = ( c==N ? distan(posM[i], posN[j]) : distan(posN[c], posN[j]) );
			ret = min(ret, solve2(mask&~(1<<j), i, j)+custo);
		}
	}
	return pd2[mask][i][c] = ret;
}

double solve1(int mask, int i){
	if(mask==((1<<N)-1)) return 0.0;
	if(i==M) return 1LL << 42;
	if(pd1[mask][i]>-0.5) return pd1[mask][i];
	double ret = 1LL << 42;
	for(int j=0; j<(1<<N); j++){
		if(mask&j) continue;
		ret = min(ret, solve1(mask|j, i+1)+solve2(j, i, N));
	}
	return pd1[mask][i] = ret;
}

int main(){
	
	scanf("%d %d", &N, &M);
	rep(i, 0, M) scanf("%d %d", &posM[i].F, &posM[i].S);
	rep(i, 0, N) scanf("%d %d", &posN[i].F, &posN[i].S);
	
	rep(i, 0, (1<<N)) rep(j, 0, M){
		pd1[i][j] = -1.0;
		rep(k, 0, N+1)
			pd2[i][j][k] = -1.0;
	}
	double ans = solve1(0, 0);
	printf("%.2lf\n", ans);

	return 0;
}
