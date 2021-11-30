// Author: Gustavo Policarpo
// Name: Constructions of China
// Level: 2
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1822

#include <bits/stdc++.h>
//#define gc getchar
//#define pc(x) putchar(x);
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>*/

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
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

//typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/*void scanint(int &x){
    register int ccc = gc(); x = 0; int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;


int mark[202][1001], tnc = 0, x, y, z, w, N;
ll pd[202][1001], v[202];

ll solve(int i, int p){
	
	if(i==N) return p*y;
	if(mark[i][p]==tnc) return pd[i][p];
	mark[i][p] = tnc;
	
	ll ret = 1LL << 54;
	if(p>=v[i]){
		for(int j = p; j>=v[i]; j--){
			ret = min(ret, solve(i+1, j)+(p-j)*y+(j-v[i])*w+v[i]*z);
		}
	}else{
		ret = solve(i+1, v[i])+(v[i]-p)*x+(v[i])*z;
	}
	
	return pd[i][p] = ret;
}

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int teste = 1;
	while(scanf("%d", &N) and N){
		
		rep(i, 0, N) scanf("%lld", &v[i]);
		scanf("%d %d %d %d", &x, &y, &z, &w);
		tnc++;
		
		ll ans = solve(1, v[0]) + x*v[0] + v[0]*z;
		printf("Instancia %d\n%lld\n", teste++, ans);
		puts("");
	}
	
	return 0;
}

