// Author: Gustavo Policarpo
// Name: SMS Championship
// Level: 8
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1458

#define gc getchar_unlocked
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
#define MAXN 100001
#define mod 1000000007
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < ii, int > iii;

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

char in[200]; 
int fim, go[705];
map<char, ii> mapa;
double dst[12][12], pd[12][12][705];

void build_mapa();
void build_dst();

double solve(int esq, int dir, int x){
	
	if(x>=fim) return 0.0;
	double &p=pd[esq][dir][x];
	if(p>-1.0) return p;
	
	double ret=INF;
	ret=min(ret, 
		min(solve(go[x], dir, x+1)+dst[esq][go[x]], 
			solve(esq, go[x], x+1)+dst[dir][go[x]]));
			
	return p=ret;	
}
int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	build_mapa();
	build_dst(); 
	while(gets(in)){
		int cnt=0, tin=strlen(in);
		rep(j, 0, mapa[in[0]].S) 
			go[cnt++]=mapa[in[0]].F;
		rep(i, 1, tin){
			if(mapa[in[i]].F==mapa[in[i-1]].F) go[cnt++]=mapa['#'].F;
			rep(j, 0, mapa[in[i]].S) 
				go[cnt++]=mapa[in[i]].F;
		}
		
		/*rep(i, 0, cnt) 
			cout << go[i];
		cout << endl;
		cout << cnt << endl;*/
		
		rep(i, 0, 10) rep(j, 0, 10) rep(k, 0, cnt) pd[i][j][k]=-10.0; fim=cnt;	 
		double ans=solve(2, 4, 0)+cnt*0.2;
		
		printf("%.2lf\n", ans);
	}
	
	return 0;
	
}

struct ponto{
	int x, y;
	ponto () {}
	ponto (int X, int Y) : x(X), y(Y) {}
}; ponto p[12];

double dPT(ponto a, ponto b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
void build_dst(){
	p[0]=ponto(1, 3); p[1]=ponto(2, 3);
	p[2]=ponto(0, 2); p[3]=ponto(1, 2); p[4]=ponto(2, 2);
	p[5]=ponto(0, 1); p[6]=ponto(1, 1); p[7]=ponto(2, 1);
	p[8]=ponto(1, 0); p[9]=ponto(2, 0);
	
	rep(i, 0, 10)
	rep(j, i, 10)
		dst[i][j]=dst[j][i]=dPT(p[i], p[j])/30.0; //cout << i << " " << j << " " << dst[i][j] << endl;
}

void build_mapa(){
	mapa['a']=mp(0, 1);
	mapa['b']=mp(0, 2);
	mapa['c']=mp(0, 3);
	mapa['d']=mp(1, 1);
	mapa['e']=mp(1, 2);
	mapa['f']=mp(1, 3);
	mapa['g']=mp(2, 1);
	mapa['h']=mp(2, 2);
	mapa['i']=mp(2, 3);
	mapa['j']=mp(3, 1);
	mapa['k']=mp(3, 2);
	mapa['l']=mp(3, 3);
	mapa['m']=mp(4, 1);
	mapa['n']=mp(4, 2);
	mapa['o']=mp(4, 3);
	mapa['p']=mp(5, 1);
	mapa['q']=mp(5, 2);
	mapa['r']=mp(5, 3);
	mapa['s']=mp(5, 4);
	mapa['t']=mp(6, 1);
	mapa['u']=mp(6, 2);
	mapa['v']=mp(6, 3);
	mapa['w']=mp(7, 1);
	mapa['x']=mp(7, 2);
	mapa['y']=mp(7, 3);
	mapa['z']=mp(7, 4);
	mapa[' ']=mp(8, 1);
	mapa['#']=mp(9, 1);
}

