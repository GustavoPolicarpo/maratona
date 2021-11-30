// Author: Gustavo Policarpo
// Name: Smider Pan
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2943

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


int n, h[1010];
int pd[1010][1010][2];

int solve(int i, int j, int o){
	if(i==n) return 1;
	int &ret = pd[i][j][o];
	if(ret!=-1) return ret;
	
	if(o==0){
		if(h[i]>h[j] || j==n){
			ret = max(solve(i+1, i, 0), solve(i+1, i, 1))+1;
		}
		ret = max(ret, max(solve(i+1, j, 0), solve(i, j, 1)));
	}
	
	else{
		if(h[i]<h[j] || j==n){
			ret = solve(i+1, i, 1)+1;
		}
		ret = max(ret, solve(i+1, j, 1));
	}
	
	return ret;
}

int main(){
	
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", &h[i]);
	
	memset(pd, -1, sizeof pd);
	printf("%d\n", solve(0, n, 0));
	
	return 0;
}
