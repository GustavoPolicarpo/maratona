// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Spurs Rocks
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1303

//#define gc getchar_unlocked
#include<bits/stdc++.h>

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

struct tru{
	int win, pontos, ins, fez, tomo, id;
	double ave;
};

bool comp(tru a, tru b){
	if(a.win>b.win) return true;
	if(b.win>a.win) return false;
	
	if(a.ave>b.ave) return true;
	if(b.ave>a.ave) return false;
	
	if(a.pontos>b.pontos) return true;
	if(b.pontos>a.pontos) return false;
	
	if(a.ins>b.ins) return false;
	return true;	
}
int main()
{
	int N, t=1; 
	while(scanf("%d", &N) and N){
		int x, y, z, w; tru n[N+1];
		rep(i, 1, N+1){
			n[i].win=0, 
			n[i].pontos=0, 
			n[i].ins=0, 
			n[i].fez=0,
			n[i].tomo=0,
			n[i].id=i;
			n[i].ave=0.0; 
		}
		rep(i, 0, N*(N-1)/2){
			scanf("%d %d %d %d", &x, &y, &z, &w);
			n[x].ins++, n[z].ins++;
			
			if(y>w) n[x].win++, n[x].pontos+=2;
			else n[z].win++, n[z].pontos+=1;
			
			n[x].fez+=y, n[z].fez+=w;
			n[x].tomo+=w, n[z].tomo+=y;
		}
		N++;
		rep(i, 1, N){
			if(n[i].tomo==0) n[i].ave=n[i].fez;
			else n[i].ave=double(n[i].fez)/n[i].tomo;
		}
		sort(n+1, n+N, comp);
		
		if(t>1) printf("\n");
		printf("Instancia %d\n", t++);
		rep(i, 1, N){
			if(i>1) printf(" ");
			printf("%d", n[i].id);
		}
		printf("\n");
		
	}
	



return 0;
}
