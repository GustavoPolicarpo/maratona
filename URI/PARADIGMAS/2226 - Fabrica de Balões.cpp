// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fabrica de Balões
// Nível: 2
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2226

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define INF 0x3f3f3f3f
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;



typedef pair <int, int> ii;
typedef long long int ll;

void scanint(ll &x)
{
    register ll ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

const int cc = 10;										
const int MAX = 5000*18+10; 									

int cnt;												
int sig[MAX][cc]; 
										
int term[MAX]; 											
int T[MAX]; 																						

inline int C( char c ){
	int ret=c-'0';
	return ret;								
}

void add( ll ss ){

	int x = 0; 
		
	char s[20]; int p=0;
	
	while(ss){
		s[p++]=(ss%10) + '0';
		ss/=10;
	}
	
	for(int i=p-1; i>=0; i--){		
		int c = C( s[i] );							
		if( !sig[x][c] ){ 								
			term[cnt] = 0; 								
			sig[x][c] = cnt++; 							
		}
		x = sig[x][c]; 									
	}
	term[x] = 1; 																					
}

void aho(){
	queue < int > q;
	rep( i, 0, cc ){									
		int x = sig[0][i];			
		if( !x ) continue;								
		q.push( x ); 									
		T[x] = 0;										
	}
	while( !q.empty() ){
		int u = q.front();							
		q.pop();
		rep( i, 0, cc ){								
			int x = sig[u][i]; 							
			if( !x ) continue;							
			int v = T[u];								
			while( v && !sig[v][i] ) v = T[v];			
			v = sig[v][i];								
			T[x] = v;									
			term[x] += term[v];							
			q.push( x );								
		}
	}
}
										
ll pd[18][2][MAX][2];											
char N[20]; int tam;
ll solve(int pos, bool p, int no, bool z){

	if(pos==tam){
		if(z) return 1;
		return 0;
	}
	if(pd[pos][p][no][z]!=-1) return pd[pos][p][no][z];
	ll ans=0;
	if(p){
		int atual=N[pos]-'0';
		rep(i, 0, atual+1){
			int v = no;										
			while( v && !sig[v][i] ) v = T[v];				
			v = sig[v][i];										
			if( term[v] && !(i==0 && z==0) ) continue;	
								
			ans = ( ans + solve( pos+1, i==atual, v , z|i) );
		}
	}
	else{
		rep(i, 0, 10){
			int v = no;										
			while( v && !sig[v][i] ) v = T[v];				
			v = sig[v][i];									
			if( term[v] && !(i==0 && z==0) ) continue;							
			ans = ( ans + solve( pos+1, 0, v , z|i) );
		}		
	}
	return pd[pos][p][no][z]=ans;
}

int main(){
	
	ll n, aux; char nn[20]; int p=0;
	memset(pd, -1, sizeof pd);
	
	while(scanf("%lld", &n) !=EOF){
		if(n==0) break; 
		
		rep(i, 0, p)
		rep(j, 0, 2)
		rep(k, 0, cnt + 1){
			rep(l, 0, 2) pd[i][j][k][l]=-1, sig[k][l]=0;
			rep(l, 2, 10) sig[k][l]=0;	
		}
			
		aux=n; nn[20]; p=0;
		while(aux){
			nn[p++]=(aux%10) + '0';
			aux/=10;
		}tam=p;
		rep(i, 0, p) N[p-i-1]=nn[i];

		cnt=1; int zz=0;
		ll M;scanint(M);
		rep(i, 0, M){
			scanint(aux);
			if(aux==0){
				zz=1;
				int x = 0; 														
				if( !sig[x][0] ){ 								
					term[cnt] = 0; 								
					sig[x][0] = cnt++; 							
				}
				x = sig[x][0]; 									
				term[x] = 1; 
				continue;																					
			}
			add( aux );
		}
		aho();
		
		ll ans=solve(0, 1, 0, 0);
		
		printf("%lld\n", n-ans+zz);
				
	}
	
	return 0;
}


