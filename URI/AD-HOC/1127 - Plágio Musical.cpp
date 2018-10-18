// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Plágio Musical
// Nível: 6
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1127

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

struct state{
	int len, link;
	map <int, int> next;
};

const int MAXN = 100010;
state st[2*MAXN]; //vetor que armazena os estados
int sz; //contador do número de estados
int last; //número do estado que corresponde ao texto todo



void sa_init(){
	sz = 1;
	last = 0;
	st[0].len = 0;
	st[0].link = -1;
	st[0].next.clear(); 
	//limpa o mapeamento de transições
}

void sa_extend (int c, ll &ans){
	int cur = sz++; // novo estado a ser criado
	st[cur].len = st[last].len + 1;
	st[cur].next.clear();
	int p; // variável que itera sobre os estados terminais
	for(p=last; p!=-1 && !st[p].next.count(c); p=st[p].link){
		st[p].next[c] = cur;
	}
	if(p == -1){// não ocorreu transição c nos estados terminais
		st[cur].link = 0;
		ans+=st[cur].len;
	}else{ // ocorreu transição c no estado p
		int q = st[p].next[c];
		if(st[p].len + 1 == st[q].len){
			st[cur].link = q;
		}else{
			int clone = sz++; // criação do vértice clone de q
			st[clone].len = st[p].len + 1;
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
			for(; p!=-1 && st[p].next[c]==q; p=st[p].link){// atualização das transições c
				st[p].next[c] = clone;
			}
			st[q].link = st[cur].link = clone;
		}
		ans+=st[cur].len-st[st[cur].link].len;
	}
	// atualização do estado que corresponde ao texto
	last = cur; 
}

bool busca_automato(int m, string p){
	int i, pos=0;
	for( i=0 ; i<m ; i++ ){
		if( st[pos].next[p[i]]==0 ){
			return false;
		}else{
			pos=st[pos].next[p[i]];
		}
	}
	return true;
}

/*int maior_tamanho_repetido( int vezes ){
	int ret=0;
	for( int i=1 ; i<sz ; i++ ){
		if( st[i].cnt>=vezes ){
			ret=max(ret,st[i].len);
		}
	}return ret;
}*/

long long conta_substrings(){
	long long ret=0;
	for( int i=1 ; i<sz ; i++ ){
		ret+=st[i].len-st[st[i].link].len;
	}
	return ret;
}


int toint(string n){
	if(n=="C" || n=="B#") return 0;
	if(n=="C#" || n=="Db") return 1;
	if(n=="D") return 2;
	if(n=="D#" || n=="Eb") return 3;
	if(n=="E" || n=="Fb") return 4;
	if(n=="F" || n=="E#") return 5;
	if(n=="F#" || n=="Gb") return 6;
	if(n=="G") return 7;
	if(n=="G#" || n=="Ab") return 8;
	if(n=="A") return 9;
	if(n=="A#" || n=="Bb") return 10;
	if(n=="B" || n=="Cb") return 11;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, M, nm;
	while(scanf("%d %d", &N, &M) and N){
		
		string text, pat;
		char aux[5];
		vector <int> n, m;
		
		rep(i, 0, N){
			scanf("%s", aux);
			nm=toint(aux);
			n.pb(nm);
		}
		
		text.pb(n[0]);
		for(int i=1; i<N; i++){
			text.pb( (n[i]-n[i-1]+12)%12 );
		}	
		
		rep(i, 0, M){
			scanf("%s", aux);
			nm=toint(aux);
			m.pb(nm);
		}
		
		//pat.pb(m[0]+'0');
		for(int i=1; i<M; i++){
			pat.pb( (m[i]-m[i-1]+12)%12 );
		}
			
		//cout << text << "\n" << pat << '\n';
		sa_init(); ll zr=0;
		rep(i, 0, text.size()){
			sa_extend(text[i], zr);
		}
		int yep=busca_automato(pat.size(), pat);
		
		if(yep) puts("S");
		else puts("N");		
	}
    
    return 0;
    
}
