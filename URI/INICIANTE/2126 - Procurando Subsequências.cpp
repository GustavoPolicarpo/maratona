// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Procurando Subsequências
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2126

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

const int cc=11, MAXN=1001;
int T[MAXN], term[MAXN], sig[MAXN][cc];
int cnt;

void add (string s)
{
	int x=0;
	rep(i, 0, s.size()){
		int c=s[i]-'0';
		if(!sig[x][c]){
			term[cnt]=0;
			sig[x][c]=cnt++;
		}
		x=sig[x][c];
	}
	term[x]=1;
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

int resp, last;
int busca( string s)
{
	int x=0;
	rep(i, 0, s.size()){
		int c=s[i]-'0';
		while(x && !sig[x][c]) x=T[x];
		x=sig[x][c];
		if(term[x]){
			resp++;
			last=i;
		}
	}
}
int main ()
{
	string in, aux; int z=1;
	//int T, Q; cin >> T;
	while(cin >> in){
		memset(sig, 0, sizeof sig);
		memset(term, 0, sizeof term);
		cnt=1;
		//cin >> in;
		//cin >> Q;
		//while(Q--){
			cin >> aux;
			add(in);
		//}
		aho(); resp=0, last=-1;
		busca(aux);
		printf("Caso #%d:\n", z++);
		if(resp==0) printf("Nao existe subsequencia\n");
		else{
			printf("Qtd.Subsequencias: %d\n", resp);
			printf("Pos: %d\n", last-in.size()+2);
		}
		printf("\n");
	}
	
return 0;
}
