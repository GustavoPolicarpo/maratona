// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Expondo a Corrupção
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2008

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

int A, B, N, M, pd[300][10001];
int cu[300], ct[300], bene[300];
int rb, rc, fim;
vector <int> adj[300];
int vis[300];

int solve(int i, int c)
{
	if(i==fim) return 0;
	int &p=pd[i][c];
	if(p!=-1) return p;
	int ret=solve(i+1, c);
	if(c-ct[i]>=0){
		ret=max(ret, solve(i+1, c-ct[i])+bene[i]);
	}
	return p=ret;
}
void dfs(int u, int op)
{
	if(op==1){
		rb+=1;	
	}
	else{
		rb-=1;
	}
	rc+=cu[u];
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(vis[v]) continue;
		vis[v]=1;
		dfs(v, op*-1);
	}
	return;
}

int main()
{
	cin >> A >> B >> N >> M;
	rep(i, 0, A) cin >> cu[i];
	rep(i, 0, B) cin >> cu[i+100];
	int u, v;
	rep(i, 0, N){
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v+100), adj[v+100].pb(u);
	}
	memset(ct, 0, sizeof ct);
	memset(bene, 0, sizeof bene);
	
	rep(i, 0, A){
		ct[i]=0, bene[i]=1;
	}
	memset(vis, 0, sizeof vis);
	rep(i, 100, B+100){
		if(vis[i]) continue;
		if(adj[i].size()==0){
			ct[A+i-100]=cu[i], bene[A+i-100]=1;
		}
		else{
				
			rc=0, rb=0;
			vis[i]=1;
			dfs(i, 1);
			ct[A+i-100]=rc, bene[A+i-100]=rb;
		}
	}
	
	/*cout << endl;
	rep(i, 0, B+A){
		cout << ct[i] << " ";
	}
	cout << endl;
	rep(i, 0, B+A){
		cout << bene[i] << " ";
	}
	cout << endl;*/
	fim=A+B;
	memset(pd, -1, sizeof pd);
	int PA=solve(0, M);
	cout << PA << " ";
 	
 	memset(ct, 0, sizeof ct);
	memset(bene, 0, sizeof bene);
	
	rep(i, A, B+A){
		ct[i]=0, bene[i]=1;
	}
	memset(vis, 0, sizeof vis);
	rep(i, 0, A){
		if(vis[i]) continue;
		if(adj[i].size()==0){
			ct[i]=cu[i], bene[i]=1;
		}
		else{
			rc=0, rb=0;
			vis[i]=1;
			dfs(i, 1);
			ct[i]=rc, bene[i]=rb;
		}
	}

	/*cout << endl;
	rep(i, 0, B+A){
		cout << ct[i] << " ";
	}
	cout << endl;
	rep(i, 0, B+A){
		cout << bene[i] << " ";
	}
	cout << endl;*/
	memset(pd, -1, sizeof pd);
	//cout << "arroz" << endl;
	int PB=solve(0, M);
	cout << PB << endl;
	

return 0;
}
