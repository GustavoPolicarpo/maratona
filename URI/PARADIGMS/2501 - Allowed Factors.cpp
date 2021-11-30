// Author: Gustavo Policarpo
// Name: Allowed Factors
// Level: 10
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2501

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

ll v[101];

ll solve(int n, int m){
	
    vector <ll> ni(n+2, 0), next_multiple(n+2, 0), ugly(m+2, 0);
    rep(i, 0, n) next_multiple[i]=v[i]; ugly[0] = 1;	
    
	rep(i, 1, m+1){
		ugly[i] = 1LL << 42;
		rep(j, 0, n) ugly[i] = min(ugly[i], next_multiple[j]);
		
		rep(j, 0, n){
			if(ugly[i] == next_multiple[j]){
				ni[j]++;
				next_multiple[j]=ugly[ni[j]]*v[j];
			}
		}
	}
	
	return ugly[m];
}


int main(){
	
	int N, M;
	
	while(scanf("%d %d", &N, &M) and N+M){
		
		rep(i, 0, N) scanf("%lld", &v[i]);
		cout << solve(N, M)	 << '\n';
	    
	}
	
	return 0;
}

