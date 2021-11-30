// Author: Gustavo Policarpo
// Name: Locked in the Castle
// Level: 9
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1773

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
#define mod 1000000007 

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;
ll readInt();
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, M, vis[1001], podeir[1001], tenhokey[1001];
vector <int> adj[1001];
set <int> key[1001];
vector <int> kk[1001];

void bfs(){
	queue<int> q;
	q.push(1); vis[1]=1;
	while(!q.empty()){
		int u=q.front(); q.pop();

		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			if(vis[v]) continue;
			//cout << u << " " <<  " " << v << endl;
			if(tenhokey[v]){
				vis[v]=1;
				q.push(v);
				continue;
			}
			if(!key[u].count(v)){
				podeir[v]=1;
				continue;
			}
			vis[v]=1;
			q.push(v);
			continue;
		}
		rep(j, 0, kk[u].size()){
			int go=kk[u][j];
			tenhokey[go]=1;
			if(podeir[go]){
				vis[go]=1;
				q.push(go);
			}
		}
	}
}
int main()
{
//	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(scanf("%d %d", &N, &M) !=EOF){
		rep(i, 1, N+1) podeir[i]=0, vis[i]=0, adj[i].clear(), key[i].clear(), kk[i].clear(), tenhokey[i]=0;
		int u, v, k;
		rep(i, 0, M){
			u=readInt(), v=readInt();
			adj[u].pb(v), adj[v].pb(u);
		}
		rep(i, 2, N+1){
			k=readInt();
			kk[k].pb(i);
			key[k].insert(i);
		}
		rep(i, 0, kk[1].size()) tenhokey[kk[1][i]]=1;
		bfs();
		bool yep=true;
		rep(i, 1, N+1){
			if(!vis[i]){
				yep=false;
				break;
			}
		}
		if(yep) puts("sim");
		else puts("nao");
	}
			
return 0;
}

ll readInt(){
    int minus = 0;
    ll result = 0; char ch;

    ch = getchar();
    while(1){
        if( ch == '-' )
            break;
        if( ch >= '0' && ch <= '9' ) break;
        ch = getchar();
    }
    if( ch == '-' )  minus = 1;
    else result = ch-'0';
    while(1){
        ch = getchar();
        if( ch < '0' || ch > '9' ) break;
        result = result*10 + (ch-'0');
    }
    if( minus ) return -result;
    else return result;
}

