// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Prant e a Indecisão
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2064

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < ll, ii > iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL<<58;


int main(){
	
	int k, n, m; cin >> k >> n >> m;
	
	string fv; cin >> fv;
	
	string s; cin >> s; int aux=0, ans=0;
	
	map<char, vector <char> > tk;
	map<char, char> nv;
	map<char, vector <char> > :: iterator it;
	map<char, int> qt;
	
	rep(i, 0, s.size()) qt[s[i]]++;
	rep(i, 'a', 'z'+1) tk[i].pb(i), nv[i]=i;
	rep(i, 0, fv.size()) aux+=qt[fv[i]];
	
	char a, b; ans=aux; string resp=s;
	
	while(m--){
		cin >> a >> b; 
		
		int sv=qt[b];
		qt[b]=qt[a]; qt[a]=sv;
		
		vector <char> vs;
		rep(i, 0, tk[b].size()) vs.pb(tk[b][i]); 
		tk[b].clear();
		
		rep(i, 0, tk[a].size()){
			tk[b].pb(tk[a][i]);
			nv[tk[a][i]]=b;
		}	
		
		tk[a].clear();
		rep(i, 0, vs.size()){
			tk[a].pb(vs[i]);
			nv[vs[i]]=a;
		}
		
		
		aux=0;
		rep(i, 0, fv.size()) aux+=qt[fv[i]];
		
		if(aux>ans){
			ans=aux;
			resp.clear();
			rep(i, 0, s.size()){
				resp.pb(nv[s[i]]);
			}
		}
		
	}
	
	cout << ans << '\n' << resp << '\n';
	
	return 0;
	
}
