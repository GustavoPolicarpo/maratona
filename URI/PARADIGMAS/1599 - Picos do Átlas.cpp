// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Picos do Átlas
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1599

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


int mat[1010][1010];
int dx[]={-1, -1, -1, 0, 0, 1, 1, 1},
	dy[]={-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N, M;
	
	while(scanf("%d %d", &N, &M) !=EOF){
		
		rep(i, 0, N)
		rep(j, 0, M)
			scanint(mat[i][j]);
		
		vector <ii> out;
		
		rep(i, 0, N)
		rep(j, 0, M){
			bool yep=true;
			rep(k, 0, 8){
				int ax=i+dx[k], ay=j+dy[k];
				if(ax>=0 && ay>=0 && ax<N && ay<M){
					if(mat[ax][ay]>=mat[i][j]){
						yep=false;
						break;
					}
				}
				
			}
			if(yep) out.pb(mp(i+1, j+1));
		}
		
		sort(out.begin(), out.end());
		
		if(out.size()==0) printf("%d\n", -1);
		else rep(i, 0, out.size()) printf("%d %d\n", out[i].F, out[i].S);
		printf("\n");
	}
	
	return 0;
	
}
