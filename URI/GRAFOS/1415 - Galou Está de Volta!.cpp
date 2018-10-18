// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Galou Está de Volta!
// Nível: 7
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1415

#include <bits/stdc++.h>

#define pb push_back 
#define mp make_pair 
#define F first 
#define S second 
#define rep(i, a, b) for(int i=a; i<b; i++)

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int L, C;
char mat[101][101], ans[101][101];

int dx[]={-1, -1, 0, 0, 1, 1}, dy[]={0, 1, -1, 1, -1, 0};

bool go(int x, int y){
    return x>=0 && y>=0 && x<L && y<C && mat[x][y]!='.';
}

bool go2(int x, int y){
    return x>=0 && y>=0 && x<L && y<C && ans[x][y]!='.';
}

void dfs(int x, int y, int c){
    
    char cmp = c==1?'(':')';
    
    rep(i, 0, 6){
        int ax=x+dx[i], ay=y+dy[i];
        if(!go(ax, ay)) continue;
        if(ans[ax][ay]=='F'){
            ans[ax][ay]=cmp;
            dfs(ax, ay, 1-c);
        }else if(ans[ax][ay]!=cmp){
            ans[ax][ay]='B';
        }
    }
    
    return;
    
}


void dfs2(int x, int y){
    
    rep(i, 0, 6){
        int ax=x+dx[i], ay=y+dy[i];
        if(!go2(ax, ay) || ans[ax][ay]=='B') continue;
        ans[ax][ay]='B';
        dfs2(ax, ay);
    }
    
    return;
    
}

int main(){
        
//  freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

    while(scanf("%d %d", &L, &C) and L+C){
        
        cin.ignore();
        
        rep(i, 0, L) rep(j, 0, C) cin >> mat[i][j];
        
        rep(i, 0, L)
        rep(j, 0, C){
            if(mat[i][j]=='*') ans[i][j]='F';
            else if(mat[i][j]=='I') ans[i][j]='(';
            else ans[i][j]='.';
        }
            
                    
        rep(i, 0, L)
        rep(j, 0, C){
            if(mat[i][j]=='I'){
                ans[i][j]='(';
                dfs(i, j, 0);               
            }
        }
        
        rep(i, 0, L)
        rep(j, 0, C){
            if(ans[i][j]=='B')
                dfs2(i, j);
        }
        
        puts("");
        rep(i, 0, L){
        	rep(j, 0, C)
        		cout << ans[i][j];
        	cout << '\n';
		}
        
    }
    
    return 0;

}
