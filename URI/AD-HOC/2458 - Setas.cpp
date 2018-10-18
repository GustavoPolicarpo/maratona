// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Setas
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2458

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






int n, vis[505][505];
char mat[505][505];

bool dentro(int x, int y){
	return x>=0 && y>=0 && x<n && y<n;
}

int dfs(int x, int y){
	if(vis[x][y]) return vis[x][y];
	vis[x][y]=1;
	
	int ax=x, ay=y;
	if(mat[x][y]=='>') ay++;
	else if(mat[x][y]=='<') ay--;
	else if(mat[x][y]=='A') ax--;
	else if(mat[x][y]=='V') ax++;
	if(!dentro(ax, ay)){
		return vis[x][y]=2;
	}
	
	return vis[x][y]=max(vis[x][y], dfs(ax, ay));
}
int main()
{
	scanf("%d ", &n);
	rep(i, 0, n) gets(mat[i]);
	
	rep(i, 0, n){
		rep(j, 0, n){
			if(!vis[i][j]){
				dfs(i, j);
			}
		}
	}
	
	int cnt=0;
	rep(i, 0, n){
		rep(j, 0, n)
			if(vis[i][j]==1)
				cnt++;
	}
	
	cout << cnt << '\n';
	
	return 0;
	
}
