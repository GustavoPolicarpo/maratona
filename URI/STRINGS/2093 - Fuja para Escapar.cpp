// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fuja para Escapar
// Nível: 7
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2093

#define gc getchar()
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007



using namespace std;

inline int getnum() {
    int num=0; char c;
    do { c=gc; } 
    while (c!=EOF && c==' ' && c=='\n' && c=='\t');
    
    int sign=(c=='-' ? -1 : 1);
    if (c!='-') num+=(c-'0');
    
    while ( (c=gc)!=EOF && c!='\n' && c!='\t' && c!=' ') {
        num*=10; num+=(c-'0');
    }
    num*=sign; return num;
}

inline string getstr() {
    string str; char k;
    while( (k=gc)==' ' || k=='\n' )
    {
        k=gc;
        if ( k==' ' || k=='\n' ) continue;
        else break;
    }
    str.pb(k);
    while((k=gc)!=EOF && k!='\n' && k!='\t'
        && k!='\v' && k!='\0' && k!=' ')
        str.pb(k);
    return str;
}


const int cc=2, MAXN=1000001;
int T[MAXN], term[MAXN], sig[MAXN][cc], v[MAXN];
int cnt;

void add( string s, int id ){
	int x = 0; 									
	rep( i, 0, s.size() ){		
		int c = s[i]-'0';						
		if( !sig[x][c] ){ 						
			term[cnt] = 0; 							
			sig[x][c] = cnt++; 						
		}
		x = sig[x][c]; 								
	}
	term[x] = 1; 									
	v[id] = x;											
}

void aho()
{
	queue <int> q;
	rep(i, 0, cc){
		int x=sig[0][i];
		if(!x) continue;
		T[x]=0;
		q.push(x);
	}
	while(!q.empty()){
		int u=q.front(); q.pop();
		rep(i, 0, cc){
			int v=sig[u][i];
			if(!v) continue;
			int w=T[u];
			while(w && !sig[w][i]) w=T[w];
			w=sig[w][i];
			T[v]=w;
			term[v] |= term[w];
			q.push(v);
		}
	}
}

int alc[MAXN];
void busca(string s)
{	
	int x = 0;										
	rep( i, 0, s.size()){							
		int c = s[i]-'0';							
		while( x && !sig[x][c] ) x = T[x];			
		x = sig[x][c];								
		alc[x] = 1;									
	}
} 

string in, aux;
int find()
{
	queue < pair <string, int > > q; int comp=1, c;
	q.push(mp("0", 1)); q.push(mp("1", 1));
	vector <string> words;
	while(!q.empty()){
		aux=q.front().first; c=q.front().second; q.pop();
		
		if(c!=comp){
			rep(i, 0, cnt+1){
				alc[i]=0;
				rep(j, 0, 2) sig[i][j]=0;
			}
			cnt=1;
			rep(i, 0, words.size())	add( words[i], i );				

			aho();										
			busca( in );
											
			for( int i = cnt-1; i >= 0; i-- ){			
				if( alc[i] ) alc[ T[i] ] = 1;			
			}	
													
			rep( i, 0, cnt ){
				int u = v[i];							
				if( !alc[u] ) return comp;					
			}				
			words.clear(); comp++;
		}
		words.pb(aux);
		q.push(mp(aux+"0", c+1)), q.push(mp(aux+"1", c+1));
	}	
}

int main()
{
	in=getstr();
	int out=find();
	printf("%d\n", out);	
			
return 0;
}
