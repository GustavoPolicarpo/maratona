// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Caça ao Tesouro
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2628

#include <bits/stdc++.h>
#define gc getchar
#define pc(x) putchar(x);

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

void scanint(int &x){
    register int ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, M;
bool ehprimo[100010];

void build_crivo(){
	for(int i=0; i<100010; i++) i&1 ? (ehprimo[i] = true) : (ehprimo[i] = false);
	ehprimo[1] = false, ehprimo[2] = true;
	
	for(int i=3; i<100010; i+=2){
		if(ehprimo[i])
			for(ll j=ll(i)*i; j<100010; j+=i)
				ehprimo[j] = false;
	}
}

vector <int> n;
int in[111], mat[111][111], grafo[18][18], cnt;
int pd[17][1<<17], mark[17][1<<17], mk = 1;

int solve(int u, int mask){
	if(mask == (1<<cnt)-1) return grafo[u][cnt];
	if(mark[u][mask] == mk) return pd[u][mask];
	
	mark[u][mask] = mk;
	int &ret = pd[u][mask] = 0x3f3f3f3f;
	
	rep(i, 0, cnt){
		if(mask & (1<<i) || grafo[u][i]>=0x3f3f3f3f) continue;
		ret = min(ret, solve(i, mask|(1<<i))+grafo[u][i]);
	}
	
	return ret;
}

int main(){
	
	
	build_crivo();
	
	while(scanf("%d %d", &N, &M) !=EOF){ n.clear();
		
		rep(i, 0, N){
			scanf("%d", &in[i]);
			if(ehprimo[in[i]]) n.pb(i);
		}	cnt = n.size();
		
		rep(i, 0, N+2) rep(j, 0, N+2) mat[i][j] = 0x3f3f3f3f;
		rep(i, 0, N+2) mat[i][i] = 0;
		
		int u, v, c;
		while(M--){
			scanf("%d %d %d", &u, &v, &c); u--, v--;
			mat[u][v] = min(mat[u][v], c);	
			mat[v][u] = min(mat[v][u], c);
		}
		
		rep(i, 0, cnt+2) rep(j, 0, cnt+2) grafo[i][j] = 0x3f3f3f3f;
		
		rep(k, 0, N+1)
		rep(i, 0, N+1)
		rep(j, 0, N+1)
			mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			
		rep(i, 0, cnt) rep(j, 0, cnt){
			if(i==j) continue;
			grafo[i][j] = mat[n[i]][n[j]];
		}
		rep(i, 0, cnt) grafo[cnt][i] = grafo[i][cnt] = mat[N][n[i]];
		
		rep(k, 0, cnt+1)
		rep(i, 0, cnt+1)
		rep(j, 0, cnt+1)
			grafo[i][j] = min(grafo[i][j], grafo[i][k] + grafo[k][j]);
		
		/*rep(i, 0, cnt+1){
			rep(j, 0, cnt+1)
				cout << grafo[i][j] << " ";
			cout << '\n';
		}*/
		
		mk++;
		int ans = solve(cnt, 0);
		
		printf("%d\n", ans);
		
	}	
	
	return 0;
}
