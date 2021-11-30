// Author: Gustavo Policarpo
// Name: Numbers of Ahmoc
// Level: 4
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2049

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

const int cc=11, MAXN=300003;
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
			return 1;
			last=i;
		}
	}
}
int main ()
{
	string in, aux; int z=1;
	//int T, Q; cin >> T;
	while(cin >> in){
		if(in=="0") break;
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
		if(z>1) printf("\n");
		printf("Instancia %d\n", z++);
		if(resp==0) printf("falsa\n");
		else{
			printf("verdadeira\n");
		//	printf("Pos: %d\n", last-in.size()+2);
		}
		//printf("\n");
	}
	
return 0;
}
