// Author: Gustavo Policarpo
// Name: TV da Vovó
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2288

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
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> ii;


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



int mat[1010][1010];
int main ()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, M, z=1;
	while(scanf("%d %d", &N, &M) and N+M){
		printf("Teste %d\n", z++);
		rep(i, 0, N)
		rep(j, 0, M)
			scanint(mat[i][j]);
		
		int v=0, h=0, x, y;
		while(1){
			scanint(x), scanint(y);
			if(x==0 && y==0) break;
			h-=x, v+=y;
		}	
		v%=N, h%=M;
		if(v<0) v+=N;
		if(h<0) h+=M;
		
		
		rep(i, 0, N){
			rep(j, 0, M){
				if(j>0) printf(" ");
				printf("%d", mat[(i+v)%N][(j+h)%M]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
  
  return 0;
}
