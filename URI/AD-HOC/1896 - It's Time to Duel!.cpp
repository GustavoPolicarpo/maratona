// Author: Gustavo Policarpo
// Name: It's Time to Duel!
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1896

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
const int mod=1e9+7;


int N, A, D, H, yep;
int a[22], d[22], h[22];

void solve(int n, int x, int y, int z, int qt){
	
	if(yep) return;
	
	if(x==A && y==D && z==H && qt>=2) return void(yep=true);
	
	if(n==N || x>A || y>D || z>H) return;
	
	solve(n+1, x, y, z, qt);
	solve(n+1, x+a[n], y+d[n], z+h[n], qt+1);
		
}

int main(){
	
	scanf("%d %d %d %d", &N, &A, &D, &H); yep=0;
	
	rep(i, 0, N) scanf("%d %d %d", &a[i], &d[i], &h[i]);
	
	solve(0, 0, 0, 0, 0);
	
	yep?puts("Y"):puts("N");
	
	return 0;
	
}
