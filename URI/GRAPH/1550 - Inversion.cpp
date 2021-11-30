// Author: Gustavo Policarpo
// Name: Inversion
// Level: 7
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1550

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F

typedef pair < int, int > ii;
typedef long long int ll;

int vis[10001];

int revert(int n)
{
	int ret=0;
	int i=1;

	while(i<=n){
		ret*=10;
		ret+=(n%(i*10)-n%i)/i;
		i*=10;
	}	
	return ret;
}

int bfs(int a, int b)
{
	queue <ii> q;
	memset(vis, 0, sizeof(vis));
	q.push(mp(a, 0));
	int u, c;
	while(!q.empty()){
		u = q.front().first;
		c = q.front().second;
		q.pop();
		if(u==b)
			return c;
		if(vis[u]!=1){
			vis[u]=1;
			if(u<10000)
				q.push(mp( u+1, c+1));
			int temp=revert(u);
			if(temp!=u)	
				q.push(mp(temp, c+1));		
		}
	}	
}

int main ()
{
	int T, A, B, out; cin >> T;
	while(T--){
		scanf("%d %d", &A, &B);
		int out=bfs(A, B);
		printf("%d\n", out);
	}
	 
return 0;
}
