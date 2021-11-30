// Author: Gustavo Policarpo
// Name: Worldwide Finals in 2008
// Level: 8
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2130

#define gc getchar_unlocked
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

int N, M, Q, mat[101][101][101];
 
int main()
{
	int z=1, u, v, d, t;
	while(scanf("%d %d", &N, &M) !=EOF){

		rep(i, 0, N+1)
			rep(j, 0, N+1)
				rep(k, 0, N+1){
					if(i==j) mat[i][j][k]=0;
					else mat[i][j][k]=INF;
				}				
							
		rep(i, 0, M){
			//scanf("%d %d %d", &u, &v, &d);
			scanint(u), scanint(v), scanint(d);
			//u=readInt(), v=readInt(), d=readInt();
			u--, v--, d;
			mat[u][v][0]=min(mat[u][v][0], d);
		}
		
		rep(k, 0, N)
			rep(i, 0, N)
				rep(j, 0, N)
					mat[i][j][k+1]=min(mat[i][j][k], mat[i][k][k]+mat[k][j][k]);
		
		scanf("%d", &Q);
		printf("Instancia %d\n", z++);
		while(Q--){
			//scanf("%d %d %d", &u, &v, &t);
			scanint(u), scanint(v), scanint(t);
	
			int out=mat[u-1][v-1][t];
			
			if(out==INF) printf("-1\n");
			else printf("%d\n", out);			
		}
			
		printf("\n");
					
	}
				
return 0;
} 
