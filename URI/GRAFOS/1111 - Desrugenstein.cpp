// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Desrugenstein
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1111

#include<bits/stdc++.h>
//#define gc getchar_unlocked


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
//

int N, in[20][80], mat[200][200];
int main()
{
	//freopen("out.txt", "w", stdout);
	while(scanf("%d", &N) and N){
		
		rep(i, 0, N)
		rep(j, 0, N*4)
			scanf("%d", &in[i][j]);
		
		map <ii, int> mapa;
		
		
		int cnt=0;
		for(int i=N-1; i>=0; i--){
			for(int j=0; j<N*4; j+=4){
				if(!mapa.count(mp(i, j))) mapa[mp(i, j)]=cnt++;
			}
		}
		
		rep(i, 0, cnt)
		rep(j, 0, cnt){
			if(i==j) mat[i][j]=0;
			else mat[i][j]=INF;
		}
		
		for(int i=N-1; i>=0; i--){
			for(int j=0; j<N*4; j+=4){
				if(in[i][j]==1 && i>0){
					mat[mapa[mp(i, j)]][mapa[mp(i-1, j)]]=1;	
				}
				if(in[i][j+1]==1 && i<N-1){
					mat[mapa[mp(i, j)]][mapa[mp(i+1, j)]]=1;
				}
				if(in[i][j+2]==1 && j>0){
					mat[mapa[mp(i, j)]][mapa[mp(i, j-4)]]=1;
				}
				if(in[i][j+3]==1 && j+4<4*N){
					mat[mapa[mp(i, j)]][mapa[mp(i, j+4)]]=1;
				}
			}
		}
		rep(k, 0, cnt)
		rep(i, 0, cnt)
		rep(j, 0, cnt)
			mat[i][j]=min(mat[i][j], mat[i][k]+mat[k][j]);
		
		int P; cin >> P;
		int a, b, c, d, u, v;
		while(P--){
			scanf("%d %d %d %d", &a, &b, &c, &d);
			
			u=mapa[mp(N-b-1, a*4)];
			v=mapa[mp(N-d-1, c*4)];
			
			if(mat[u][v]==INF) puts("Impossible");
			else printf("%d\n", mat[u][v]);
		}
		cout << endl;	
	}

return 0;
}



