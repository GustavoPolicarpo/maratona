// Author: Gustavo Policarpo
// Name: Brothers
// Level: 6
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1376

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

#define INF 0x3f3f3f3f
#define MAXV 100001

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < ii, vector <ii> > iii;

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

int mat[105][105], aux[105][105], dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};
int main()
{
	rep(i, 0, 105)
	rep(j, 0, 105)
		mat[i][j]=aux[i][j]=-1;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int N, R, C, K;
    while(1){
    	scanint(N), scanint(R), scanint(C), scanint(K);
    	
    	if(!N) break;
	    R++, C++;
	    
	    rep(i, 1, R)
	    rep(j, 1, C)  
			scanint(mat[i][j]);
		
		while(K--){
			rep(i, 1, R){
				rep(j, 1, C){
					rep(k, 0, 4){
						int x=i+dx[k], y=j+dy[k];
						if(mat[x][y]==-1) continue;
						if(mat[x][y]==mat[i][j]+1 || (mat[x][y]==0 && mat[i][j]==N-1)) aux[x][y]=mat[i][j];
					}
				}
			}
			rep(i, 1, R)
			rep(j, 1, C){
				if(aux[i][j]!=-1) mat[i][j]=aux[i][j];
			}
		}
		rep(i, 1, R){
			rep(j, 1, C){
				if(j>1) printf(" ");
				printf("%d", mat[i][j]);
			}
			printf("\n");
		} memset(aux, -1, sizeof aux);
	}
    
return 0;
}


