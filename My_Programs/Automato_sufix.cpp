struct state{
	int len, link;
	int next[26];
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
	rep(i, 0, 26) st[0].next[i]=0;
	//limpa o mapeamento de transições
}

void sa_extend (int c, ll &ans){
	int cur = sz++; // novo estado a ser criado
	st[cur].len = st[last].len + 1;
	rep(i, 0, 26) st[cur].next[i]=0;
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
			rep(i, 0, 26) st[clone].next[i]=st[q].next[i];
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


int maior_tamanho_em_comum( string s, string t ){
	ll nothing=0;
	// Constrói o autômato com o primeiro texto
	sa_init();
	for(int i=0; i<(int)s.size(); i++) sa_extend (s[i]-'a', nothing);
	int estado = 0, tamanho = 0, maior = 0;
	// Passando pelos caracteres do segundo texto
	for(int i=0; i<(int)t.size(); ++i){
		while( estado && ! st[estado].next[t[i]-'a'] ){
			estado = st[estado].link;
			tamanho = st[estado].len;
		}
		if(st[estado].next[t[i]-'a']){
			estado = st[estado].next[t[i]-'a'];
			tamanho++;
		}
		if(tamanho > maior){
			maior = tamanho;
		}
	}
	return maior;
}

int main()
{
	char s[MAXN];
	char p[MAXN];
	while(gets(s)){
		sa_init();
		int tam=strlen(s); ll ans=0;
		rep(i, 0, tam){
			sa_extend(s[i]-'a', ans);
		}
		gets(p);
		printf("%d\n", maior_tamanho_em_comum(s, p));
	}

	return 0;
	
}
