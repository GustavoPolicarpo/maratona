// Author: Gustavo Policarpo
// Name: Kids in a Grid
// Level: 8
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1341

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define error 1e-12

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

int N, M;
int pd[600][600];
string a, b;
int t1, t2;
char mat[25][25];

int solve(int i, int j)
{
	if(i==t1) return 0;
	if(j==t2) return 0;
	
	if(pd[i][j]!=-1) return pd[i][j];
	
	int ret=0;
	
	if(a[i]==b[j]) ret=max(ret, solve(i+1, j+1)+1);
		
	ret=max(ret, max(solve(i+1, j), solve(i, j+1)));
	
	return pd[i][j]=ret;	
}
int main()
{
	int t; cin >> t;
	rep(z, 1, t+1){
		
		memset(pd, -1, sizeof pd);
		
		int l, c;
		cin >> l >> c;
		rep(i, 0, l)
			rep(j, 0, c)
				cin >> mat[i][j];
		int n, x, y; char op[550];
		cin >> n >> x >> y;
		rep(i, 0, n)	cin >> op[i];
		a="";
		rep(i, 0, n+1){
			a+=mat[x-1][y-1];
			if(op[i]=='N') x-=1;
			else if(op[i]=='S') x+=1;
			else if(op[i]=='E') y+=1;
			else if(op[i]=='W') y-=1;
		} t1=a.size();
		cin >> n >> x >> y;
		rep(i, 0, n)	cin >> op[i];
		b="";
		rep(i, 0, n+1){
			b+=mat[x-1][y-1];
			if(op[i]=='N') x-=1;
			else if(op[i]=='S') x+=1;
			else if(op[i]=='E') y+=1;
			else if(op[i]=='W') y-=1;
		} t2=b.size();
		
		int out=solve(0, 0);
		printf("Case %d: %d %d\n", z, t1-out, t2-out);				
	}
		
return 0;
}


