// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Estacionamento Linear
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1523

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
typedef pair < ii, int > iii;


int main()
{

	int N, K;
	
	while(scanf("%d %d", &N, &K) and N+K){
		
		int yep=1, e, s;
		stack <int> q;
		
		while(N--){
			
			scanf("%d %d", &e, &s);
			
			if(q.empty()){
				q.push(s);
				continue;
			}
			
			while(!q.empty() && q.top()<=e) q.pop();
			
			if(!q.empty() && q.top()<s){
				yep=0;
				break;
			}
			
			q.push(s);
			if(q.size()>K){
				yep=0;
				break;
			}
			
			
		}
		
		while(N>0) scanf("%d %d", &e, &s), N--;
		
		yep?puts("Sim"):puts("Nao");
		
	}
	
	return 0;
	
}
