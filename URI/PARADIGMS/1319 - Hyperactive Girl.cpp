// Author: Gustavo Policarpo
// Name: Hyperactive Girl
// Level: 9
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1319

#include <bits/stdc++.h>
#define gc getchar
#define pc(x) putchar(x);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void scanint(int &x){
    register int ccc = gc(); x = 0; int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;


int N, M, mod;
int pd[101][101];
ii t[101];


bool cmp(ii a, ii b){
	if(a.F!=b.F) return a.F<b.F;
	return a.S>b.S;
}


int solve(int i, int last){
	
	if(t[i].S==M) return 1;
	if(pd[i][last]!=-1) return pd[i][last];
	
	int ret=0;
	rep(j, i+1, N){
		if(t[j].F<=t[i].S && t[j].S>t[i].S && (t[j].F>t[last].S || i==last)){
			ret+=solve(j, i);
			ret%=mod;
		}
	}
	
	return pd[i][last]=ret;
}

int main()
{
	ios_base::sync_with_stdio(false);

	mod=1e8;
	while(cin >> M >> N and N){
		
		rep(i, 0, N) cin >> t[i].F >> t[i].S;
		sort(t, t+N, cmp);
		
		memset(pd, -1, sizeof pd);
		
		int ans=0;
		rep(i, 0, N){
			if(t[i].F==0){
				ans+=solve(i, i);
				ans%=mod;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}

