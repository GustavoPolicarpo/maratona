// Author: Gustavo Policarpo
// Name: Coleção de Upas
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3062

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED


#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair <int, int> ii;

vector <int> adj[100010];
int n, m;
int vis[100010];
vector <int> ans;

int main(){

    scanf("%d %d", &n, &m);
    
    int u, v;
    rep(i, 0, m){
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    
    for(int i=n; i>=1; i--){
        if(!vis[i]){
            ans.pb(i);
            rep(j, 0, adj[i].size()){
                vis[adj[i][j]] = 1;
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    
    printf("%d\n", ans.size());
    rep(i, 0, ans.size()){
        if(i) printf(" ");
        printf("%d", ans[i]);
    }   printf("\n");
	
	
	return 0;
}
