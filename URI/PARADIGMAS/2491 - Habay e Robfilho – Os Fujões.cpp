// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Habay e Robfilho – Os Fujões
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2491

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

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
typedef pair < int, double > ii;
typedef pair < int, ii > iii;

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

iii in[101];
int pd[101][101], save[101][101], cnt;
int Q, D;

int solve(int i, int c){
	if(i==Q) return 0;
	if(pd[i][c]!=-1) return pd[i][c];
	
	int ret=solve(i+1, c);
	if(c-in[i].S.F>=0){
		int aux=solve(i+1, c-in[i].S.F)+in[i].F;
		if(aux>ret) save[i][c]=1, ret=aux;
	}
	
	return pd[i][c]=ret;
	
}

double back(int i, int c){
	if(i==Q) return 0.0;
	if( save[i][c] ){
		cnt++;
		return in[i].S.S + back(i+1, c-in[i].S.F);
	}
	return back(i+1, c);
}

int main()
{
	
	
	while(scanf("%d %d", &Q, &D)!=EOF and Q+D){
		
		double media=0.0;
		rep(i, 0, Q){
			scanf("%d %d %lf", &in[i].F, &in[i].S.F, &in[i].S.S);
			media+=in[i].S.S;
		}
		
		memset(pd, -1, sizeof pd);
		memset(save, 0, sizeof save);
		media/=Q;
		
		solve(0, D);
		cnt=0;
		double pp=back(0, D);
		
		if(cnt==0){
			printf("%.2lf NO!\n", media);
			continue;
		}
		
		pp/=cnt;
		if(pp<=media){
			printf("%.2lf NO!\n", media);
		}
		else{
			printf("%.2lf\n", pp);
		}
	}
	

	return 0;
	
}
