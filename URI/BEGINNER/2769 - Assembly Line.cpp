// Author: Gustavo Policarpo
// Name: Assembly Line
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2769

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )

using namespace std;

int tempo[2][1010];
int transicao[2][1010];
int entrada[2], saida[2];
int pd[1010][2];
int N;

int solve(int i, int l){
    if(i==N) return saida[l];
    if(pd[i][l]!=-1) return pd[i][l];
    return pd[i][l] = min(solve(i+1, l), solve(i+1, 1-l)+transicao[l][i]) + tempo[l][i];
}

int main(){
    
    while(scanf("%d", &N)!=EOF){
        
        memset(pd, -1, sizeof pd);
        
        rep(i, 0, 2) scanf("%d", &entrada[i]);
        rep(i, 0, 2) rep(j, 0, N){
            scanf("%d", &tempo[i][j]);
        }
        rep(i, 0, 2) rep(j, 0, N-1){
            scanf("%d", &transicao[i][j]);
        }   transicao[0][N-1] = transicao[1][N-1] = 0x3f3f3f3f;
        rep(i, 0, 2) scanf("%d", &saida[i]);
        
        printf("%d\n", min(solve(0, 0)+entrada[0], solve(0, 1)+entrada[1]));
        
    }
    
    return 0;
}
