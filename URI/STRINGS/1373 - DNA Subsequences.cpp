// Author: Gustavo Policarpo
// Name: DNA Subsequences
// Level: 8
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1373

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
#define INF 0x3f3f3f3f


int k, pd[1010][1010];
string a, b;

int solve(int i, int j){
	
	if(i==a.size() || j==b.size()) return 0;
	if(pd[i][j]!=-1) return pd[i][j];
	
	int ret=0, pi=i, pj=j, cnt=0;
	
	ret=max(ret, solve(i+1, j));
	ret=max(ret, solve(i, j+1));
	
	while(pi<a.size() && pj<b.size() && a[pi]==b[pj]){
		cnt++, pi++, pj++;
		if(cnt>=k){
			ret=max(ret, solve(pi, pj)+cnt);
		}
	}
	
	return pd[i][j]=ret;
	
}

int main(){
	
	while(scanf("%d", &k) and k){
		
		cin >> a >> b;
		
		rep(i, 0, a.size()+2) rep(j, 0, b.size()+2) pd[i][j]=-1;
		
		printf("%d\n", solve(0, 0));
		
	}
	
	
	return 0;
	
}
