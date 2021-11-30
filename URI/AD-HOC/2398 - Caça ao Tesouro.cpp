// Author: Gustavo Policarpo
// Name: Caça ao Tesouro
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2398

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


int n, k;
int mat[101][101];

bool dentro(int x, int y){
	return x>=0 && y>=0 && x<n && y<n;
}

int main()
{
	
	scanint(n), scanint(k);
	rep(i, 0, n) rep(j, 0, n) mat[i][j]=1;
	
	int u, v, c;
	rep(i, 0, k){
		
		scanint(v), scanint(u), scanint(c);
		set <ii> cango;
		
		for(int j=-c; j<=c; j++){
			if(dentro(v+j, u+(c-abs(j)))) cango.insert(mp(v+j, u+(c-abs(j))));
			if(dentro(v+j, u-(c-abs(j)))) cango.insert(mp(v+j, u-(c-abs(j))));
		}
		
		rep(a, 0, n)
		rep(b, 0, n){
			if(mat[a][b] && !cango.count(mp(a, b)))
				mat[a][b]=0;
		}
		
	}
	
	vector <ii> out	;
	rep(i, 0, n){
		rep(j, 0, n){
			if(mat[i][j]){
				out.pb(mp(i, j));
			}
		}
	}
	
	if(out.size() > 1) printf("-1 -1\n");
	else printf("%d %d\n", out[0].F, out[0].S);
	
	
	return 0;
		
}
