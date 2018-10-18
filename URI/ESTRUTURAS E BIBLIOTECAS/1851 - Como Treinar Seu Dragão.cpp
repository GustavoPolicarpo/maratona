// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Como Treinar Seu Dragão
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1851

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define f(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(c) c.begin(), c.end() 

typedef pair<int, int> ii;
typedef pair<pair<double, int>, ii> iii;
typedef unsigned long long int ll;


int main()
{
	
    int t, f; ll ans=0;
    priority_queue <iii> pq;
    
    
    vector <iii> v; int cnt=0;
    while(scanf("%d %d", &t, &f)!=EOF){
    	v.pb(mp(mp(double(f)/t, cnt++), mp(t, f)));
	}
	
	ll tempo=0, last=1;
	pq.push(v[0]);
	
	while(1){
		
		rep(i, last, min(tempo+1, ll(v.size()))){
			pq.push(v[i]);
		}
		if(pq.empty()) break;
		
		//cout << pq.top().S.S << '\n';
		ans+=ll(tempo-pq.top().F.S)*pq.top().S.S;
		last=tempo+1;
		tempo=tempo+pq.top().S.F; pq.pop();
		
	}
	
	cout << ans << '\n';

	return 0;
	
}
