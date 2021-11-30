// Author: Gustavo Policarpo
// Name: Festival
// Level: 8
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2881

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

struct use{
	int t, i, f, o;	
};

vector <use> v; int N;
int dp[1026][1026];
int bit[86402][1026];

int query(int x, int m){
	x++; int ret = -INF;
	for(; x<86402; x+=x&-x) ret = max(ret, bit[x][m]);
	return ret;
}

void update(int x, int m, int v){
	x++;
	for(; x>0; x-=x&-x) bit[x][m] = max(bit[x][m], v);
	return;
}

int sol(){
	memset(bit, -INF, sizeof bit);
	memset(dp, -INF, sizeof dp);
	dp[v.size()][(1<<N)-1] = 0;
	
	int ans = -1;
	for(int i=v.size()-1; i>=0; i--){
		rep(j, 0, 1<<N){
			int mg = j|(1<<v[i].t), ad = v[i].o;
			int qr = query(v[i].f, mg);
			dp[i][j] = max(dp[v.size()][mg], qr)+ad;
			update(v[i].i, j, dp[i][j]);;
		}
		ans = max(ans, dp[i][0]);
	}
	
	return ans;
}

bool cmp(use a, use b){
	return a.i < b.i;	
}

int main(){
	
	scanf("%d", &N); use aux; int M;
	rep(i, 0, N){
		scanf("%d", &M); aux.t = i;
		rep(j, 0, M){
			scanf("%d %d %d", &aux.i, &aux.f, &aux.o);
			v.pb(aux);
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	
	int ans = sol();
	cout << ans << '\n';
	
	
	return 0;
}  
