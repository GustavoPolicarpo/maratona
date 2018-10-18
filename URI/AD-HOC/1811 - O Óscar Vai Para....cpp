// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Óscar Vai Para...
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1811

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

#define INF 0x3f3f3f3f
const int mod=1e9+7;

int mat[1010][101];

struct use{
	int i, j, id;
};

bool cmp(use a, use b){
	int ta=a.j-a.i, tb=b.j-b.i;
	if(ta!=tb) return ta>tb;
	
	int da=mat[a.id][a.j]-mat[a.id][a.i],
		db=mat[b.id][b.j]-mat[b.id][b.i];
	if(da!=db) return da>db;
	
	int la=mat[a.id][a.j], lb=mat[b.id][b.j];
	if(la!=lb) return la>lb;
	
	int ia=a.id, ib=b.id;
	return ia<ib;
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	
	int n, m, z=1;
	
	while(scanf("%d", &n) and n){
		
		scanf("%d", &m);
		
		rep(i, 0, n) rep(j, 0, m) scanf("%d", &mat[i][j]);
		
		vector <use> v;
		
		rep(i, 0, n){
			use aux; 
			aux.id=i, aux.i=aux.j=0;
			vector <use> p;
			
			rep(j, 1, m){
				if(mat[i][j]<=mat[i][j-1]){
					aux.j=j-1;
					p.pb(aux);
					aux.i=j;
				}
			}
			
			if(m) aux.j=m-1;
			p.pb(aux);
			
			sort(p.begin(), p.end(), cmp);
			v.pb(p[0]);
			
		}
		
		sort(v.begin(), v.end(), cmp);
		printf("Instancia #%d\n", z++);
		printf("%d\n\n", v[0].id+1);
		
	}
	
		
	return 0;
	
}
