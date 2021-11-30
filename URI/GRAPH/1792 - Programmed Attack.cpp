// Author: Gustavo Policarpo
// Name: Programmed Attack
// Level: 8
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1792

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

struct pt{
	int ami, ini, cg, id;
	bool operator() (pt a, pt b){
		if(a.ini>b.ini)	return true;
		if(a.ini<b.ini)	return false;
		if(a.ami>b.ami)	return false;
		if(a.ami<b.ami)	return true;
	}	
};

pt in[100001];
vector <int> adj[100001];

int N, M, S;

int main()
{
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
	while(scanf("%d %d %d", &N, &M, &S) and N+M+S){
		rep(i, 1, N+1){
			adj[i].clear();
			in[i].id=i;
			in[i].cg=0;
		}
		rep(i, 1, N+1){
			int k=readInt();
			in[i].ini=k;
		}
		rep(i, 1, N+1){
			int k=readInt();
			in[i].ami=k;
		}
		rep(i, 0, M){
			int u=readInt();
			int v=readInt();
			adj[u].pb(v);
			in[v].cg++;
		}
		priority_queue <pt, vector<pt>, pt> pq;
		rep(i, 1, N+1){
			if(in[i].cg==0){
				pq.push(in[i]);
			}
		}
		
		int count=N;
		while(!pq.empty()){
			
			pt u=pq.top(); pq.pop();
			if(u.ini>=S) break;
			count--;
			S+=u.ami;
			
			rep(i, 0, adj[u.id].size()){
				int v=adj[u.id][i];
				if(--in[v].cg==0){
					pq.push(in[v]);
				}
			}	
		}
		if(!count)	puts("possivel");
		else puts("impossivel");
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

