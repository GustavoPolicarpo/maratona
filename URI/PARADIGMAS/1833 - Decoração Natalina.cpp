// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Decoração Natalina
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1833

#include <bits/stdc++.h>
#define gc getchar
#define pc(x) putchar(x);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

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
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void scanint(int &x){
    register int ccc = gc(); x = 0; int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int R, N, M;
int n[101], m[101];
double pd[101][101];

double solve(int i, int j){
	if(i==N) return 0.5*(M-j)*R;
	if(j==M) return 2.5*(N-i)*R;
	double &ret=pd[i][j];
	if(ret>=0.0) return ret;
	
	ret=solve(i+1, j)+2.5*R;
	ret=min(ret, solve(i, j+1)+0.5*R);
	if(i!=N){
		if(n[i]==m[j]) ret=min(ret, solve(i+1, j+1));
		else ret=min(ret, solve(i+1, j+1)+1.0*R);
	}
	
	return ret;	
}

int main(){
	
	int T; cin >> T;
	
	rep(z, 1, T+1){
		rep(i, 0, 101) rep(j, 0, 101) pd[i][j]=-10.0;
		map<string, int> mapa; string s; int cnt=0;
		
		cin >> R >> M;
		rep(i, 0, M){
			cin >> s;
			if(!mapa.count(s)) mapa[s]=cnt++;
			m[i]=mapa[s];
		}
		cin >> N;
		rep(i, 0, N){
			cin >> s;
			if(!mapa.count(s)) mapa[s]=cnt++;
			n[i]=mapa[s];
		}
		
		double ans=solve(0, 0);
		int inteiro = ans;
		double fracionario = ans-inteiro;
		int inteiro_fracionario = fracionario*100;
		
		printf("Caso #%d: R$ %d,%.2d\n", z, inteiro, inteiro_fracionario);
	}
	
	return 0;
}

