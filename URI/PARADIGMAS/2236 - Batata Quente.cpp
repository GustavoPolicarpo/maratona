// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Batata Quente
// Nível: 7
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2236

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < char, ii > iii;


int N, Q, v[50050], mn[50050], mapa[50050], root;
ii qt[225][50050];
vector <int> adj[50050];
vector <int> blocos[225], ob[225];

int C(int u){
	return u/root;
}
void build(int b, int x){
	int p=upper_bound(ob[b].begin(), ob[b].end(), x)-ob[b].begin();
	qt[b][x].F=p;
	qt[b][x].S=ob[b].size()-p;
}

void check(int a, int b, int mid, int &la, int &lb){
	int aa=C(a), bb=C(b), u;
	
	if(aa==bb){
		for(int i=mapa[a]; i<=mapa[b]; i++){
			u=blocos[aa][i];
			if(mn[u]<=mid) la++;
			else lb++;
		}
	}
	else{
		for(int i=aa+1; i<=bb-1; i++){
			if(!qt[i][mid].F && !qt[i][mid].S) build(i, mid);
			la+=qt[i][mid].F;
			lb+=qt[i][mid].S;
		}
		for(int i=mapa[a]; i<blocos[aa].size(); i++){
			u=blocos[aa][i];
			if(mn[u]<=mid) la++;
			else lb++;
		}
		for(int i=0; i<=mapa[b]; i++){
			u=blocos[bb][i];
			if(mn[u]<=mid) la++;
			else lb++;
		}
	}
}


int menor;
void dfs(int u){
	if(mn[u]){
		menor=min(menor, mn[u]);
		return;
	}
	
	mn[u]=u;
	menor=min(menor, u);
	dfs(v[u]);
	
	mn[u]=0;
}


int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	scanf("%d %d", &N, &Q);
	root = sqrt(N);
	
	rep(i, 1, N+1) scanf("%d", &v[i]);
	
	rep(i, 1, N+1){
		menor=INF;
		dfs(i);
		mn[i]=menor;
	}
	
	rep(i, 1, N+1){
		mapa[i]=blocos[C(i)].size();
		blocos[C(i)].pb(i);
		ob[C(i)].pb(mn[i]);
	}
	rep(i, 0, root+1) sort(ob[i].begin(), ob[i].end());
	
	
	while(Q--){
		int a, b; scanf("%d %d", &a, &b);
		int ini=1, fim=N, mid, best=INF, mb=INF;
		
		while(ini<=fim){
			
			mid=(ini+fim)/2;
			int la=0, lb=0;
			
			check(a, b, mid, la, lb);
			
			if(la >= lb){
				fim=mid-1;
			}else{
				ini=mid+1;
			}
			
			if(abs(la-lb) < best){
				best=abs(la-lb);
				mb=mid;
			}else if(abs(la-lb) == best){
				mb=min(mb, mid);
			}
		}
		
		int ans=mid=mb;
		
		while(1){
			
			--mid;
			if(!mid) break;
			int la=0, lb=0;
			
			check(a, b, mid, la, lb);
			
			if(abs(la-lb) <= best){
				ans=mid;
				best=abs(la-lb);
			}else{
				break;
			}
			
		}
		
		printf("%d\n", ans);
		
	}
	
	return 0;
	
}
