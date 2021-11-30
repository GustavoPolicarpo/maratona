// Author: Gustavo Policarpo
// Name: Jogo do Labirinto
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2332

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

struct use{
	int x, y, t;
};

int N, M, mat[52][52], vis[52][52][1052], 
	dx[]={-1, 0, 0, 1, 0}, dy[]={0, -1, 1, 0, 0};
	
bool podeir(use go){
	return go.x>=0 && go.x<N && go.y>=0 && go.y<M && vis[go.x][go.y][go.t]==0;
}

int solve(){
	queue <use> q; use aux, go;
	aux.x=0, aux.y=0, aux.t=0, vis[0][0][0]=1;
	q.push(aux);
	while(!q.empty()){
		aux=q.front(); int alt=(mat[aux.x][aux.y]+aux.t)%10; q.pop();
		
		//cout << aux.x << " " << aux.y << " " << aux.t << endl;
		if(aux.x==N-1 && aux.y==M-1) return aux.t;
		
		rep(i, 0, 5){
			go.x=aux.x+dx[i], go.y=aux.y+dy[i], go.t=aux.t+1;
			if(!podeir(go)) continue;
			int nalt=(mat[go.x][go.y]+aux.t)%10;
			if(alt>=nalt-1){
				vis[go.x][go.y][go.t]=1;
				q.push(go);
			}
		}
		
	}
}

/*
3 4
0 0 0 0
0 0 0 0
0 0 0 0
*/

int main ()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d %d", &N, &M);
	rep(i, 0, N)
	rep(j, 0, M)
		scanf("%d", &mat[i][j]);
	
	printf("%d\n", solve());
  
  return 0;
}
