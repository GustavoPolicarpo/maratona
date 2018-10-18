// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ajude o Sr. Barriga
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1913

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

struct cil{
	int r, h, c; 
};
cil n[1001]; int pd[1001][1001], N;

int solve(int i, int last)
{
	if(i==N) return 0;
	if(pd[i][last]!=-1) return pd[i][last];
	
	int ret=solve(i+1, last);
	if(n[last].c==4) ret=max(ret, solve(i+1, i)+n[i].h);
	else if(n[last].c==0 && n[i].c!=3 && n[i].r<n[last].r)  ret=max(ret, solve(i+1, i)+n[i].h);
	else if(n[last].c==1 && n[i].c!=0 && n[i].r<n[last].r)  ret=max(ret, solve(i+1, i)+n[i].h);
	else if(n[last].c==2 && n[i].c!=1 && n[i].r<n[last].r)  ret=max(ret, solve(i+1, i)+n[i].h);
	else if(n[last].c==3 && n[i].c!=2 && n[i].r<n[last].r)  ret=max(ret, solve(i+1, i)+n[i].h);
	
	return pd[i][last]=ret;
}
bool comp(cil a, cil b)
{
	if(a.r>b.r) return true;
	return false;
}
int main()
{
	// vermelho 0, laranja 1, azul 2, verde 3
	char in[10];
	while(scanf("%d", &N) and N){ memset(pd, -1, sizeof pd);
		n[0].h=0, n[0].r=INF, n[0].c=4;
		N++;
		rep(i, 1, N){
			scanf("%d %d %s", &n[i].h, &n[i].r, &in);
			if(strcmp(in, "VERMELHO")==0) n[i].c=0;
			else if(strcmp(in, "LARANJA")==0) n[i].c=1;
			else if(strcmp(in, "AZUL")==0) n[i].c=2;
			else if(strcmp(in, "VERDE")==0) n[i].c=3;
		}
		sort(n, n+N, comp);
		int out=solve(1, 0);
		printf("%d centimetro(s)\n", out);	
	}
		
return 0;
}
