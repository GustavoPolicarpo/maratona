// Author: Gustavo Policarpo
// Name: Uncle Tom’s Inherited Land
// Level: 8
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1330

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < double, ii > iii;

int mat[101][101];
int match[100101];
int vis[100101];
vector <int>adj[100101];

int N, M;

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

int aug(int v)
{
	if(vis[v]==1) return 0;
	vis[v]=1;
	rep(i, 0, adj[v].size()){
		int r=adj[v][i];
		if(match[r]==-1 || aug(match[r])){
			match[r]=v;
			return 1;
		}
	}
	return 0;
}

bool dentro(int x, int y)
{
	return x>=0&&y>=0&&x<N&&y<M;
}

int main(){
    
    while(cin>>N>>M and N+M){
    	
    	memset(mat, 0, sizeof(mat));
    	memset(match, -1, sizeof(mat));
    	memset(vis, 0, sizeof(vis));
    	rep(i, 0, N*M+M)
    		adj[i].clear();
    		
    	int K;  cin >> K;
    	int X, Y;
    	while(K--){
    		cin >> X >> Y;
    		mat[X-1][Y-1]=1;
		}
		int x, y;
		rep(i, 0, N)
			rep(j, 0, M)
				if(mat[i][j]==0)
					rep(k, 0, 4){
						x=i+dx[k]; y=j+dy[k];
						//cout << i << " " << j << endl;
						//cout << x << " " << y << endl;
						//system("pause");
						if(dentro(x, y)&&mat[x][y]==0)
							adj[i*M+j].pb(x*M+y);
					}
				
		/*cout << endl;	
		rep(i, 0, N*M){
			cout << i << " : ";
			rep(j, 0, adj[i].size())
				cout << adj[i][j] << " ";
			cout << endl;
		}*/
				
		int mcbm=0;
		rep(i, 0, N*M){
			rep(j, 0, N*M)
				vis[j]=0;
			mcbm+=aug(i);
		}
		cout << mcbm/2 << endl;
	}
		
return 0;
}
