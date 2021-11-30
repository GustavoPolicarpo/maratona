# Author: Gustavo Policarpo
# Name: Chuva
# Level: 5
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/3052

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define REP(i,a,b) for( int i = (int) a; i <= (int) b; i++ )
#define PER(i,a,b) for( int i = (int) a; i >= (int) b; i-- )
#define F first
#define S second
#define mk make_pair
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }
 
using namespace std;
 
typedef long long int ll;
typedef pair <int, int> ii;
 
const int MAX = 2e3+3;
const int mod = 1e9+7;
 
int n, m;
char mat[505][505];
int vis[505][505];

void solve(int x, int y){
    if(vis[x][y]) return; vis[x][y] = 1;
    if(x==n-1) return;
    if(mat[x+1][y]=='#') solve(x, y-1), solve(x, y+1);
    else solve(x+1, y);
}

int main(){
    scanf("%d %d", &n, &m);
    rep(i, 0, n) scanf("%s", mat[i]);
    rep(i, 0, m) if(mat[0][i]=='o'){
        solve(0, i);
    }
    rep(i, 0, n){
        rep(j, 0, m){
            if(vis[i][j]) cout << 'o';
            else cout << mat[i][j];
        }
        cout << '\n';
    }
 
    return 0;
}
