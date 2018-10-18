// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Apenas Outro Problema de ...
// Nível: 5
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1693

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
#define MAXN 100001
#define mod 1000000007
#define error 1e-14

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

int R, H, V, G;

 
double calc_tempo(double a, double b, double c){
	double delta=b*b-4.0*a*c;
		delta=sqrt(delta);
	double ret=(-b-delta)/(2.0*a);
	return ret;
}
int main()
{
	while(scanf("%d %d %d %d", &R, &H, &V, &G)!=EOF){
		double a, b, c, maximo_alcance=0.0, a1, a2, last=47.0, tempo, teta; bool yep=false;
		a=-G/2.0, c=H;
		double ini=0.0, fim=90.01, u1=(ini+fim+error)/2.0, u2=(u1+fim+error)/2.0; int cont=101;
		while(cont--){
			//cout << fim << " " << ini << endl; 
			teta=(u1*M_PI/180.0);
			b=V*sin(teta);
			tempo=calc_tempo(a, b, c);
			a1=V*cos(teta)*tempo;
			
			teta=(u2*M_PI/180.0);
			b=V*sin(teta);
			tempo=calc_tempo(a, b, c);
			a2=V*cos(teta)*tempo;
				
			if(a1<=a2){
				ini=u1, fim=fim;
				u1=(ini+fim+error)/2.0, u2=(u1+fim+error)/2.0;
				maximo_alcance=max(maximo_alcance, a2);	
			}
			else if(a1>a2){
				ini=ini, fim=u2;
				u1=(ini+fim+error)/2.0, u2=(u1+fim+error)/2.0;
				maximo_alcance=max(maximo_alcance, a1);	
			}	
		}
		//cout << maximo_alcance << endl;
		if(maximo_alcance>=R-error) puts("Y");
		else puts("N");
	}
	
	return 0;
}


