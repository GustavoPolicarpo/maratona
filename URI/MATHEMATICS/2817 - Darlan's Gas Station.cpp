// Author: Gustavo Policarpo
// Name: Darlan's Gas Station
// Level: 8
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2817

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int sum[1010][1010][3];
char mat[1010][1010];
int n, m, l;

int val(int i, int j, int op){
	if(op==0) return (mat[i][j]=='C'?25:12);
	if(op==1) return (mat[i][j]=='C');
	if(op==2) return (mat[i][j]=='M');
}

void buildsum(int op){
	sum[0][0][op] = val(0, 0, op);
	rep(i, 1, n) sum[i][0][op] = sum[i-1][0][op] + val(i, 0, op);
	rep(j, 1, m) sum[0][j][op] = sum[0][j-1][op] + val(0, j, op);
	rep(i, 1, n) rep(j, 1, m) sum[i][j][op] = sum[i-1][j][op] + sum[i][j-1][op] + val(i, j, op) - sum[i-1][j-1][op];
}

int query(int i, int j, int l, int op){
	int ret = sum[i+l-1][j+l-1][op];
	if(i) ret-=sum[i-1][j+l-1][op];
	if(j) ret-=sum[i+l-1][j-1][op];
	if(i&&j) ret+=sum[i-1][j-1][op];
	return ret;
}

int main(){
	
	cin >> n >> m;
	rep(i, 0, n) rep(j, 0, m) cin >> mat[i][j];
	
	buildsum(0);
	buildsum(1);
	buildsum(2);
	
	int ans = -1;
	cin >> l;
	
	rep(i, 0, n-l+1){
		rep(j, 0, m-l+1){
			int v = query(i, j, l, 0);
			int v1 = query(i, j, l, 1);
			int v2 = query(i, j, l, 2);
			if(v2>0 && v1>0){
				ans = max(ans, v);
			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
