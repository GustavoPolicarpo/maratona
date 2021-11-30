// Author: Gustavo Policarpo
// Name: Escaping from Escaping
// Level: 10
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2093

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F
#define limite 10000005


typedef pair < int, int > ii;
typedef long long int ll;

const int cc=2, MAXN=1000001;
int T[MAXN], term[MAXN], sig[MAXN][cc], v[MAXN], alc[MAXN];
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

void busca( string s ){	
	int x = 0;											// Inicialmente se posiciona na raiz da Trie
	rep( i, 0, s.size() ){								// Percorre toda a string
		int c = s[i]-'0';								// Valor da posição atual da string
		while( x && !sig[x][c] ) x = T[x];				// Procura o maior prefixo-sufixo do no atual que possui caminho para c  
		x = sig[x][c];									// Se move para o nó encontrado
		alc[x] = 1;										// Marca que o nó encontrado pode ser alcançado durante o texto
	}
}
int out; string in, aux;

int find()
{
	queue < pair <string, int > > q; int comp=1;
	q.push(mp("0", 1)); q.push(mp("1", 1));
	vector <string> words;
	while(!q.empty()){
		aux=q.front().first; int c=q.front().second; q.pop();
		
		if(c!=comp){
			//cout << q.size() << endl;
			rep(i, 0, cnt+1){
				term[i]=0, v[i]=0, alc[i]=0;
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
	//	cout << aux;
		q.push(mp(aux+"0", c+1)), q.push(mp(aux+"1", c+1));
	}	
}
int main ()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//int T; cin >> T;
//	while(T--){
		cin >> in;
		out=find();
		printf("%d\n", out);	
//	}
			
return 0;
}
