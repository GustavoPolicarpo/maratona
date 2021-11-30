// Author: Gustavo Policarpo
// Name: Bike Land
// Level: 6
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2086

#include<bits/stdc++.h>
#define gc getchar_unlocked


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
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;
/*
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
*/

int N, M, u, v, w, Q;
ii mat[101][101];

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(1){
		cin >> N >> M;
		if(!N) break;
		rep(i, 0, N)
		rep(j, 0, N){
			if(i==j) mat[i][j]=mp(0, 0);
			else mat[i][j]=mp(INF, INF);
		}
		rep(i, 0, M){
			cin >> u >> v >> w;
			u--, v--;
			mat[u][v]=mp(w, w);
			mat[v][u]=mp(w, w);
		}
		rep(k, 0, N)
		rep(i, 0, N)
		rep(j, 0, N){
			int aux=max(mat[i][k].S, mat[k][j].S);
			if(mat[i][j].S>aux)
				mat[i][j]=mp(mat[i][j].F, aux);		
		}
		cin >> Q;
		rep(i, 0, Q){
			cin >> u >> v;
			u--, v--;
			cout << mat[u][v].S << endl;
		}		
	}

return 0;
}



