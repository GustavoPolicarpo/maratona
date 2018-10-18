// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Decodifique a Árvore
// Nível: 7
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1736

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

int vet[55], qt[55];
vector <int> adj[55];

void dfs(int u){

	printf("%d", u);
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		printf(" (");
		dfs(v);
	}
	printf(")");
	
}
int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	string s;
	while(getline(cin, s)){
	
		if(!s.size()){
			puts("(1)");
			continue;
		}
		
		memset(qt, 0, sizeof qt);
		memset(vet, 0, sizeof vet);
		
		int i=0, p=0, n=0; 
		while(i<s.size()){
		
			while(isdigit(s[i])){
				vet[p]*=10;
				vet[p]+=s[i]-'0';
				i++;
			}
			
			n=max(n, vet[p]);
			qt[vet[p]]++;
			p++;
			i++;
		
		}
		
		p=0;
		
		while(vet[p]){
			rep(i, 1, n+1){
				if(qt[i]==0){
					adj[vet[p]].pb(i);
					qt[i]=-1, qt[vet[p++]]--;
					break;
				}
			}
		
		}
		
		/*rep(i, 1, n+1){
			rep(j, 0, adj[i].size()) cout << adj[i][j] << " ";
			cout << '\n';
		}*/
		
		printf("(");
		dfs(n);
		printf("\n");	
		
		rep(i, 1, n+1) adj[i].clear();
	
	}
	
	return 0;
	
}
