// Author: Gustavo Policarpo
// Name: Euro Cup 2000
// Level: 6
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1727

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

#define INF 0x3f3f3f3f

int N;
string team[22];
int mat[22][22][2];
ii ans[22];
map <string, int> mapa;
set <ii> st;
vector <iii> g;

struct game{
	int fez, levou, sc, id;
};
bool cmp(game a, game b){
	if(a.sc!=b.sc) return a.sc>b.sc;
	if(a.fez-a.levou!=b.fez-b.levou) return a.fez-a.levou>b.fez-b.levou;
	return a.fez>b.fez;
}

void solve(int t){
	
	if(t==g.size()){
		vector <game> v; game aux;
		rep(i, 0, N){
			aux.fez=0, aux.levou=0, aux.sc=0, aux.id=i;
			rep(j, 0, N){
				if(i==j) continue;
				rep(k, 0, 2){
					if(mat[i][j][k]>mat[j][i][k]) aux.sc+=3;
					else if(mat[i][j][k]==mat[j][i][k]) aux.sc+=1;
					aux.fez+=mat[i][j][k];
					aux.levou+=mat[j][i][k];
				}
			}
			v.pb(aux);
		}
		
		sort(v.begin(), v.end(), cmp);
		rep(i, 0, v.size()){
			ans[v[i].id].F=min(ans[v[i].id].F, i+1);
			ans[v[i].id].S=max(ans[v[i].id].S, i+1);
		}
		
		return;
	}
	
	int i=g[t].F.F, j=g[t].F.S, k=g[t].S;
	mat[i][j][k]=0; solve(t+1);
	mat[i][j][k]=1000; solve(t+1);
	mat[i][j][k]=-1;
	
}

int main(){

	int z=1;
	while(cin >> N and N){
		
		memset(mat, -1, sizeof mat);
		mapa.clear(); st.clear(); g.clear();
		
		rep(i, 0, N) cin >> team[i], mapa[team[i]]=i, ans[i].F=1000, ans[i].S=0;
		
		int T, cnt=0; cin >> T; string a, b; int ga, gb;
		rep(i, 0, T){
			cin >> a >> b >> ga >> gb;
			if(st.count(ii(mapa[a], mapa[b]))){
				mat[mapa[a]][mapa[b]][1]=ga;
				mat[mapa[b]][mapa[a]][1]=gb;
			}else{
				mat[mapa[a]][mapa[b]][0]=ga;
				mat[mapa[b]][mapa[a]][0]=gb;
				st.insert(ii(mapa[a], mapa[b]));
				st.insert(ii(mapa[b], mapa[a]));
			}
		}
		
		rep(k, 0, 2)
		rep(i, 0, N)
		rep(j, 0, N){
			if(i==j) continue;
			if(mat[i][j][k]==-1){
				g.pb(iii((ii(i, j)), k));
			}
		}
		
		solve(0);
		
		printf("Group #%d\n", z++);
		rep(i, 0, N){
			printf("%s %d-%d\n", team[i].c_str(), ans[i].F, ans[i].S);
		}	printf("\n");
	}
	
	
	return 0;
	
}
