// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Calçada da Fama
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1777

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define F first
#define S second
#define pb push_back

typedef long long int ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const int MAX=1000010;

vector <ii> process(vector <ii> &v){
	
	vector <ii> ret;
	
	ii aux;
	
	for(int i=0; i<v.size(); i++){
		aux=v[i];
		while(i+1<v.size() && v[i+1].F <= aux.S+1){
			aux.S=max(aux.S, v[i+1].S);
			i++;
		}
		ret.pb(aux);
	}
	
	//rep(i, 0, ret.size()) cout << ret[i].F << " " << ret[i].S << '\n';
	
	return ret;
	
}

bool check(int pos, vector <ii> &v){
	
	int p=upper_bound(v.begin(), v.end(), ii(pos, INF))-v.begin(); 
	if(!p) return false; ii aux=v[p-1];
	if(pos >= aux.F && pos <= aux.S) return true;
	return false;
	
}

int main(){
	
	int T; cin >> T;
	
	rep(z, 1, T+1){
		
		int N, C; cin >> N >> C;
		vector <ii> in; ii aux;
		
		rep(i, 0, C){
			scanf("%d %d", &aux.F, &aux.S);
			in.pb(aux);
		}
		
		sort(in.begin(), in.end());
		
		vector <ii> vec = process(in);
		
		int E; cin >> E; int p, ans=0;
		
		while(E--){
			scanf("%d", &p);
			if(check(p, vec)){
				ans++;
			}
		}
		
		printf("Caso #%d: %d\n", z, ans);
		
	}
	return 0;
	
}
