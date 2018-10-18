// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Gruntz
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1525

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef pair < int, int > ii;

int dx[] = { -1, 0, 0, 1};
int dy[] = { 0, -1, 1, 0};
char dir[] = { 'v', '>', '<', '^' };
char dic[] = { '^', '<', '>', 'v' };

char co[101][101];
int vis[101][101][101];
int L, C;

bool dentro(int i, int j)
{
	return ( i>=0 && j>=0 && i<L && j<C );
}

bool verify(int i, int j)
{
	if(i==0||j==0||i==L-1||j==C-1)
		return true;
	return false;
}

bool fim;
void out(int x, int y, int k)
{
	
	if(fim)
		return;
			
	if(verify(x, y))
		fim=true;
	
	
	vis[x][y][k]=1;
	
	rep(i, 0, 4){
		int X=x+dx[i];
		int Y=y+dy[i];
		if(co[X][Y]==dir[i]&&vis[X][Y][k]!=1)
			out(X, Y, k);
				
		else if(k>0&&co[X][Y]==dic[i]&&vis[X][Y][k]!=1)
			out(X, Y, k-1);
	}
}

int main()
{
	int m1, m2; int K;
	while(cin>>L>>C>>K and L+C+K){
		
		rep(i, 0, L)
			rep(j, 0, C)
				cin >> co[i][j];
					
		m1=L/2; m2=C/2; fim=false;
		memset(vis, 0, sizeof(vis));
		rep(i, 0, 4){
			if(fim) break;
				if(co[m1+dx[i]][m2+dy[i]]==dir[i]){
					memset(vis, 0, sizeof(vis));
					out(m1+dx[i], m2+dy[i], K);
				}
	
				else if(K>0&&co[m1+dx[i]][m2+dy[i]]==dic[i]){
					memset(vis, 0, sizeof(vis));
					out(m1+dx[i], m2+dy[i], K-1);
				}
		}
		if(fim==true)	cout << "Sim";
		else 			cout << "Nao";
						cout << endl;
	}

return 0;
}
