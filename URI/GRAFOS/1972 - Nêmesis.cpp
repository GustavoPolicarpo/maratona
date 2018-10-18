// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Nêmesis
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1972

#include<bits/stdc++.h>
#define gc getchar_unlocked


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
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

/*
void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}
*/


int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};
char mat[501][501];
int N, M, energ[501][501], d, c;
ii atual, fim, aux;

bool cango(ii x){
	return x.F>=0 && x.S>=0 && x.F<N && x.S<M && mat[x.F][x.S]!='#';
}

int dijskatra(){
	memset(energ, INF, sizeof energ);
	priority_queue <iii> pq;
	pq.push(mp(0, atual));
	while(!pq.empty()){
		atual=pq.top().S, d=-pq.top().F; pq.pop();	
		rep(i, 0, 4){
			aux.F=atual.F+dx[i], 
			aux.S=atual.S+dy[i];
			if(!cango(aux)) continue;
			
			if(aux==fim) return d;
			
			if(mat[aux.F][aux.S]=='.'){
				if(energ[aux.F][aux.S]<=d) continue;
				energ[aux.F][aux.S]=d;
				pq.push(mp(-d, aux));
			}
			else{
				if(energ[aux.F][aux.S]<=d+mat[aux.F][aux.S]-'0') continue;
				energ[aux.F][aux.S]=d+mat[aux.F][aux.S]-'0';
				pq.push(mp(-energ[aux.F][aux.S], aux));
			}
		}
	}
	return INF;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d %d", &N, &M);
	rep(i, 0, N)
	rep(j, 0, M){
		cin >> mat[i][j];
		if(mat[i][j]=='H') atual.F=i, atual.S=j;
		else if(mat[i][j]=='E') fim.F=i, fim.S=j;
	}
	int out=dijskatra();
	if(out==INF) puts("ARTSKJID");
	else printf("%d\n", out);

return 0;
}



