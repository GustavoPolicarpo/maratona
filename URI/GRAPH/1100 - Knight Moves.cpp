// Author: Gustavo Policarpo
// Name: Knight Moves
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1100

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
typedef pair < int, ii > iii;

int vis[65][65];
vector <ii> adj[65][65];

int bfs(int ib, int jb, int ie, int je)
{
	int qm=0;
	queue <iii> q;
	q.push(mp(qm, mp(ib, jb)));
	while(!q.empty()){
		
		qm=q.front().first;
		ii aux=q.front().second;
		ib=aux.first;
		jb=aux.second;
		
		q.pop();
		
		if(ib==ie&&jb==je)
			return qm;
			
		vis[ib][jb]=1;
		
		rep(i, 0, adj[ib][jb].size()){
			ii w = adj[ib][jb][i];
			int u=w.first;
			int v=w.second;
			if(vis[u][v]!=1)
				q.push(mp(qm+1, mp(u, v)));
		}
	}

}

void buildchess()
{
	rep(i, 0, 8)
		rep(j, 0, 8){
			if(i<6){
				if(j>0)
					adj[i][j].pb(mp(i+2, j-1));
				if(j<7)
					adj[i][j].pb(mp(i+2, j+1));
			}
			if(i>1){
				if(j>0)
					adj[i][j].pb(mp(i-2, j-1));
				if(j<7)
					adj[i][j].pb(mp(i-2, j+1));
			}
			if(j<6){
				if(i>0)
					adj[i][j].pb(mp(i-1, j+2));
				if(i<7)
					adj[i][j].pb(mp(i+1, j+2));
			}
			if(j>1){
				if(i>0)
					adj[i][j].pb(mp(i-1, j-2));
				if(i<7)
					adj[i][j].pb(mp(i+1, j-2));
			}	
		}
}
int reti(char in)
{
	if(in=='a')
		return 0;
	if(in=='b')
		return 1;
	if(in=='c')
		return 2;
	if(in=='d')
		return 3;
	if(in=='e')
		return 4;
	if(in=='f')
		return 5;
	if(in=='g')
		return 6;
	if(in=='h')
		return 7;
}
int main()
{
	buildchess();
	string a, b;
	int ib, jb, ie, je, mov;
	while(cin >> a >> b){
		
		memset(vis, 0, sizeof(vis));
		
		ib=reti(a[0]);
		jb=a[1]-'1';
		ie=reti(b[0]);
		je=b[1]-'1';
		
		//cout << ib << " " << jb << " " << ie << " " << je << endl;
		mov = bfs(ib, jb, ie, je);
		
		cout << "To get from " << a << " to " << b
		<< " takes " << mov << " knight moves."	<< endl;
	}
								
return (0);
}
