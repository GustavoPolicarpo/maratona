// Author: Gustavo Policarpo
// Name: Leverage MDT
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3023

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define REP(i,a,b) for( int i = (int) a; i <= (int) b; i++ )
#define PER(i,a,b) for( int i = (int) a; i >= (int) b; i-- )
#define F first
#define S second
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }
 
using namespace std;
 
typedef long long int ll;
typedef pair <int, int> ii;
const int MAX = 1e3+3;
char m[MAX][MAX];
int b[MAX][MAX];
int N, M, ans;

void update(int i, int j, int x) {
	for(; i <= N; i += i&-i)
		b[i][j] = min(b[i][j], x);
}

int query(int i, int j) {
	int ret = MAX;
	for(; i; i -= i&-i)
		ret = min(ret, b[i][j]);
	return ret;
}

int search(int ini, int fim, int i, int j) {
	int m = (ini+fim+1)/2;
	if(ini == fim) return m;
	if(i+m-1 <= N && query(i+m-1, j) >= m) return search(m, fim, i, j);
	return search(ini, m-1, i, j);
}


int main(){
	ans++;
	scanf("%d%d", &N, &M);
	REP(i, 0, N) REP(j, 0, M) b[i][j] = MAX;
	REP(i, 1, N) REP(j, 1, M)
		scanf(" %c", &m[i][j]);
	PER(i, N, 1) {
		int cnt = 0;
		PER(j, M, 1) {
			cnt = (j == M || m[i][j] == m[i][j+1]) ? cnt + 1 : 1;
			update(i, j, cnt);
			ans = max(ans, search(1, cnt, i, j));
		}
	}
	printf("%d\n", ans*ans);
	return 0;
}

