// Author: Gustavo Policarpo
// Name: 106 Miles To Chicago
// Level: 6
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1655

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
#define mod 1300031
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, int > ii;
typedef pair < int, ii > iii;


/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/


double mat[101][101];
int N, M;
int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(scanf("%d", &N) and N){
		scanf("%d", &M);
		rep(i, 0, N+1)
		rep(j, 0, N+1){
			if(i==j) mat[i][i]=1;
			else mat[i][j]=0.0;
		}
		int u, v; 
		double p;
		rep(i, 0, M){
			cin >> u >> v >> p;
			u--, v--, p/=100.0;
			mat[u][v]=p;
			mat[v][u]=p;
			//cout << mat[u][v] << endl;
		}
		rep(k, 0, N)
		rep(i, 0, N)
		rep(j, 0, N)
			mat[i][j]=max(mat[i][j], mat[i][k]*mat[k][j]);
		
		double out=mat[0][N-1]*100.0;
		printf("%.6lf percent\n", out);
			
	}
	
return 0;	
}
