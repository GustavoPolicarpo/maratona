#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int n;
double dist[18][18];
double pd[1<<18];
bool mark[1<<18];
vector <ii> pos;

double distance(ii a, ii b){
	return sqrt((double)(a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S));
}

double solve(int mask, int qt){
	if(qt==2*n) return 0;
	if(mark[mask]) return pd[mask]; mark[mask] = true;
	double ret = 1e32;
	rep(i, 0, 2*n){
		rep(j, i+1, 2*n){
			if(mask&(1<<i) || mask&(1<<j)) continue;
			ret = min(ret, solve(mask|(1<<i)|(1<<j), qt+2)+dist[i][j]);
		}
	}
	return pd[mask] = ret;
}

int main(){
	
	int z = 1;
	while(cin >> n and n){
		pos.clear(); ii aux; string s;
		memset(mark, false, sizeof mark);
		rep(i, 0, 2*n){
			cin >> s >> aux.F >> aux.S;
			pos.pb(aux);
		}
		rep(i, 0, 2*n) rep(j, 0, 2*n){
			dist[i][j] = distance(pos[i], pos[j]);
		}
		printf("Case %d: %.2lf\n", z++, solve(0, 0));
	}
	
	
	return 0;
} 
