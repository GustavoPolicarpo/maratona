// Author: Gustavo Policarpo
// Name: Cops and Robbers
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1905

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
typedef pair < int, int > ii;
typedef pair < double, int > iii;

int vis[5][5];
int lab[5][5];

int dx[]={-1,0,0,1}, dy[]={0,-1,1,0};
bool go(int x, int y)
{
	if(vis[x][y]==1) return false;
	if(lab[x][y]==1) return false;
	return x>=0 && y>=0 && x<5 && y<5;
}
bool solve(int x, int y)
{
	queue <ii> q;
	q.push(mp(x, y));
	while(!q.empty()){
		x=q.front().F, y=q.front().S, q.pop();
		if(x==4 && y==4) return true;
		vis[x][y]=1;
		rep(i, 0, 4){
			int ax=x+dx[i], ay=y+dy[i];
			if(!go(ax, ay)) continue;
			q.push(mp(ax, ay));
		}
		
	}
	return false;		
}

int main()
{
	int T; cin >> T;
	while(T--){
		memset(vis, 0, sizeof vis);
		rep(i, 0, 5)
			rep(j, 0, 5)
				scanf("%d", &lab[i][j]);
		if(solve(0, 0)) cout << "COPS" << endl;
		else cout << "ROBBERS" << endl;
	}
	

return 0;
}
