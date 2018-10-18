// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cavalo
// Nível: 7
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1513

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
#define error 1e-12

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;


int N, M, K, inix, iniy, pd[20][1<<16];
char mat[101][101]; int grafo[20][20];

struct po{
    int x, y, d;
};

po in[20];
int dx[]={-2, -2, -1, -1, 1, 1, 2, 2}, dy[]={-1, 1, -2, 2, -2, 2, -1, 1};
int solve(int i, int mask)
{
    if(mask == (1<<K+1)-1) return grafo[i][0];
    if(pd[i][mask]!=-1) return pd[i][mask];

    int ans=INF;
    rep(j, 0, K+1){
        if(i!=j && !(mask&(1<<j)))
                ans=min(ans, solve(j, mask|(1<<j))+grafo[i][j]);
    }
    return pd[i][mask]=ans;

}
int vis[101][101];
bool dentro(int x, int y)
{
    return x>=0 && y>=0 && x<N && y<M && mat[x][y]!='#';
}
map <ii, int> mapa;
void build_grafo(int ini)
{
    queue <po> q; po aux;
    aux.x=in[ini].x, aux.y=in[ini].y, aux.d=0; int cont=0; vis[aux.x][aux.y]=1;
    q.push(aux);
    while(!q.empty()){
        po aux=q.front(); q.pop();
        int x=aux.x, y=aux.y, d=aux.d;
        //cout << mat[x][y] << endl;
        if(mat[x][y]=='P' || mat[x][y]=='C'){
            grafo[ini][mapa[mp(x, y)]]=d; cont++;
            if(cont>K) return;
        }
        rep(i, 0, 8){
            int ax=x+dx[i], ay=y+dy[i];
            if(!dentro(ax, ay) || vis[ax][ay]) continue;
            vis[ax][ay]=1;
            aux.x=ax, aux.y=ay, aux.d=d+1;
            q.push(aux);
        }
    }
}
int main()
{
    while(scanf("%d %d %d", &N, &M, &K) and N+M+K){
        memset(pd, -1, sizeof pd); int z=1;
        rep(i, 0, N)
        rep(j, 0, M){
            cin >> mat[i][j];
            if(mat[i][j]=='C') in[0].x=i, in[0].y=j, mapa[mp(i, j)]=0;
            else if(mat[i][j]=='P') in[z].x=i, in[z].y=j, mapa[mp(i, j)]=z++;
        }
        memset(grafo, INF, sizeof grafo);
        rep(i, 0, z){
            memset(vis, 0, sizeof vis);
            build_grafo(i);
        }
       // rep(i, 0, K+1){
       //     rep(j, 0, K+1)
       //         cout << grafo[i][j] << " ";
       //     cout << endl;
       // }

        int out=solve(0, 0);
        cout << out << endl;
    }

return 0;
}

