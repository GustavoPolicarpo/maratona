// Author: Gustavo Policarpo
// Name: See World
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1955

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef pair < ll, ll > ii;

vector <int> adj[10002];
int cor[10002];

bool did=true;

bool bfsc(int u, int c)
{
	queue <ii> q;
	q.push(mp( u, c));
	cor[u]=c;
	while(!q.empty()){
		u=q.front().first;
		c=q.front().second;
		//cout << u << " " << c << endl;
		q.pop();
		cor[u]=c;
		rep(i, 0, adj[u].size()){
			int w=adj[u][i];
			if(cor[w]==c){
				return false;
				break;
			}
			if(cor[w]==0)
				q.push(mp(w, c*-1));
		}
	}
	return true;	
}


void tozero(int n)
{
	rep(i, 0, n+1){
		adj[i].clear();
		cor[i]=0;
	}
}

int main()
{
	int N;
	cin >> N;
		tozero(N);
		
		rep(i, 0, N){
			rep(j, 0, N){
				int temp; cin >> temp;
				if(temp==0)
					adj[i].pb(j);	
			}		
		}		
		
		bool yep=bfsc(0, 1);
		if(yep)
			cout << "Bazinga!";
		else
			cout << "Fail!";
		cout << endl;
	


return (0);
}
