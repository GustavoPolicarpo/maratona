// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: L de Atreus!?
// Nível: 5
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2825

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;


int pd[101][101];
int mark[101][101], cnt = 1;
int Q, C;
char words[1001][101];
int tam[1001], diff[1001];

int solve(int i, int j, int p){
	if(i==tam[p]) return tam[Q]-j;
	if(j==tam[Q]) return tam[p]-i;
	if(mark[i][j]==cnt) return pd[i][j];
	mark[i][j] = cnt;
	int ret = 0x3f3f3f3f;
	if(words[p][i]==words[Q][j]) ret = solve(i+1, j+1, p);
	else ret = min(solve(i+1, j+1, p), min(solve(i+1, j, p), solve(i, j+1, p)))+1;
	return pd[i][j] = ret;
}

int dp[101][101];
int solveIt(int p){
	rep(i, 0, tam[p]+1) dp[i][tam[Q]] = tam[p]-i;
	rep(i, 0, tam[Q]+1) dp[tam[p]][i] = tam[Q]-i;
	for(int i=tam[p]-1; i>=0; i--){
		for(int j=tam[Q]-1; j>=0; j--){
			if(words[p][i]==words[Q][j]) dp[i][j] = dp[i+1][j+1];
			else dp[i][j] = min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]))+1;
		}
	}
	return dp[0][0];
}

void letsGo(){
	int bestDiff = 0x3f3f3f3f;
	rep(i, 0, Q){
		diff[i] = solveIt(i); cnt++;
		bestDiff = min(bestDiff, diff[i]);
	}
	rep(i, 0, Q){
		if(diff[i]==bestDiff){
			printf("%s", words[i]);
			break;
		}
	}
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &Q);
	rep(i, 0, Q){
		scanf("%s", words[i]);
		tam[i] = strlen(words[i]);
	}
	scanf("%d", &C);
	rep(i, 0, C){
		scanf("%s", words[Q]);
		tam[Q] = strlen(words[Q]);
		if(i) printf(" ");
		letsGo();
	}	puts("");
	
	return 0;
} 
