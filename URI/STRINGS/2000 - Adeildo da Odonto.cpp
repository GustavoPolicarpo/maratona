// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Adeildo da Odonto
// Nível: 6
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2000

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
	int next[30];
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
	rep(i, 0, 30) st[0].next[i]=0;
	//limpa o mapeamento de transições
}

void sa_extend (int c, ll &ans){
	int cur = sz++; // novo estado a ser criado
	st[cur].len = st[last].len + 1;
	rep(i, 0, 30) st[cur].next[i]=0;
	int p; // variável que itera sobre os estados terminais
	for(p=last; p!=-1 && !st[p].next[c]; p=st[p].link){
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
			rep(i, 0, 30) st[clone].next[i]=st[q].next[i];
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

long long conta_substrings(){
	long long ret=0;
	for( int i=1 ; i<sz ; i++ ){
		ret+=st[i].len-st[st[i].link].len;
	}
	return ret;
}

int main()
{
	char s[MAXN];
	int T, tam; scanf("%d", &T);
	ll a, b;
	
	while(T--){
		
		sa_init();
		scanf("%s", s);
		tam=strlen(s); a=0;
		rep(i, 0, tam)
			sa_extend(s[i]-'a', a);
		
		sa_init();
		scanf("%s", s);
		tam=strlen(s); b=0;
		rep(i, 0, tam)
			sa_extend(s[i]-'a', b);
		
		a==b ? puts("s") : puts("n");
		
	}

	return 0;
	
}
