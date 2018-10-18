// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Contaminação
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1583

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
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, string > ii;
typedef pair < double, int > iii;
 
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

char mat[51][51], out[51][51];
int N, M, vis[51][51];

int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};

bool dentro(int x, int y){
	return x>=0 && y>=0 && x<N && y<M && (mat[x][y]=='A' || mat[x][y]=='T');
}
void dfs(int i, int j){
	if(vis[i][j]) return;
	vis[i][j]=1;
	rep(k, 0, 4){
		int x=i+dx[k], y=j+dy[k];
		if(!dentro(x, y)) continue;
		out[x][y]='T';
		dfs(x, y);
	}
	return;
}

int main(){
	while(scanf("%d %d", &N, &M) and N){
		rep(i, 0, N)
		rep(j, 0, M)
			cin >> mat[i][j];
		memset(vis, 0, sizeof vis);
		rep(i, 0, N)
		rep(j, 0, M){
			if(vis[i][j]) continue;
			if(mat[i][j]=='T'){
				out[i][j]='T';
				dfs(i, j);
			}
			else out[i][j]=mat[i][j];
		}
		rep(i, 0, N){
			rep(j, 0, M)
				cout << out[i][j];
			printf("\n");
		}
		printf("\n");
	}
}
