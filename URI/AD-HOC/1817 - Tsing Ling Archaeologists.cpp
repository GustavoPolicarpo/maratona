// Author: Gustavo Policarpo
// Name: Tsing Ling Archaeologists
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1817

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
#define pf push_front
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

int N, M, pd[101][1001];
string A, B;

int solve(int i, int j){
	if(i==A.size()) return 1;
	if(j==B.size()) return 0;
	if(pd[i][j]!=-1) return pd[i][j];
	
	int ret=solve(i, j+1);
	if(A[i]==B[j]) ret = ret+solve(i+1, j+1);
	
	return pd[i][j]=ret;
}

int main()
{
	
	int z=1;
	while(scanf("%d %d", &N, &M) and N+M){
		cin >> A >> B; memset(pd, -1, sizeof pd);
		printf("Instancia %d\n%d\n\n", z++, solve(0, 0));
	}
	
	
	

	return 0;
}


