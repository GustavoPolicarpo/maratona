// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Luciano e a Bicicletinha
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2182

#include <bits/stdc++.h>
 
using namespace std;
 
vector < pair < int, int > > adj[100010];
vector < pair < double, int > > media;
int vis[10010], ncomponentes = 0, ncaminhos = 0, maior;
 
void dfs(int u){
	vis[u] = 1;
	if(u > media[ncomponentes].second)
		media[ncomponentes].second = u;
	for(int i = 0; i < adj[u].size(); i++){
		ncaminhos++;
		int viz = adj[u][i].first;
		media[ncomponentes].first += adj[u][i].second;
		if(vis[viz] == 0){
			dfs(viz);
		}
	}
}
 
int main(){
 
	int casas, caminhos;
	cin >> casas >> caminhos;
	for(int i = 0; i < caminhos; i++){
		int a, b, buracos;
		cin >> a >> b >> buracos;
		adj[a].push_back(make_pair(b, buracos));
		adj[b].push_back(make_pair(a, buracos));
	}
	
	for(int i = 1; i <= casas; i++){
		if(vis[i] == 0){
			media.push_back(make_pair(0, 0));
			dfs(i);		
			if(ncaminhos != 0)
				media[ncomponentes].first = media[ncomponentes].first/(2.0*ncaminhos);
			else 
				media[ncomponentes].first = 0;
			ncomponentes++;
			ncaminhos = 0;
		}	
	}
	
	double menor = media[0].first;
	int maior = media[0].second;
	
	for(int i = 0; i < ncomponentes; i++){
		if(media[i].first < menor){
			menor = media[i].first;
			maior = media[i].second;
		}else if(media[i].first == menor and maior < media[i].second){
			menor = media[i].first;
			maior = media[i].second;
		}
	}
	
	cout << maior << endl;
 
	return 0;
}
