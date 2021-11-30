// Author: Gustavo Policarpo
// Name: Balloon Factory
// Level: 10
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2226

#include <bits/stdc++.h>

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

const int cc = 10;										
const int MAX = 5000*18+1; 									

int cnt;												
int sig[MAX][cc]; 
										
int term[MAX]; 											
int T[MAX]; 																						

inline int C( char c ){
	int ret=c-'0';
	return ret;								
}

void add( string s){
	int x = 0; 											
	rep( i, 0, s.size() ){		
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
string N, c; int tam;
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
	
	ll n;
	while(cin >> n){
		if(n==0) break; 
		ll aux=n; N="";
		while(aux){
			N+=(aux%10) + '0';
			aux/=10;
		}tam=N.size();
		reverse(N.begin(), N.end());
		memset(sig, 0, sizeof sig);
		memset(pd, -1, sizeof pd);
		cnt=1; int zz=0;
		int M; cin >> M;
		rep(i, 0, M){
			cin >> c;
			if(c=="0") zz=1;
			add(c);
		}
		aho();
		ll ans=solve(0, 1, 0, 0);
		printf("%lld\n", n-ans+zz);
	}
	
	return 0;
}


