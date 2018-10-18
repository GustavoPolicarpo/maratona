// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cultivando Strings
// Nível: 9
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1141

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef pair < int, int > ii;
typedef pair < ii, int > iii;

const int INF = 0x3f3f3f3f;

const int cc = 28;										
const int MAX = 1100010; 									

int cnt;												
int sig[MAX][cc]; 										
int term[MAX], best[MAX];
int T[MAX]; 											

inline int C( char c ){
	return c - 'a'; 									
}

void add( string s, int id ){
	int x = 0; 											
	rep( i, 0, s.size() ){		
		int c = C( s[i] );								
		if( !sig[x][c] ){ 								
			term[cnt] = 0; 
			sig[x][c] = cnt++; 							
		}
		x = sig[x][c]; 									
	}
	term[x]++;
}


void aho(){
	queue < int > q; int ans=0;
	rep( i, 0, cc ){									
		int x = sig[0][i];				
		if( !x ) continue;								
		q.push( x ); best[x]=term[x]; ans=max(ans, best[x]);
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
									
			//term[x] += term[v];	
			best[x]=max(best[u], best[v])+term[x];
			ans=max(ans, best[x]);
			
			q.push( x );						
		}
	}
	
	printf("%d\n", ans);
	
}



int main(){
	
	int N;
	
	while(scanf("%d", &N) and N){
		
		rep(i, 0, cnt+2){
			rep(j, 0, cc) sig[i][j]=0;
			best[i]=0;
			term[i]=0;
			T[i]=0;
		}	cnt=1;
		
		string s; vector <string> vec;
		
		rep(i, 0, N){
			cin >> s;
			vec.pb(s);
		}
		
		sort(vec.begin(), vec.end());
		
		rep(i, 0, N) add(vec[i], i+1); vec.clear();
		
		aho();
		
	}
	
	return 0;
	
}
