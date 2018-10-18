// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ataque Programado
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1792

#define gc getchar_unlocked
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
using namespace std;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

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
		int k, a, b;
		rep(i, 1, N+1){
			scanint(k);
			in[i].ini=k;
		}
		rep(i, 1, N+1){
			scanint(k);
			in[i].ami=k;
		}
		rep(i, 0, M){
			scanint(a);
			scanint(b);
			adj[a].pb(b);
			in[b].cg++;
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
