// Author: Gustavo Policarpo
// Name: Optical Fiber
// Level: 8
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1270

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
ll readInt();
struct pt{
	int x, y;
}; 
int N; 
vector <int> adj[1001];

vector <pt> in[1001];
double grafo[1001][51][51], pd[1001][51];

double dst(pt a, pt b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int fim;
double solve(int u, int last, int c){
	//cout << u << " " << last << endl;
	if(pd[u][c]>0) return pd[u][c];
	double ans=0;
	
	rep(i, 0, adj[u].size()){
		double ret=INF;
		int v=adj[u][i];
		if(v==last && adj[u].size()==1) return 0;
		if(v==last) continue;
		rep(j, 0, in[v].size()){
			ret=min(ret, solve(v, u, j)+dst(in[u][c], in[v][j]));
			//cout << in[u][j].x  << " " << in[u][j].y << "   ";
			//cout << in[v][k].x  << " " << in[v][k].y << endl;
			//cout << dst(in[u][j], in[v][k]) << endl;
		}
		ans+=ret;
		
		//cout << ret << endl;
	}
	return pd[u][c]=ans;
}

int main(){
	while(1){
		N=readInt(); fim=0;
		if(!N) break; 
		map<string, int> city;
		string no, me; int Q;
		
		memset(pd, -1, sizeof pd);
		memset(grafo, 0, sizeof grafo);
		
		rep(i, 0, N){
	
			adj[i].clear();
			in[i].clear();
			
			cin >> no >> Q;
			city[no]=i;
			rep(j, 0, Q){
				pt aux;
				scanf("%d %d", &aux.x, &aux.y);
				in[i].pb(aux);
			}
		}
		rep(i, 1, N){
			cin >> no >> me;
			adj[city[no]].pb(city[me]);
			adj[city[me]].pb(city[no]);
		}
		
		double out=INF;
		rep(i, 0, in[0].size()) out=min(out, solve(0, 0, i));
		
		printf("%.1lf\n", out);
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
