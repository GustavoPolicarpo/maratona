// Author: Gustavo Policarpo
// Name: How Many Substrings?
// Level: 9
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1530

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

const int MAXN = 200020;
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
		if( st[pos].next.count(p[i])==0 ){
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
	while(scanf("%s", s) !=EOF){
		sa_init();
		int tam=strlen(s); ll ans=0;
		rep(i, 0, tam){
			if(s[i]=='?'){
				printf("%lld\n", ans);
			}else{
				sa_extend(s[i], ans);
			}
		}
	}

	return 0;
	
}
