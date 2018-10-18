// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Maior Retângulo em um His...
// Nível: 8
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1683

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

int N, n[100010];
vector <ii> rect, good;
stack <ii> st;

void add(int x, int y){
	if(x>y) swap(x, y);
	if(x==0) return;
	rect.pb(ii(x, y));
}

ll max_area(){
	rect.clear();
	while(!st.empty()) st.pop();
	
	rep(i, 0, N){
		if(!st.size() || st.top().S<=n[i]) st.push(ii(i, n[i]));
	 	else{
	 		ii tp = st.top(); st.pop();
	 		add(tp.S, st.empty()?i:i-st.top().F-1);
	 		i--;
		}
	}
	while(!st.empty()){
		ii tp = st.top(); st.pop();
	 	add(tp.S, st.empty()?N:N-st.top().F-1);
	}
	
	//rep(i, 0, rect.size()) cout << rect[i].F << " " << rect[i].S << '\n'; cout << '\n';
	
	ll ret = 0;
	rep(i, 0, rect.size()){
		ret = max(ret, (ll)rect[i].F*rect[i].S);
	}
	return ret;
}

int main(){
	
	
	while(1){
		scanf("%d", &N);
		if(!N) break;
		rep(i, 0, N) scanf("%d", &n[i]);
		
		printf("%lld\n", max_area());
	}
	
	
	return 0;
}
