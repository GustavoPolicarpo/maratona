// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Viagem Barril
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1757

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
#define MAXN 100001
#define mod 1000000007
#define error 1e-7

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
}
*/

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int T, N, M, mat[101][101], pset[101];
vector <iii> edg;

int findset(int x){
	if(x!=pset[x]){
		pset[x]=findset(pset[x]);
	}
	return pset[x];
}

void unionset(int x, int y){
	x=findset(x), y=findset(y);
	pset[x]=y;
}

bool sameset(int x, int y){
	return findset(x)==findset(y);
}
int main()
{
	cin >> T;
	while(T--){
		
		scanf("%d %d", &N, &M);
		
		rep(i, 0, N){
			pset[i]=i;
			rep(j, 0, N)
				mat[i][j]=0;
		} edg.clear();
		
		int u, v, c;
		rep(i, 0, M){
			scanf("%d %d", &u, &v);
			mat[u][v]=1;
			mat[v][u]=1;
		}
		
		/*rep(k, 0, N)
		rep(i, 0, N)
		rep(j, 0, N){
			mat[i][j]=min(mat[i][j], mat[i][k]+mat[k][j]);
		}*/
		
		rep(i, 0, N){
			rep(j, i+1, N){
				c=0;
				if(mat[i][j]) c=1;
				edg.pb(mp(c, mp(i, j)));
			}
		}
		sort(edg.begin(), edg.end());
		int out=0;
		
		rep(i, 0, edg.size()){
			u=edg[i].S.F,
			v=edg[i].S.S,
			c=edg[i].F;
			if(!sameset(u, v)){
				unionset(u, v);
				out+=c;
			}
		}
		
		cout << out << endl;
	}
	
}



