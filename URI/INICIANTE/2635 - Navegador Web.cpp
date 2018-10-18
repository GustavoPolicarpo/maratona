// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Navegador Web
// Nível: 5
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2635

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const ll mod = 1e9+7;

const int MAX = 10010, cc = 28;

int cnt;												
int sig[MAX][cc]; 										
int term[MAX], tam[MAX]; 
vector <int> v[MAX];

inline int C( char c ){
	return c - 'a'; 									
}

void add( string s, int id ){
	int x = 0; 											
	rep( i, 0, s.size() ){		
		int c = C( s[i] );								
		if( !sig[x][c] ){ 								
			term[cnt] = 0; 	
			v[x].clear();
			sig[x][c] = cnt++; 							
		}
		x = sig[x][c]; 									
	}
	term[x]++;
	v[x].pb(id);
	tam[id] = s.size();
}

vector <int> ans;
void dfs(int x){
	rep(i, 0, v[x].size()) ans.pb(v[x][i]);
	rep(c, 0, 26) if(sig[x][c]) dfs(sig[x][c]);
	return;
}

void query( string s ){
	int x = 0;
	rep(i, 0, s.size()){
		int c = C( s[i] );
		if(!sig[x][c]) return;
		x = sig[x][c];
	}
	dfs(x);
}

int main(){
	
	int N, Q; char s[101];
	
	while(scanf("%d", &N) !=EOF){
		
		cnt = 1;
		
		rep(i, 0, N){
			scanf("%s", s);
			add(s, i);
		}
		
		scanf("%d", &Q);
		while(Q--){
			scanf("%s", s);
			ans.clear();
			query(s);
			if(!ans.size()) puts("-1");
			else{
				int maior = 0;
				rep(i, 0, ans.size()) maior = max(maior, tam[ans[i]]) ;
				printf("%d %d\n", ans.size(), maior);
			}
		}
	}
	
	return 0;
}
