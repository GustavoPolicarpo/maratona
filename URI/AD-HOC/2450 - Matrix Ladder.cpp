// Author: Gustavo Policarpo
// Name: Matrix Ladder
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2450

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

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
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}


int n, m, mat[505][505];

bool check(int i){
	for(; i<n; i++)
	for(int j=0; j<m; j++)
	if(mat[i][j]) return false;
	return true;
}
bool yep(){
	int i=0, j=0;
	
	while(i<n){
		while(mat[i][j]==0 && j<m) j++;
		if(j==m) return check(i+1);
		int p=i+1;
		while(p<n){
			if(mat[p][j]) return false;
			p++;
		}
		i++;
	}
	return true;
}
int main()
{
	scanint(n), scanint(m);
	rep(i, 0, n)
	rep(j, 0, m)
		scanint(mat[i][j]);
	
	yep() ? puts("S") : puts("N");
	
	
	return 0;
	
}
