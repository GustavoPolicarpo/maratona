// Author: Gustavo Policarpo
// Name: Pushing Blocks
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1874

#include <iostream>

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main()
{
	int H, P, F;
	while(scanf("%d %d %d", &H, &P, &F) and H+P+F){
		int mat[H][P];
		rep(i, 0, H)
		rep(j, 0, P)
			scanf("%d", &mat[i][j]);
		
		int i=H-1, j=P-1, aux;
		while(F--){
			scanf("%d", &aux);
			if(i==0 && j==0 && mat[i][j]!=0) continue;
			while(mat[i][j]!=0){
				i--;
				if(i==-1){
					i=H-1, j--;
					if(j==-1){
						i=0, j=0;
						break;
					}
				}
			}
			if(mat[i][j]==0) mat[i][j]=aux;
		}
		rep(i, 0, H){
			rep(j, 0, P){
				if(j>0) printf(" ");
				printf("%d", mat[i][j]);
			}
			printf("\n");
		}
	}
	
return 0;

}
